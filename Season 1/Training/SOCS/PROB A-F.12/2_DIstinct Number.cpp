#include <stdio.h>

int main()
{

    int T;
	scanf("%d", &T);
	
	int X = 1;
	while(X <= T){
		int N;
		scanf("%d", &N);
		
		static int nomor[1000005] = {0};
		
		for(int i = 0; i < 1000005; i++){
			nomor[i] = 0;
		}
		
		int count = 0;
		for(int i = 0; i < N; i++){
			int Y;
			scanf("%d", &Y);
			if(nomor[Y] == 0){
				nomor[Y]++;
				count++;
			}
		}
		printf("Case #%d: %d\n", X, count);
		X++;
	}
    return 0;
}