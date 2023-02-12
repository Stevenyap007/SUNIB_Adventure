#include <stdio.h>
#include <stdlib.h>


int comp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int linear_search(int *s, int n, int x)
{
    int left, right, center;

    left = 0;
    right = n - 1;
    while (left <= right){
        center = (left + right) / 2;
        
        if (s[center] < x){
            left = center + 1;
        }
        else if (s[center] > x){
            right = center - 1;
        }
        else {
            return (1);
        }
    }
    
    return (0);
}

int main(void)
{
    int n, S[100000], q, T[50000];
    int cnt;
    int i;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%d", &S[i]);
    }

    scanf("%d", &q);
    for (i = 0; i < q; i++){
        scanf("%d", &T[i]);
    }
    
    qsort(S, n, sizeof(int), comp);
    
    cnt = 0;
    for (i = 0; i < q; i++){
        cnt += linear_search(S, n, T[i]);
    }
    
    printf("%d\n", cnt);

    return (0);
}