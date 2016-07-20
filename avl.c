#include<stdio.h>
#include<stdlib.h>
struct avl{
	int data;
	struct avl *left;
	struct avl *right;
};
/*
void rebalance(struct avl *node, int bf, int data) {
	struct avl *temp = node;
	if (bf > 0) {
		if (data > temp->right->data) {
			inorout = 1; // outside
		} else {
			inorout = 2; // inside
		}
	} else {
		if (data < temp->left->data) {
			inourout = 3; //outside
		} else {
			inorout = 4;
		}
	}
	switch(inorout) {
		case 1: rotateleft();
			break;
		case 2: rotateright();
			rotateleft();
			break;
		case 3: rotateright();
			rotate
}
*/
int height(struct avl *node) {
	int lheight = 0, rheight = 0;
	if (node == NULL) {
		return 0;
	}
	lheight = height(node->left);
	rheight = height(node->right);
	return lheight+rheight+1;
}
/*
void check_balance(struct avl *node, int data) {
	height(node, data);
}
*/
void rotateright(struct avl **node) {
	struct avl *temp;
	temp = (*node)->right;
	(*node)->right = temp->left;
	temp->left = (*node);
	(*node) = temp;
}

void rotateleft(struct avl **node) {
	struct avl *temp;
	temp = (*node)->left;
	(*node)->left = temp->right;
	temp->right = (*node);
	(*node) = temp;
}

void doublerotateright(struct avl **node) {
	rotateleft(&(*node)->right);
	rotateright(node);
}

void doublerotateleft(struct avl **node) {
	rotateleft(&(*node)->left);
	rotateright(node);
}

struct avl *allocnode(int data) {
	struct avl *newnode = (struct avl*)malloc(sizeof(struct avl));
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

void insert_avlnode(int data, struct avl **avlnode) {
	struct avl *newnode = *avlnode;
	struct avl *temp = newnode, *parent = newnode;

	if (*avlnode == NULL) {
		*avlnode = allocnode(data);
		return;
	}
	while(newnode) {
		parent = temp;
		temp = newnode;
		if(data >= newnode->data) {
			newnode = newnode->right;
		} else {
			newnode = newnode->left;
		}
	}
	if(data >= temp->data) {
		temp->right = allocnode(data);
		if (height(parent->left) - height(parent->right) == 2) {
			if(temp->data > data) {
				rotateright(&parent);
			} else {
				doublerotateright(&parent);
			}
		}
	} else {
		temp->left = allocnode(data);
		if (height(parent->right) - height(parent->left) == 2) {
			if(temp->data < data) {
				rotateleft(&parent);
			} else {
				doublerotateleft(&parent);
			}
		}
	}
}

void print_tree(struct avl *node) {
	if (node == NULL) {
		return;
	}
	printf("%d\n",node->data);
	print_tree(node->left);
	print_tree(node->right);
}

int main() {
	struct avl *avlnode = NULL;
	int data[3]={1,2,3}, sample;
	scanf("%d",&sample);
	for (int i=0;i<sample;i++) {
		//scanf("%d",&data);
		insert_avlnode(data[i], &avlnode);
	}
	print_tree(avlnode);
	return 0;
}
	


