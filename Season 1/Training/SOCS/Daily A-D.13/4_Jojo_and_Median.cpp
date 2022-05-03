#include <stdio.h>

struct item
{
    char id[20];
    char makanan[20];
    long long harga;
};

int main()
{
    int T;
    long long temp = 0;
    scanf("%d", &T);
    getchar();
    struct item food[30000];
    for (int i = 0; i < T; i++)
    {
        scanf("%[^\n]s", food[i].id);
        getchar();
        scanf("%[^\n]s", food[i].makanan);
        getchar();
        scanf("%lld", &food[i].harga);
        getchar();
    }

    temp = food[T / 2].harga;

    for (int i = 0; i < T; i++)
    {
        if (food[i].harga >= temp)
        {
            printf("%s %s\n", food[i].id, food[i].makanan);
        }
    }

    return 0;
}