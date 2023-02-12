#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    long long int tc;
    scanf("%lld",&tc);
    getchar();

    long long int time[tc];
    for(int i =0 ; i<tc-1; i++){
        scanf("%lld", &time[i]);
        getchar();
    }

    long long int steak[tc+1];
    for(int i=0; i<tc; i++){
        scanf("%lld", &steak[i]);
        getchar();
    }
    
    long long int order[tc+1];
    for(int i=0;i<tc;i++){
        scanf("%lld",&order[i]);
        getchar();
    }
    
    long long int AA;
    long long int j=tc-1;
    long long int count=0,clock=0;
    while(j>=1){
        if(steak[j]<order[j]){
            AA = order[j]-steak[j];
            steak[j-1] = steak[j-1]-AA;
            steak[j] = steak[j]+AA;
            count += AA*time[j-1];
        }
        if(steak[j]>order[j]){
            clock++;
        }
        j--;
    }

    if(steak[0]<0 || order[0]>steak[0]){
        printf("-1\n");
    }
    else{
        printf("%lld\n", count);
    }

    return 0;
}