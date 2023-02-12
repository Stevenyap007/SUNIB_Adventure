#include <stdio.h>
#include <limits.h>
int ct = 0;

void merge(int a[],int l,int mid, int r){
    int n1=mid-l+1;
    int n2=r-mid;
    int L[n1+1],R[n2+1];
    for (int i = 0; i < n1; i++)
    {
        L[i]=a[l+i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j]=a[mid+j+1];
    }
    L[n1]=R[n2]=INT_MAX;
    int i = 0;
    int j = 0;
    for(int k = l;k<=r;k++){
        if(L[i]<=R[j]){
            a[k]=L[i];
            i++;
        }else{
            a[k]=R[j];
            j++;
        }
        ct++;
    }
}

void mergesort(int a[],int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}

int main(){
    int t;
    scanf("%d",&t);
    int a[t];
    for (int i = 0; i < t; i++)
    {
        scanf("%d",&a[i]);
    }
    mergesort(a,0,t-1);
    for (int i = 0; i < t-1; i++)
    {
        printf("%d ",a[i]);     
    }
    printf("%d",a[t-1]);
    printf("\n");
    printf("%d\n",ct);
    


    return 0;
}