#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int H;
int A[2000001];

int parent(int i){
    return i/2;
}

int left(int i){
    return i*2;
}

int right(int i){
    return i*2+1;
}

int isin(int N,int k){
    return 1<=k && k<=N;
}

void maxheapify(int i){
    int l=left(i);
    int r=right(i);
    int max=i;
    if(l<=H&&A[l]>A[max]){
        max=1;
    }
    if(r<=H && A[r]>A[max]){
        max = r;
    }
    if(max!=i){
        int tmp = A[i];
        A[i] = A[max];
        A[max]=tmp;
        maxheapify(max);
    }
}

void insert(int k){
    H++;
    A[H]=k;
    int i =H;
    while (i>1 && A[parent(i)]<A[i])
    {
        int tmp = A[parent(i)];
        A[parent(i)]=A[i];
        A[i]=tmp;
        i=parent(i);
    }
    
}

int extract(){
    int max=A[1];
    A[1]=A[H];
    H--;
    maxheapify(1);
    return max;
}

int main(void){
    while(1){
        char com[10];
        scanf("%s",com);
        if(strcmp(com, "insert")==0){
            int num;
            scanf("%d",&num);
            insert(num);
        }else if(strcmp(com,"extract")==0){
            printf("%d\n",extract());
        }else{
            break;
        }
    }

    return 0;
}