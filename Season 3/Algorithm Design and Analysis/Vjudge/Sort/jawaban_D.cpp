#include <stdio.h>
int x[100000];

int fg(int a[],int p,int r){
    int i,v,j,t;
    v=a[r];
    i=p-1;
    for (j=p ; j<=r-1; j++)
    {
        if(a[j]<=v){
            i++;
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    t=a[i+1];
    a[i+1]=a[r];
    a[r]=t;
    return i+1;

}
int main(){
    int n,i,q;
    scanf("%d",&n);
    for (i = 0; i < n; i++)
    {
        scanf("%d",&x[i]);
    }
    q=fg(x,0,n-1);
    for (i = 0; i < n; i++)
    {
        if(i==q){
            printf("[%d]",x[i]);
        }else{
            printf("%d",x[i]);
        }
        if(i!=n-1){
            printf(" ");
        }else{
            printf("\n");
        }
    }
    
    
}