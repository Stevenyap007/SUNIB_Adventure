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
    int N;

    scanf("%d",&N);
  
    if(isPrime(N) == 0){
        printf("NO\n");
    }else{
        printf("YES\n");
    }
  
    return 0;
}