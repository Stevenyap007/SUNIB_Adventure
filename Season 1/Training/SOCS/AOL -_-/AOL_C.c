#include <stdio.h>

int main(){
	
	int n, i, j, k, l;  
	printf("Input your size of matrix : "); 
	scanf("%d", &n); 
	
	int m_1[n][n], count_1 = 0;  
	printf("Please input your first matrix\n");
	for(  i = 0; i < n; i++){
		for(  j = 0; j < n; j++){    
			scanf("%d", &m_1[i][j]);    
				if( m_1[i][j] == 1){
					count_1 += 1;
				}
		}
	}
	int m_2[n][n], count_2 = 0;  
	printf("Please input your second matrix\n");
	for(  k = 0; k < n; k++){
		for(  l = 0; l < n; l++){  
			scanf("%d", &m_2[k][l]);   
				if( m_2[k][l] == 1){
					count_2 += 1;
				}
		}
	}
	if ( count_1 == count_2 ){                       
		printf("object 1 and 2 has the same size\n");  
	}else if( count_1 > count_2 ){            
		printf("object 1 is bigger\n");       
	}else if( count_1 < count_2 ){           
		printf("object 2 is bigger\n");        
	}
	return 0;
}


/*
5
0 0 1 0 0
0 1 0 1 0
0 0 1 0 0
0 0 0 0 0
0 0 0 0 0

0 0 1 0 0
0 1 0 1 0
0 1 0 1 0
0 1 0 1 0
0 0 1 0 0
*/