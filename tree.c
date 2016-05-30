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

void farthestnode(struct tree *node, int height) {
	if(node == NULL)
		return;
	if(height == 0)
		printf("farthest node%d\n",node->data);
	farthestnode(node->left, height-1);
	farthestnode(node->right, height-1);
}

void inorder(struct tree *node)
{
	struct tree **stack = (struct tree **)malloc(sizeof(struct tree*)*15);
	struct tree *temp;
	int i=0;
	while (node!=NULL) {
		while(node!=NULL) {
			//printf("pushing %d\n",node->data);
			stack[i++] = node;
			node = node->left;
		}
		while (i>=0) {
			temp = stack[--i];
			if (temp)
				printf("Inorder %d %d %x\n",temp->data, i, temp->right);
			else
				break;
			if (temp->right) {
				node = temp->right;
				break;
			}
		}
	}
}

void best_inorder(struct tree *node) {
	struct tree *temp;
	while(node!=NULL) {
		if(node->left==NULL) {
			printf("%d\n",node->data);
			node = node->right;
		}else {
			temp = node->left;
			while(temp->right!=NULL && temp->right!=node) {
				temp = temp->right;
			}
			if(temp->right == NULL ) {
				temp->right = node;
				node = node->left;
			} else {
				temp->right = NULL;
				printf("%d\n",node->data);
				node = node->right;
			}
		}
	}
}	

int inorder1[6] = {4,2,5,1,6,3};
int preorder[6] = {1,2,4,5,3,6};

int binsearch(int number) {
	for(int i=0;i<6;i++) {
		if(inorder1[i] == number) {
			return i;
		}
	}
}



void construct(int st, int end, struct tree **node) {
	static int i;
	if (st > end)
		return;
	int number  = preorder[i++];
	if (*node == NULL) {
	*node = (struct tree*)malloc(sizeof(struct tree));
	(*node)->data = number;
	(*node)->left = NULL;
	(*node)->right = NULL; 
	}
	int indx = binsearch(number);
	construct(st, indx-1, &(*node)->left);
	construct(indx+1, end, &(*node)->right);
}

int findanode(struct tree *node, int number) {
	if(node == NULL)
		return 0;
	printf("%d\n",node->data);
	if(node->data == number){
		printf("%d\n",node->data);
		return 1;
	}
	if(findanode(node->left,number)) {
		printf("l: %d\n",node->data);
		return 1;
	} else if (findanode(node->right,number)) {
		printf("r: %d\n",node->data);
		return 1;
	}else {
		return 0;
	}
}

int returnanode(struct tree *node, int number, struct tree **found) {
        if(node == NULL)
                return 0;
        if(node->data == number){
                printf("%d\n",node->data);
		*found  = node;
                return 1;
        }
	if (returnanode(node->left,number,found) || returnanode(node->right,number,found)) {
		return 1;
	}
	return 0;
}

int inordertree(struct tree *maintree, struct tree *subtree) {
	if(maintree== NULL && subtree != NULL)
		return 0;
	if (maintree!=NULL && subtree == NULL)
		return  1;
	if (maintree == NULL && subtree == NULL)
		return 1;
	if (maintree->data == subtree->data){
		if (inordertree(maintree->left, subtree->left) && inordertree(maintree->right, subtree->right)) {
			return 1;
		} else {
			return 0;
		}
	} 
	return 0;
}

	
int checksubtree(struct tree *maintree, struct tree *subtree) {
	struct tree *found;
	int re=0;
	if(maintree == NULL || subtree == NULL) {
		return 1;
	}
	if(returnanode(maintree, subtree->data, &found)) {
		re = inordertree(found, subtree);
	}
	return re;
}

void leafpath(struct tree *node, int arr[]) {
	static int i=0;
	if(node == NULL) {
		return;
	}
	arr[i++] = node->data;
	if (node->left == NULL && node->right == NULL) {
		for(int j=0;j<i;j++) {
			printf("%d ",arr[j]);
		}
		printf("\n");
	}
	leafpath(node->left, arr);
	leafpath(node->right,arr);
	i--;
}

