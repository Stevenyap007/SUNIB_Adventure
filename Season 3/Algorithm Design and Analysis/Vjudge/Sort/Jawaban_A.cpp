#include <stdio.h>
int a[2000],v[2000],n;
int solve(int i,int m){
    int r;
    if(m==0){
        return 1;
    }
    if(i>=n){
        return 0;
    }
    r=solve(i+1,m)||solve(i+1,m-a[i]);
    return r;
}
int main(){
    int i,q,l;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d",&v[i]);
        l=solve(0,v[i]);
        if(l)printf("yes\n");
        else 
        printf("no\n");
    }
    return 0;
}