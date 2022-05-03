#include <stdio.h>

int jarak(int x_1, int y_1, int x_2, int y_2){  // mengetahui jarak
	return (x_1 - x_2) * (x_1 - x_2) + (y_1 - y_2) * (y_1 - y_2);
}

int min(int x, int y){   //function mencari minimal
	if (x > y) {
        return y;
    }else{
        return x;
    }
}

int main(){
	
	int a, i, j, k, l, m, n;//matrix dimension
	printf("Please input your matrix dimension: ");
	scanf("%d", &a);
	
	printf("\nPlease input your matrix: \n");
	
	int matrix[a][a];// declare matrix
	
	for( i = 0; i < a; i++){
		for( j = 0; j < a; j++){
			scanf("%d", &matrix[i][j]); //matrix input
		}
	}

	//mencari koordinat center
	int center_x = a/2;
	int center_y = a/2;
	int center  = matrix[center_x][center_y];
	int max = 999; 
	
	for( k = 0; k < a; k++){
		for( l = 0; l < a; l++){
            printf("k dan l = %d dan %d\n",k,l);
			if((k != center_x || l != center_y) && (center == matrix[k][l])){
				max = min(max,jarak(k, l, center_x, center_y));
                printf("max = %d\n",max);
			}
		}
	}

	int find = 0;
		printf("Nearest same elements is at: ");
		
	for( m = 0; m < a; m++){
		for( n = 0; n < a; n++){
			if((center == matrix[m][n]) && (jarak(m, n, center_x, center_y) == max)){
                // printf("m n center jarak = %d %d %d %d\n",m, n, center,jarak(m, n, center_x, center_y));
				if(find == 0){  // untuk print jika ada 1 elemen saja
					printf("(%d,%d)", m, n);
					find++;
				}else{
					printf(" and (%d, %d)\n", m, n);//untuk print jika ada elemen yang lebih
				}
                // printf("find = %d\n",find);
			}
		}
	}
	if(!find){
		puts("no nearest element\n");
	}// print apabila tidak ada elemen terdekat
	return 0;
}

/*
5
0	0	2	0	0
0	1	0	0	0
0	0	1	0	5
0	0	0	0	0
0	0	0	0	1

5
0	0	2	0	0
0	1	0	0	0
0	1	1	1	5
0	0	0	0	0
0	0	0	0	7

4
0	0	2	0
0	0	0	0
0	0	1	0
0	0	0	0

*/