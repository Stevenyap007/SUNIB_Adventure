#include <stdio.h>

int n, m, jumlah;
int vis[100][100];
char arena[100][100];

void langkah(int x, int y){
	if(x < 0 || x >= n || y < 0 || y >= n || arena[x][y] == '#' || vis[x][y])
    //memntukan batas
		return;
	vis[x][y] = true;
	jumlah++;
	
	int dx[] = {-1, 0, 1, 0};
	int dy[] = {0, -1, 0, 1};
	for(int k = 0; k < 4; ++k){
		langkah(x + dx[k], y + dy[k]);
	}
    //floodfill function
}

int main(){
	scanf("%d %d", &n, &m);
	getchar();
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j)
			scanf("%c", &arena[i][j]);
		getchar();	
	}
	
	for(char c = 'a'; c <= 'z'; ++c){
		int x = -1, y = -1;
		for(int i = 0; i < n && x == -1; ++i){
			for(int j = 0; j < n && y == -1; ++j){
				if(arena[i][j] == c){
                    // menentukan character yang ingin dilihat langkanhnya
					x = i, y = j;
		            jumlah = 0;
		            langkah(x, y);
                    if(jumlah == 0) continue;{
		            printf("%c %d\n", c, jumlah);
                    }
                }
            }
        }
	}

	return 0;
}