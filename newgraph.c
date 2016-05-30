#include<stdio.h>
typedef struct Edge {
	int weight;
	int edgetonode;
	struct Edge *nextedge;
}edge;

typedef struct Vertex {
	int indegree;
	int outdegree;
	int visited;
	edge *e;
}vertex;

typedef struct Graph{
	int vno;
	int direct;
	vertex *v;
}graph;
	
struct node{
	int number;
	int visited;
	struct node *connect;
};

void bfs(struct node **root, int v) {
	struct node **temp = (struct node **)malloc(sizeof(struct node *)*v);
	while(*root);
}

void dfs(struct node *v, struct node **root){
  struct node *temp = v;
  if(root[temp->number]->visited == 0) {
	root[temp->number]->visited = 1;
	printf("%d-",temp->number);
  }
  else
	return;
  while (temp!=NULL) {
	temp = temp->connect;
	if (temp)
		dfs(root[temp->number], root);
  }
}

int main()
{
   int vertices;
   struct node **v;
   printf("Printf Enter number of vertices\n");
   scanf("%d",&vertices);  
   v = (struct node**)malloc(sizeof(struct node*)*vertices);
   for (int i=0; i<vertices; i++) {
	v[i] = (struct node*)malloc(sizeof(struct node));
	v[i]->number = i;
	v[i]->visited = 0;
	v[i]->connect = NULL;
  }
  for (int i=0; i<vertices; i++) {
	struct node *temp = v[i];
	int connector;
	while (temp->connect!=NULL)
		temp = temp->connect;
	printf("Enter the number of connectors for node %d\n",i);
	scanf("%d",&connector);
	for (int j=0; j<connector; j++) {
		struct node *newnode = (struct node*)malloc(sizeof(struct node));
		printf("Enter the new connector to node %d\n",i);
		scanf("%d",&(newnode->number));
		newnode->connect = NULL;
		temp->connect = newnode;
		temp = newnode;
	}
   }
   for (int i=0; i<vertices; i++) {
	struct node *temp = v[i];
	printf("\n");
	while (temp!=NULL){
		printf("%d - ",temp->number);
		temp = temp->connect;
	}
   }
  printf("DFS: \n");
//  for (int i=0; i<vertices; i++) {
  	dfs(v[0],v);
 // }
  return 0;
}
