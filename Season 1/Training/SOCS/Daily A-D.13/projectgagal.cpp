#include <stdio.h>



int main()
{
    int T, Q;
    int arr[1001];
    char code[T][40];
    char day[T][100];
    int time[100];


    scanf("%d", &T);
    getchar();
    
    
    for (int i = 1; i <= T; i++)
    {
        scanf("%s", &code[i]);
        getchar();
        scanf("%s", &day[i]);
        getchar();
        scanf("%d", &time[i]);
        getchar();
    }

    scanf("%d", &Q);
    for (int i = 1; i <= T; i++)
    {
        scanf("%d", &arr[i]);
        getchar();
    }


    for (int i = 1; i <= Q; i++)
    {
        printf("Query #%d:\n", i);
        printf("Code: %s\n", code[arr[i]]);
        printf("Day: %s\n", day[arr[i]]);
        printf("Time: %02d:00\n", time[arr[i]]);
    }

    return 0;
}