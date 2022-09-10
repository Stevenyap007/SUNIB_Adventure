#include <stdio.h>

int parent[255] = {0};

void makeSet(int vertexCount){
    for (int i = 0; i < vertexCount; i++)
    {
            parent[i] = i;
    }  
}

int findParent(int vertex){
    // base cxase klo dia merupakan parent maka return
    if (parent[vertex] == vertex){
        return vertex;
    }
    return findParent(parent[vertex]);
}

void join(int vertexA,int vertexB){
    // ambil paent si vertexA,B
    int parentA = findParent(vertexA);
    int parentB = findParent(vertexB);

    // parameter kedua menjadi parent
    parent[parentA] = parentB;

    // klo misalnya parameter pertama jadi parent
    // parent[parentB] = parentA;
}

// cek apakah suatu vertex berhubungan
bool isSameSet(int vertexA, int vertexB){
    return findParent(vertexA) == findParent(vertexB); 
}

int main(){
    makeSet(6);
    join(0,1);
    join(1,2);
    join(2,3);

    join(3,5);

    join(4,5);
    if(isSameSet(0,4)){
        puts("berhubung");
    }
    else{
        puts("Tidak Berhubung");
    }

    return 0;
}