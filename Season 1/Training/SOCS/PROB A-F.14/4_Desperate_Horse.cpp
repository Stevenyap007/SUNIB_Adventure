#include <stdio.h>

int FinalD_x, FinalD_y, minimal, test=0;

void knightmove(int awal_x, int awal_y, int langkah){

    if(langkah > 6 ||awal_x < 1 || awal_y < 1 || awal_x > 8 || awal_y > 8){
        return;
    }

    if(awal_x == FinalD_x && awal_y == FinalD_y){
        if(langkah < minimal){
            minimal = langkah;
        }
        return;
    }
    knightmove(awal_x + 2, awal_y + 1, langkah + 1);
    knightmove(awal_x + 2, awal_y - 1, langkah + 1);
    knightmove(awal_x - 2, awal_y + 1, langkah + 1);
    knightmove(awal_x - 2, awal_y - 1, langkah + 1);
    knightmove(awal_x + 1, awal_y + 2, langkah + 1);
    knightmove(awal_x + 1, awal_y - 2, langkah + 1);
    knightmove(awal_x - 1, awal_y + 2, langkah + 1);
    knightmove(awal_x - 1, awal_y - 2, langkah + 1);
}


int main()
{
    int tc;
    scanf("%d", &tc);
    getchar();

    for(int i = 1; i <= tc; i++){
        minimal = 7;
        char x1,x2;
        int y;

        scanf("%c%d %c%d", &x1, &y, &x2, &FinalD_y);
        getchar();

        int x = x1 - 'A' + 1;
        FinalD_x = x2 - 'A' + 1;

        knightmove(x, y, 0);

        printf("Case #%d: %d\n", i, minimal);
    }
    return 0;
}