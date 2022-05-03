#include <stdio.h>
#include <string.h>

int main(){
	
	int T;
	scanf("%d", &T); 
	
	char kata[T][100005];
	int count[T];
	
	for(int i = 0; i < T; i++){
		scanf("%s", kata[i]); 
	}
	
	for(int i = 0; i < T; i++){
		int l = strlen(kata[i]) - 1;
		for(int j = 0; j <= l; j++){
			count[i] = count[i] + 1;
			if(j != 0){
				for(int k = 0; k < j; k++){
					if(kata[i][j] == kata[i][k]){
						count[i] = count[i] - 1;
						break;
					}
				}
			}
		}
		
		printf("Case #%d: ", i + 1);
		if(count[i] % 2 == 1){
			printf("Unbreakable\n");
		} else {
			printf("Breakable\n");
		}
	}
	
	return 0;
}