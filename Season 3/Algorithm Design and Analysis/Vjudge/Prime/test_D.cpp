#include <stdbool.h>
#include <stdio.h>
#include <string.h>
  
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


    scanf("%d",&T);
    char tampung[T][10];

    for (int i = 0; i < T; i++)
    {
        scanf("%d",&N);
        if(isPrime(N)){
            strcpy(tampung[i],"YES");
        }else{
            strcpy(tampung[i],"NO");
        }
        
    }
    for (int j = 0; j < T; j++)
    {
        printf("%s\n",tampung[j]);
    }


    return 0;
}
  