#include<stdio.h>
#include<stdlib.h>
int visited[100] = {0,};

struct node {
    int vertex;
    struct node* next;
};
struct node* createNode(int);

struct Graph {
    int numVertices;
    struct node** adjLists; // we need a pointer to add the pointer of adjLists
};

// Create a node
struct node* createNode(int v) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct node*));

    int i;
    for (i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

// Add edge
void addEdge(struct Graph* graph, int s, int d) {
    // Add edge from s to d
    struct node* newNode = createNode(d);
    newNode->next = graph->adjLists[s];
    graph->adjLists[s] = newNode;

    // Add edge from d to s
    newNode = createNode(s);
    newNode->next = graph->adjLists[d];
    graph->adjLists[d] = newNode;
}

void dfs_vlr(struct Graph* graph, int i){
    //using dfs make all vertices linked to 1 visited[i] = 1
    struct node* temp = graph->adjLists[i];
    visited[temp->vertex] = 1;
    while(temp){
        if(visited[temp->vertex] != 1){
            dfs_vlr(graph, temp->vertex);
            visited[temp->vertex] = 1;
        }
        temp = temp->next;
    }
}

int main(){
    int ver_num, edge_num, vir_num = 0; //vertex num, edge num, virus num
    struct Graph* graph = createGraph(100);
    scanf("%d", &ver_num);
    scanf("%d", &edge_num);
    for(int i = 0; i<edge_num; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(graph, a, b);
    }
    dfs_vlr(graph, 1);
    for(int i = 1; i<=edge_num; i++){
        if(visited[i] == 1) {
            vir_num++;
        }
    }
    printf("%d", vir_num);
    return 0;
}
