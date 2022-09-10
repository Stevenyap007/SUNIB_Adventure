#include <stdio.h>
#include <malloc.h>

int parent[255] = {0};

struct Edge{
    int source;
    int destination;
};

struct Graph{
    int verticesCount, edgesCount;
    Edge *edge;
};

// creategraph
Graph* createGraph(int verticesCount, int edgesCount){
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->verticesCount = verticesCount;
    graph->edgesCount = edgesCount;
    graph->edge = (Edge*)malloc(sizeof(Edge) * edgesCount);
    return graph;
}

void makeSet(int vertexCount){
    for (int i = 0; i < vertexCount; i++)
    {
        parent[i] = i;
    }
}

int findParent(int vertex){
    if(parent[vertex] == vertex){
        return vertex;
    }

    return findParent(parent[vertex]);
}

bool join(Graph* graph){
    for (int i = 0; i < graph->edgesCount; i++)
    {
        int source = findParent(graph->edge[i].source);
        int destination = findParent(graph->edge[i].destination);

        // validasi apakah cyclic
        if(source == destination){
            return true;
        }

        //join
        parent[source] = destination;
    }
    
    return false;
}

bool isCyclic(Graph* graph){
    makeSet(graph->verticesCount);
    return join(graph);
}


int main(){
    Graph* graph = createGraph(4,4);

    graph->edge[0].source = 0;
    graph->edge[0].destination = 1;

    graph->edge[1].source = 1;
    graph->edge[1].destination = 2;

    graph->edge[2].source = 2;
    graph->edge[2].destination = 3;
    
    graph->edge[3].source = 3;
    graph->edge[3].destination = 0;  

    if(isCyclic(graph)){
        puts("graphnya siklik");
    }
    else{
        puts("graphnya tidak siklik");
    }

    return 0;
}