struct tree* tree2list(struct tree *node) {
	struct tree *prev;
	struct tree *next;
	struct tree *temp = node;
	if(node == NULL)
		return NULL;
	prev = tree2list(node->left);
	next = tree2list(node->right);
	while(prev!=NULL && prev->right!=NULL) {
		prev = prev->right;
	}
	while (next!=NULL && next->left!=NULL) {
		next = next->left;
	}
	node->left = prev;
	node->right = next;
	if (prev!=NULL) {
		prev->right = node;
	}
	if (next!=NULL) {
		next->left = node;
	}
	while(temp!=NULL) {
		printf("%d-",temp->data);
		temp = temp->left;
	}
	printf("\n");
	temp = node;
	while(temp!=NULL) {
		printf("%d-",temp->data);
		temp = temp->right;
	}
	printf("\n");
	return node;
}

int sumtree2(struct tree *node) {
	int sumleft= 0, sumright = 0;
	int left = 0, right = 0, leaf = 0;
	if (node == NULL)
		return 1;
	if (node->left == NULL && node->right == NULL) {
		leaf = 1;
	}
	sumleft = sumtree2(node->left);
	sumright = sumtree2(node->right);
	if (node->left)
		left = node->left->data;
	if (node->right)
		right = node->right->data;
	return (sumleft && sumright && ((node->data == left + right) || leaf ));
}

void sumtree3(struct tree *node) {
	int sumleft= 0, sumright = 0;
	int left = 0, right = 0, leaf = 0;
	if (node == NULL)
		return;
	if (node->left == NULL && node->right == NULL) {
		leaf = 1;
	}
	sumtree3(node->left);
	sumtree3(node->right);
	if(!leaf) {
		if(node->left) {
			left = node->left->data;
		}
		if (node->right) {
			right = node->right->data;
		}
		node->data = left+right;
		printf("non leaf %d %d %d\n",node->data, left, right);
	}
	if(leaf)
		printf("%d\n",node->data);
}

int heightbalance(struct tree *node) {
	int lheight=0, rheight=0;
	if(node == NULL)
		return 0;
	lheight = heightbalance(node->left);
	rheight = heightbalance(node->right);
	if(lheight < 0 || rheight <0 || abs(lheight-rheight) > 1) {
		return -1;
	} else {
		if (rheight >= lheight) {
			return 1+rheight;
		} else {
			return 1+lheight;
		}
	}
}

void root2leaf(struct tree *node, int arr[], int i, int target) {
	int sum=0;
	if(node == NULL) {
		return;
	}
	arr[i] = node->data;
	if(node->left == NULL && node->right == NULL) {
		for(int j=0;j<i+1;j++)
			sum+=arr[j];
		if (sum == target) {
			printf("target achieved\n");
			for (int k=0;k<i;k++) 
				printf(" %d -",arr[k]);
			printf("\n");
		}
		return;
	}
	root2leaf(node->left, arr, i+1, target);
	root2leaf(node->right,arr, i+1, target);;
	arr[i] = 0;
	return;
}

struct tree* newnode(int number) {
	struct tree *node = (struct tree*)malloc(sizeof(struct tree));
	node->data = number;
	node->left = NULL;
	node->right = NULL;
	return node;
}




int main() {
	struct tree *root = NULL;
//	construct(0,5,&root);	
	//	tree 1:
/*
	insert(&root,5);
	insert(&root,1);
	insert(&root,10);
	insert(&root,2);
	insert(&root,6);
	insert(&root,8);
	insert(&root,7);
	insert(&root,9);
	insert(&root,3);
*/
	// tree 2:
/*
	insert(&root,11);
	insert(&root,12);
	insert(&root,13);
	insert(&root,14);
	insert(&root,15);
*/
/*
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
	farthestnode(root,4);
*/
//	inorder(root);
//	best_inorder(root);
//	findanode(root,7);

/*	struct tree *subtree = NULL;
	insert(&subtree, 6);
	insert(&subtree, 8);
	insert(&subtree, 7);
	insert(&subtree, 9);

	printf("subtree: %d\n",checksubtree(root,subtree));
*/
/*	int arr[20];
	leafpath(root,arr);
*/
//	tree2list(root);

	root = newnode(10);
	root->left = newnode(2);
	root->right = newnode(8);
	root->left->left = newnode(2);
	root->left->left->left = newnode(1);
	root->right->left = newnode(6);
	root->right->left->left = newnode(1);
	root->right->right = newnode(3);
	//sumtree3(root);
	//printf("%d\n",heightbalance(root));
	int arr[10];
	root2leaf(root,arr,0,12);
	return 0;
}
