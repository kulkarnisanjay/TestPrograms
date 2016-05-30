#include<stdio.h>
#include<stdlib.h>
typedef struct Edge {
	int weight;
	void *edgetonode;
	struct Edge *nextedge;
}edge;

typedef struct Vertex {
	int number;
	int indegree;
	int outdegree;
	int visited;
	edge *e;
}vertex;

typedef struct Graph {
	int vno;
	int direct;
	vertex *v;
}graph;

void insertedge(graph *g, int source, int dest, int direct, int weight) {
	edge *newedge = (edge *)malloc(sizeof(edge));
	newedge->weight = weight;
	newedge->edgetonode = &(g->v[dest]);
	newedge->nextedge = g->v[source].e;
	((vertex*)newedge->edgetonode)->indegree++; //set the indegree of the dest edge
	g->v[source].outdegree++;
	g->v[source].e = newedge;
	if(!direct) {
		g->direct = direct;
		insertedge(g, dest, source, 1, weight);
	}
}

void printgraph(graph *g) {
	for(int i=0;i<g->vno;i++) {
		if(g->v[i].e) {
			edge *e1 = g->v[i].e;
			printf("%d(%d): ",i, g->v[i].indegree);
			while(e1) {
				//vertex *v = (e1->edgetonode
				printf("%d ",((vertex *)e1->edgetonode)->number);
				e1 = e1->nextedge;
			}
			printf("\n");
		}
	}
}

void insertvertex(graph *g, int vno) {
	vertex *vtemp;
	vtemp = (vertex *)realloc(g->v, sizeof(vertex)*(g->vno+vno));
	g->v = vtemp;
	g->vno+=vno;
}

int stack[20];
/*
void initstack() {
	for(int i=0;i<20;i++) {
		stack[i] = 999;
	}
}

int instack(int number) {
	for(int i=0;i<20;i++) {
		if(stack[i] == number) {	
			return 1;
		}
	}
	return 0;
}
*/
void dfs(graph *g, int start, int parent) {
//	printf("%d ",start);
	g->v[start].visited = 1;
	stack[start] = 1;
	edge *e1;
	for(e1 = g->v[start].e; e1; e1 = e1->nextedge) {
		if(!((vertex*)e1->edgetonode)->visited) {
			printf("processing %d %d\n",start,((vertex *)e1->edgetonode)->number);
			dfs(g, ((vertex *)e1->edgetonode)->number, start);
		}
		if(/*((vertex*)e1->edgetonode)->visited && */
			((vertex*)e1->edgetonode)->number != parent && stack[((vertex*)e1->edgetonode)->number]) {
			printf("Found a cycle %d %d %d\n",parent,start,((vertex*)e1->edgetonode)->number);
			for(int i=0;i<20;i++) {
				if (stack[i])
					printf("%d ",i);
			}
			printf("\n");
		}
	}
	stack[start] = 0;
}
	

void dfs1(graph *g, int start) {
	for(int i=start;i<g->vno;i++) {
		if(!g->v[i].visited)
			dfs(g, i, -1);
	}
	for(int i=0;i<start;i++) {
		if(!g->v[i].visited)
			dfs(g, i, -1);
	}
}


void bfs(graph *g, int start) {
	int *q = (int *)malloc(sizeof(int)*g->vno);
	int discovered[20];
	int head=0, tail=0;
	q[head] = start;
	tail = head;
	discovered[q[head]] = 1;
	while(head<=tail) {
		g->v[q[head]].visited = 1;
		printf("%d ",q[head]);
		edge *e1 = g->v[q[head]].e;
		while(e1) {
			//printf("processing edge %d(%d) %d\n",q[head], g->v[head].number, e1->edgetonode);
			if (((vertex *)e1->edgetonode)->visited == 1 || discovered[((vertex*)e1->edgetonode)->number] == 1) {
				e1 = e1->nextedge;
				continue;
			}
			discovered[((vertex*)e1->edgetonode)->number] = 1;
			q[++tail] = ((vertex*)e1->edgetonode)->number;
			e1 = e1->nextedge;
		}
		head++;
	}
}

void removedges(edge **e) {
	if (*e == NULL) {
		return;
	} else {
		removedges(&((*e)->nextedge));
		((vertex*)(*e)->edgetonode)->indegree--;
		free(*e);
		*e = NULL;
	}
}

