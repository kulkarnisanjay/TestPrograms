#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
struct tree {
	int data;
	struct tree *left;
	struct tree *right;
};

int queue[5][10];
int width[10];

void printdiagonal(struct tree *node, int q) {
	int i;
	if (node == NULL) {
		return;
	}
	for(i=0;queue[q][i]!=0;i++);
	queue[q][i] = node->data;
	printf("diag number %d and %d\n",q,node->data);
	printdiagonal(node->right,q);
	q++;
	printdiagonal(node->left,q);
}

int height(struct tree *node) {
	if (node == NULL) {
		return 0;
	}
	int lheight = height(node->left);
	int rheight = height(node->right);
	if (lheight > rheight) {
		return lheight+1;
	} else {
		return rheight+1;
	}
}

void bfs(struct tree *node, int level, int st_level) {
	if(node == NULL)
		return;
	if(level == 0){
		printf("%d ",node->data);
		width[st_level] = width[st_level]+1;
	}
	bfs(node->left, level-1, st_level);
	bfs(node->right, level-1, st_level);
}

void dobfs(struct tree *node, int height) {
	int i;
	for(i=0;i<height-1;i++) {
		bfs(node,i,i);
	}
}

void insert(struct tree **root, int number) {
	if (*root == NULL) {
		*root = (struct tree*)malloc(sizeof(struct tree));
		(*root)->data = number;
		(*root)->left = NULL;
		(*root)->right = NULL;
		return;
	}
	struct tree *temp2, *temp = *root;
	while(temp){
		temp2 = temp;
		if(temp->data <= number)
			temp=temp->right;
		else
			temp=temp->left;
	}
	temp = (struct tree*)malloc(sizeof(struct tree));
	temp->data = number;
	temp->right = NULL;
	temp->left = NULL;
	if(temp2->data <= number) {
		temp2->right = temp;
	} else {
		temp2->left = temp;
	}
}
int max;
int longestpath(struct tree *root) {
	int rheight=0,lheight=0;
	if (root == NULL) {
		return 0;
	}
	lheight = longestpath(root->left);
	rheight = longestpath(root->right);
	if(rheight+lheight > max)
		max  = rheight+lheight;
	if(rheight>lheight)
		return rheight+1;
	else
		return lheight+1;
}

int main() {
	struct tree *root = NULL;
	insert(&root,5);
	insert(&root,1);
	insert(&root,10);
	insert(&root,2);
	insert(&root,6);
	insert(&root,8);
	insert(&root,7);
	insert(&root,9);
	insert(&root,3);
	printdiagonal(root,0);
	for(int i=0;i<5;i++){
		for(int j=0;j<10;j++){
			printf("%d ",queue[i][j]);
		}
		printf("\n");
	}
	printf("%d",height(root));
	dobfs(root,height(root));
	printf("\n");
	for(int i=0;i<10;i++) {
		printf("%d ",width[i]);
	}
	longestpath(root);
	printf("longest path: %d\n",max);
	return 0;
}
