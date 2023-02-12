#include <stdio.h>
 
int main(){
	int i,j,n,flag=0;
	
	scanf("%d", &n);
	
	for(i=n; i>0; i++){
		flag=0;
		for(j=1; j<=i; j++){
			if(i%j==0){
				flag++;
			}
		}
		if(flag==2){
			printf("%d",i);
			break;
		}
	}
}