#include <stdio.h>

int main (){

	int T, A, B;
	scanf("%d", &T);
	
	for(int tc = 0; tc < T; tc++){
		scanf("%d %d", &A, &B);	
		int result = 0;
		int x = 1;
		
		while(A > 0 || B > 0){
			result += (((A % 10) + (B % 10)) % 10) * x;
			A /= 10;
			B /= 10;
			x *= 10;
		}
		printf("Case #%d: %d\n", tc + 1, result);
	}



    return 0;
}