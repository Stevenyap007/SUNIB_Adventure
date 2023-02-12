#include <stdio.h>

int a[310][2], res[310];

void output(int cnt){
    int i;
    for (i = 0; i < cnt; i++)
        printf("(%4d,%4d)", a[ res[i]][0], a[ res[i]][1]);
    puts( "" );
}

int same_line(int x1, int y1, int x2, int y2, int x3, int y3){
    return (y2-y1) * ( x3 - x1 ) == ( x2 - x1 ) * ( y3 - y1 );
}

int main(){
    int x,y, sz = 0, i, j, k;
    while (scanf("%d%d", &a[sz][0], &a[sz][1]) > 0, a[sz][0] + a[sz][1])
    {
        int yes = sz++;
        while(scanf("%d%d", &a[sz][0], &a[sz][1]), a[sz][0] + a[sz][1])
            sz++;
        for ( i = 0; i < sz; i++)
            for ( j = i+1; j < sz; j++)
                if (a[i][0] > a[j][0] || (a[i][0] == a[j][0] && a[i][1] > a[j][1]))
                {
                    int tmp = a[i][0];
                    a[i][0] = a[j][0];
                    a[j][0] = tmp;
                    tmp = a[i][1];
                    a[i][1] = a[j][1];
                    a[j][1] = tmp;
                }
        for( i = 0; i < sz; i++)
            for(j = i+1 ; j < sz; j++){
                int cnt = 0;
                res[cnt++]=i;
                res[cnt++]=j;
                for(k=0;k <= j ; k++)
                    if(k != i && k != j)
                        if( same_line(a[i][0],a[i][1],a[j][0],a[j][1],a[k][0],a[k][1]))
                            k =sz;
                for(; k < sz;k++){
                    if( same_line(a[i][0],a[i][1],a[j][0],a[j][1],a[k][0],a[k][1])){
                        res[ cnt++ ] = k;
                    }
                }
                if( cnt > 2){
                    if( ++ yes == 1)
                        printf("The following lines were found:\n");
                    output( cnt );
                    
                }
            }

        if( !yes )
            printf("No lines were found\n");
        sz = 0;
    }
    
    return 0;
}