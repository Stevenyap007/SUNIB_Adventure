# include <stdio.h>
# include <string.h>

int main(){

//	int A[5]= {1,2,3,4,5};
//	
//	printf("%d\n",A[3]);
//	printf("%d\n",*(A+3));
//	
//	int  B[10];
//	for(int i=0;i<10;i++){
//		B[i] = i+1;
//	}
//	
//	for(int i= 0; i<10;i++){
//		printf("index %d: %d\n",i, B[i]);	
//	}

//int x[3][2][4] = {
//				  {{1,2,3,4}, {5,6,7,8}},
//                  {{11,12,13,14}, {15,16,17,18}},
//                  {{21,22,23,24}, {25,26,27,28}}
//			     };   
// 	for(int i=0;i<4;i++){
// 		for(int  j=0;j<3;j++){
// 			for(int k=0;k<5;k++){
// 				printf("Nilai X ideks ke %d %d %d:%d\n",i,j,k,x[i][j][k]);
//			 }
//		 }
//	 }
//   	printf("%5d", x[2][1][3]);

	int x[10],min =0,max=9,total=0;
	for(int i=0;i<10;i++){
		printf("input 10 nilai: \n");
		scanf("%d",&x[i]);
		
	}
	for(int i=0;i<10;i++){
		printf("Nilai ke-%d:%d\n",i+1,x[i]);
		total = total+1;
		if (x[i]<x[min]){
			min =i;
		}
		if(x[i]>x[max]){
			max=i;
		}
	}
	printf("Nilaimin ada pada index %d yaitu %d\n",min,x[min]);
	printf("Nilaimin ada pada index %d yaitu %d\n",max,x[max]);
	printf("Nilai rata-rata: ");
	
	
	
	
return 0;	
} 



