#include  <stdio.h>

int jawaban(int A,int B){
    while ((A != 1) || (A != B)){
        if ((A == 1) || (A == B)){
            A = A;
            break;
        }else if (A % 2 == 0){
            A = A/2;
        }else if (A % 2 != 0){
            A = A * 3 + 1;
        }
    }
    
      
    // if ((A == 1) || (A == B)){
        return A;
    // }
    // return jawaban(A,B);    
}

int main (){

    int T,A,B;

    scanf ("%d",&T);

    for (int i = 0; i < T; i++)
    {
        scanf("%d %d",&A,&B);
        if (jawaban(A,B) == B){
            printf("Case #%d: YES\n",i+1);
        }else{
            printf("Case #%d: NO\n",i+1);
        }
    }
    
    return 0; 
}