void topo_sort(graph *g) {
	int vno = g->vno;
	while (vno) {
		for (int i=0; i< g->vno; i++) {
			if (g->v[i].indegree == 0 && !g->v[i].visited) {
				removedges(&(g->v[i].e));
				g->v[i].visited = 1;
				printf("%d",i);
				vno--;
			}
		}
	}

}

struct dijkstra{
	int weight; 
	int vianode;
};

int findsource(graph *g, struct dijkstra *djk) {
	int min = 999;
	int source = 999;
	for(int i=0; i<g->vno; i++) {
		if(!g->v[i].visited && (min > djk[i].weight)) {
			source = i;
		}
	}
	return source;
}

void shortpath(graph *g, int source) {
	edge *e;
	struct dijkstra *djk;
	int processed_nodes = g->vno;
	djk  = (struct dijkstra *)malloc(sizeof(struct dijkstra)*(g->vno));
	for (int i=0; i<g->vno; i++) {
		djk[i].weight = 999;
		djk[i].vianode = 999;
	}
	djk[source].weight = 0;
	djk[source].vianode = source;
	while (processed_nodes) {
		for(e=g->v[source].e; e && !(g->v[source].visited); e=e->nextedge) {
			int node = ((vertex *)e->edgetonode)->number;
			if (djk[source].weight + e->weight < djk[node].weight) {
				djk[node].weight = djk[source].weight + e->weight;
				djk[node].vianode = source;
			}
		}
		processed_nodes--;
		g->v[source].visited = 1;
		source = findsource(g, djk);
	}
	for (int i=0;i<g->vno;i++) {	
		printf("Source 0 dest %d %d weight %d\n",i, djk[i].vianode, djk[i].weight );
	}
}

struct bellford {
	int weight;
	int fromnode;
};

void shortpath_bf(graph *g, int source) {
	struct bellford *bf = (struct bellford *)malloc( sizeof (struct bellford)*g->vno);
	int t_source = source;
	for (int i=0; i<g->vno; i++) {
		if (i == source) {
			bf[i].weight  = 0;
			bf[i].fromnode = source;
			continue;
		}
		bf[i].weight = 999;
		bf[i].fromnode = 999;
	}
	for (int j=0 ; j< g->vno-1; j++) {
		t_source = 0;
		for (int i=0; i<g->vno; i++) {
			for(edge *e = g->v[i].e; e ; e=e->nextedge) {
				int vno = ((vertex*)e->edgetonode)->number;
				if(bf[vno].weight > (bf[i].weight + e->weight)) {
					bf[vno].weight = bf[i].weight + e->weight;
					bf[vno].fromnode = source;
				}
			}
		}
	}
	for (int i=0;i<g->vno;i++) {	
		printf("Source 0 dest %d %d weight %d\n",i, bf[i].fromnode, bf[i].weight );
	}
}

int main() {
   graph g;
   int dfsnode;
   int direct = 1;
   printf("Printf Enter number of vertices\n");
   scanf("%d",&g.vno);  
   g.v = (vertex*)malloc(sizeof(vertex)*g.vno);
   for (int i=0; i<g.vno; i++) {
	g.v[i].number = i;
	g.v[i].indegree = 0;
	g.v[i].outdegree = 0;
	g.v[i].visited = 0;
	g.v[i].e = NULL;
   }
   insertedge(&g,0,1,direct,20);
   insertedge(&g,1,2,direct,45);
   insertedge(&g,0,4,direct,34);
   insertedge(&g,4,3,direct,23);
   insertedge(&g,4,1,direct,-21);
   insertedge(&g,6,4,direct,12);
   insertedge(&g,6,2,direct,8);
   insertedge(&g,5,6,direct,1);
   printf("Printing the Graph:\n");
   printgraph(&g);
//   printf("Printing the Topological order\n");
//   topo_sort(&g);
     shortpath(&g,0);
   //shortpath_bf(&g, 0);
   //printf("Enter the node to start traversal from\n");
   //scanf("%d",&dfsnode);
   //printf("DFS Traversal\n");
   //dfs1(&g,dfsnode);
   /*for (int i=0; i<g.vno; i++) {
	g.v[i].visited = 0;
   }
   printf("\nBFS Traversal\n");
   bfs(&g,dfsnode);*/
}

