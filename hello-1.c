/*  
 *  hello-1.c - The simplest kernel module.
 */
#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
#include <linux/sched.h>
int init_module(void)
{
	struct mm_struct	*mm;
	mm = current->mm;
	printk(KERN_INFO "Hello world 1 %ld \n", current->mm->mmap_sem.count);
	down_read(&mm->mmap_sem);
	printk(KERN_INFO "Hello world reader %ld \n", current->mm->mmap_sem.count);
	up_read(&mm->mmap_sem);
	printk(KERN_INFO "Hello world bye reader %ld \n", current->mm->mmap_sem.count);
	down_write(&mm->mmap_sem);
	printk(KERN_INFO "Hello world writer 4 %ld \n", current->mm->mmap_sem.count);
	up_write(&mm->mmap_sem);
	printk(KERN_INFO "Hello world bye writer %ld \n", current->mm->mmap_sem.count);
	/* 
	 * A non 0 return means init_module failed; module can't be loaded. 
	 */
	return 0;
}

void cleanup_module(void)
{
	printk(KERN_INFO "Goodbye world 1.\n");
}

