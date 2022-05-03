#include <stdio.h>

long long int Search(long long int arr[],long long int batas,int left,int right)
{
    long long int middle=0,idx=-2;
    while(left<=right)
    {
        middle=(left+right)/2;
        if(arr[middle]<=batas)
        {
            idx=middle;
            left=middle+1;
        }
        else 
        right=middle-1;
    }
    return idx+1;
}

int main()
{
    int N;
    long long int Q,M;
    scanf("%d",&N);
    
    long long int x[100001]={};
    long long int arr_jumlah[100001]={};
    
    for(int i=0;i<N;i++)
    {
        scanf("%lld",&x[i]);
        arr_jumlah[i] = x[i]+arr_jumlah[i-1];
    }
    
    scanf("%lld",&Q);
    for(int i=0;i<Q;i++)
    {
        scanf("%lld",&M);
        printf("Case #%d: %lld\n",i+1,Search(arr_jumlah,M,0,N-1));
    }
    return 0;
}

/*
5
2 9 5 5 7 
6
11
12
16
17
22
3

*/