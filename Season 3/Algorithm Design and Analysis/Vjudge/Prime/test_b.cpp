#include <stdbool.h>
#include <stdio.h>
  
bool isPrime(int n)
{
    if (n == 1 || n == 0)
        return false;
  
    for (int i = 2; i < n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}
  

int main()
{
    int T;
    int N;
    int jum_prim = 1;

    scanf("%d",&T);
    int tampung[T];

    for (int i = 0; i < T; i++)
    {
        scanf("%d",&N);
        if(isPrime(N)){
            tampung[i] = jum_prim;
            jum_prim++;
        }else{
            tampung[i] = -1;
        }
        
    }
    for (int j = 0; j < T; j++)
    {
        printf("%d\n",tampung[j]);
    }


    return 0;
}
  