#include<stdio.h>
#include<stdlib.h>
struct linked_list {
	int data;
	struct linked_list *next;
};
typedef struct linked_list *ll;
void insert(int data, ll *root) {
	ll node, start = *root;
	node = malloc(sizeof(struct linked_list));
	node->data = data;
	node->next = NULL;
	if (*root == NULL) {
		*root = node;
		return;
	}
	while (start->next!=NULL)
		start = start->next;
	start->next = node;
	return;
}
void removeduplicates(ll node)
{
	ll hour,minute, prev;
	for (hour = node; hour->next!=NULL;hour=hour->next) {
		for(minute = hour->next; minute->next!=NULL; minute=minute->next) {
			if(hour->data == minute->data){
				minute->data = minute->next->data;
				prev = minute->next;
				minute->next = minute->next->next;
				free(prev);
			}
		}
	}
}

ll ispal(ll last, ll first) {
	static int n;
	if (!last)
		return first;
	else {
		n++;
		first=ispal(last->next,first);
		if (!first) { 
			return NULL;
		}
		if (last->data == first->data) {
			n--;
			if (n==0) {
				return 0x1;
			}
			return first->next;
		}else {
			return NULL;
		}
	}
}

void deletefromnode( ll node, int number)
{
  int i=0;
  while (node!=NULL && i!=number) {
	node = node->next;
	i++;
 }
  if(!node) {
	return;
  } else{
	if(node->next) {
		node->data = node->next->data;
		ll temp = node->next;
		node->next = node->next->next;
		free(temp);
	} else {
		free(node);
	}
}}

void printfromn(ll node, int pos){
	ll strt, end;
	strt = end = node;
	int i;
	for (i=0; i< pos; i++) {
		if(end->next) {
			end = end->next;
		}else {
			return ;
		}
	}
	while(end==NULL) {
		end = end->next;
		strt = strt->next;
	}
	while(strt->next!=NULL) {
		printf("%d->",strt->data);
		strt = strt->next;
	}
}

void reverse(ll *node) {
	ll first,second,third;
	if (*node) {
		first = *node;
		second = (*node)->next;
		if(second) {
			third = second->next;
		}
		(*node)->next = NULL;
	}
	while (second!=NULL) {
		second->next = first;
		first = second;
		second = third;
		if (third)
			third = third->next;
	}
	*node = first;
}

int main() {
	ll node = NULL;
	int data;
	do {
		printf("Enter the data\n");
		scanf("%d",&data);
		if (data == 999)
			break;
		insert(data, &node);
	}while(data!=999);
	//removeduplicates(node);
	//deletefromnode(node, 4);
	ll last, first;
//	last = first = node;
//	if(!ispal(last,first))
//		printf("not a palindrome\n");
//	else
//		printf("palindrome\n");
	reverse(&node);
	while (node!=NULL) {
		printf("%d->",node->data);
		node = node->next;
	}
	return 0;
}
	
	
