#include <stdio.h>

int H;
void maxHeapify(int A[], int i){
    int max = i;
    int lp = 2*i;
    int rp = 2*i+1;

    if(lp > H){
        return;
    }
    if(rp<=H){
        if((A[lp] > A[rp]) && (A[i] < A[lp])){
            max = lp;
        }else if((A[lp] < A[rp]) && (A[i] < A[rp])){
            max = rp;
        }
    }else {
        if(A[i] < A[lp]){
            max = lp;
        }
    }
    if(max != i){
        int  temp =  A[max];
        A[max] = A[i];
        A[i] = temp;
        maxHeapify(A,max);
    }
    
}

int main(){
    scanf("%d",&H);
    int A[H+5];
    for (int i = 1; i <= H; i++)
    {
        scanf("%d", &A[i]);
    }

    for (int i = H/2; i >= 1 ; i--)
    {
        maxHeapify(A,i);
    }
    
    for (int i = 1; i <= H; i++)
    {
        printf(" %d",A[i]);
    }
    printf("\n");
    
    return 0 ;
}