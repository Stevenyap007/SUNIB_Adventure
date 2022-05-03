#include <stdio.h>

void mergeSort(int arr[], int left, int right){

	// base case
	if(left == right){
		return;
	}


	// devide
	int middle = (right+left)/2;

	mergeSort(arr,left,middle);
	mergeSort(arr,middle+1,right);

	//conquer
	int tempArr[right-left];

	int leftIndex = left;
	int leftLimit = middle;
	int rightIndex = middle+1;
	int rightLimit = right;

	int tempIndex = 0;

	// sorting

	while(leftIndex <= leftLimit && rightIndex <= rightLimit){
		if(arr[leftIndex] < arr[rightIndex]){
			tempArr[tempIndex] = arr[leftIndex];
			leftIndex++;
			tempIndex++;
		}else{
			tempArr[tempIndex] = arr[rightIndex];
			rightIndex++;
			tempIndex++;
		}
	}

	// kiri masih sisa
	while (leftIndex <= leftLimit)
	{
		tempArr[tempIndex] = arr[leftIndex];
		leftIndex++;
		tempIndex++;
	}

	// kanan masih sisa
	while (rightIndex <= rightLimit)
	{
		tempArr[tempIndex] = arr[rightIndex];
		rightIndex++;
		tempIndex++;
	}

	tempIndex = 0;

	for (int i = left; i <= right; i++)
	{
		arr[i] = tempArr[tempIndex];
		tempIndex++;
	}
}

int main (){

    int N;
    scanf("%d",&N);
    int angka[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d",&angka[i]);
    }
    mergeSort(angka,0,N-1);
    //sorting data

    int poin = 0;
    
    for(int i=0; i<N-2; i++){
        if(angka[i] + angka[i+1] > angka[i+2]){
            poin = 1;
            break;
        }
        //menentukan apakah array termasuk segitiga
    }
    
    if(poin == 0){
        printf("NO\n");
    }else{
        printf("YES\n");
    }
    //output
    





    return 0;
}