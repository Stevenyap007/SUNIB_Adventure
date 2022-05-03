#include <stdio.h>

int main (){

    int N,P,T;
    double X[100];    

    scanf("%d",&T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d %d",&N,&P);
          
        for(int j=0;N>0;j++){  
            X[j]=N%2;    
            N=N/2;
        } 
        printf("%.0lf\n",X[P]);  
    }
    
     
    







    return 0;
}