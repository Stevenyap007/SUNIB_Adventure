#include <stdio.h>

int n, m, count;
int arr[100][100];
char map[100][100];

void step(int a, int b){
	if(a < 0 || a >= n || b < 0 || b >= n || map[a][b] == '#' || arr[a][b])
	return;
		
	arr[a][b] = true;
	count++;
	
	int x[] = {-1, 0, 1, 0};
	int y[] = {0, -1, 0, 1};
	
	for(int i = 0; i < 4; ++i){
		step(a + x[i], b + y[i]);
	}
}

int main(){
	
	scanf("%d %d", &n, &m); getchar();
	
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			scanf("%c", &map[i][j]); getchar();
		}
	}
	
	for(char c = 'a'; c <= 'z'; ++c){
		int a = -1, b = -1;
		for(int i = 0 ; i < n && a == -1; ++i){
			for(int j = 0; j < n && b == -1; ++j){
				if(map[i][j] == c){
					a = i, b = j;
					count = 0;
					step(a, b);
					
					if(count == 0) continue; {
						printf("%c %d\n", c, count);
					}
				}
			}
		}
	}
	
	return 0;
}