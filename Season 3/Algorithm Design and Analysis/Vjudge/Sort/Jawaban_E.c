#include <stdio.h>
#define max 100000
#define wx 2000000000

struct card
{
    char suit;
    int value;
};
struct card L[max/2+2],R[max/2+2];
void merge(struct card a[],int n, int l, int mid, int r){
    int i,j,k;
    int n1=mid-1;
    int n2=r-mid;
    for ( i = 0; i < n1; i++)
    {
        L[i]=a[l+i];
    }
    for ( i = 0; i < n2; i++)
    {
        R[i]=a[mid+i];
    }
    L[n1].value=R[n2].value=wx;
    i=j=0;
    for ( k = l; k < r; k++)
    {
        if(L[i].value<=R[j].value){
            a[k]=L[i++];
        }
        else{
            a[k]=R[j++];
        }
    }
    
}

void mergesort(struct  card a[],int n, int l, int r)
{
    int mid;
    if(l+1<r){
        mid=(l+r)/2;
        mergesort(a,n,l,mid);
        mergesort(a,n,mid,r);
        merge(a,n,l,mid,r);
    }
}

int partition(struct card a[],int p, int r){
    int i,j;
    struct card x,t;
    x=a[r];
    i=p-1;
    for ( j=p; j <= r-1; j++)
    {
        if(a[j].value<=x.value){
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

void quickSort(struct card a[],int p, int r){
    int q;
    if(p<r){
        q=partition(a,p,r);
        quickSort(a,p,q-1);
        quickSort(a,q+1,r);
    }
}

int main(){
    int n,i,v;
    struct card a[max], b[max];
    char x[10];
    int stable=1;
    scanf("%d",&n);
    for ( i = 0; i < n; i++)
    {
        scanf("%s %d",x,&v);
        a[i].suit=b[i].suit=x[0];
        a[i].value=b[i].value=v;
    }
    mergesort(a,n,0,n);
    quickSort(b,0,n-1);
    for ( i = 0; i < n; i++)
    {
        if(a[i].suit!=b[i].suit){
            stable =0;
        }
    }
    if(stable==1)
    printf("Stable\n");
    else
    printf("Not Stable\n");
    for ( i = 0; i < n; i++)
    {
        printf("%c %d\n",b[i].suit,b[i].value);
    }
    return 0;
    
}
