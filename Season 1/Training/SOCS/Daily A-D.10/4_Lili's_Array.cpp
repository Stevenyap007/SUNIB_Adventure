#include<stdio.h>

    int main() {
	
	int T;
	scanf("%d", &T);
	
	for(int i = 0; i < T; i++){
		int N;
		scanf("%d", &N);
		
		int X[N] = {};
		for(int j = 0; j < N; j++){
			scanf("%d", &X[j]);
		}
		
		int max = 0, count = 0, Z = 1000000005;
		for(int j = 0; j < N; j++){
			if(X[j] == 0){
				continue;
			}
			count = 1;
			for(int k = j + 1; k < N; k++){
				if(X[j] == X[k]){
					X[k] = 0;
					count++;
				}
			}
			
			if(count > max){
				max = count;
				Z = X[j];
			} else if(count == max){
				if(X[j] < Z){
					Z = X[j];
				}
			}
		}
		printf("Case #%d: %d\n%d\n", i + 1, max, Z);
    }

    return 0;
}
