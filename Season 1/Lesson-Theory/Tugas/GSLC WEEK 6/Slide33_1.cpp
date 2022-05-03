#include <stdio.h>

int main(){

    int Input[10];
    int max = 9;
    int min = 0;
    int total=0;

    printf("input 10 nilai: \n");
    for(int i=0;i<10;i++){
		
		scanf("%d",&Input[i]);
		
	}

    for(int i = 0; i<10; i++){
        if (Input[i]<Input[min]){
			min =i;
		}
		if(Input[i]>Input[max]){
			max=i;
		}

        total += Input[i];

    }

    printf("Nilai min ada pada index %d yaitu %d\n",min,Input[min]);
	printf("Nilai min ada pada index %d yaitu %d\n",max,Input[max]);
	printf("Nilai rata-rata: %d",total/10);






    return 0;
}

