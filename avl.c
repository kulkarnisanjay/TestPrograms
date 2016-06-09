#include<stdio.h>
struct avl{
	int number;
	struct avl *left;
	struct avl *right;
};



void insert_avlnode(struct avl **avlnode, int data) {
	struct avl *newnode = *avlnode;

	if (*avlnode == NULL) {
		*avlnode = newnode(data);
		return;
	}
	while(newnode) {
		if(data > newnode->data) {
			newnode = newnode->right;
		}


int main() {
	struct avl *rootnode;
	int data[10];
	for (int i=0;i<10;i++) {
		scanf("%d",&data[i]);
		insert_avlnode(data[i], &avlnode);
	}
	print_tree(avlnode);
	return 0;
}
	


