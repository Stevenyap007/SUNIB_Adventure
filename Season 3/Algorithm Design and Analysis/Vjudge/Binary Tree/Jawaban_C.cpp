#include <stdio.h>
#include <stdlib.h>
#define max 2000000

int n,a[max+1];

void maxheapify(int i){
    int l,r,t,q;
    l = 2*i;
    r = i*2+1;
    if(l>n && r>n){
        return;
    }
    if(l<=n && a[l]>a[i] ){
        t=l;
    }else{
        t=i;
    }
    if(r<=n && a[r]>a[t] ){
        t=r;
    }
    if(t!=i){
        q = a[i];
        a[i] = a[t];
        a[t] = q;
        maxheapify(t);
    }
}

int extract(){
    int v;
    if(n<1){
        return -1;
    }  
    v = a[1];
    a[1] = a[n--];
    maxheapify(1);
    return v;  
}

void increasekey(int i, int key){
    if(key<a[i]){
        return ;
    }
    a[i] = key;
    while(i>1 && a[i/2] < a[i]){
        int t;
        t = a[i];
        a[i] = a[i/2];
        a[i/2] = t;
        i=i/2;
    }
}

void insert(int key){
    n++;
    a[n]=-1;
    increasekey(n,key);
}

int main(){
    int i,x;
    char com[10];
    while(1){
        for(int j=0;j<10;j++){
            if(j==0){
                scanf("\n");
            }
            scanf("%c",&com[j]);
            if(com[j] == ' '|| com[j]=='\n'){
                com[j]= '\0';
                break;
            }
        }
        if(com[0]=='e'&&com[1]=='n'){
            break;
        }
        if(com[0]=='i'){
            scanf("%d",&x);
            insert(x);
        }else{
            printf("%d\n",extract());
        }
    }
    return 0;
}