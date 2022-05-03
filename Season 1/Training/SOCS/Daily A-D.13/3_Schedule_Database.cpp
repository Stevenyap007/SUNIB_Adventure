#include <stdio.h>

struct daftar
{
    char code[9];
    char day[20];
    int time;
};

int main()
{
    int T, urutan;
    int arr[1001];
    scanf("%d", &T);
    
    struct daftar a[T + 1];
    for (int i = 1; i <= T; i++)
    {
        scanf("%s", a[i].code);
        
        scanf("%s", a[i].day);
        
        scanf("%d", &a[i].time);
        
    }

    scanf("%d", &urutan);
    for (int i = 1; i <= T; i++)
    {
        scanf("%d", &arr[i]);
        
    }

    for (int i = 1; i <= urutan; i++)
    {
        printf("Query #%d:\n", i);
        printf("Code: %s\n", a[arr[i]].code);
        printf("Day: %s\n", a[arr[i]].day);
        printf("Time: %02d:00\n", a[arr[i]].time);
    }

    return 0;
}