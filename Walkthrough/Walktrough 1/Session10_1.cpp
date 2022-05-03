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

void printArray(int arr[],int size){
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	
}

int main(){
	
	// Merge Sort
	int arr[] = {5,7,4,9,1,10,11,6,3,8,2};
	int size = (int) sizeof(arr)/sizeof(arr[0]);

	mergeSort(arr,0,size-1);
	printArray(arr,size);
	
	
	
	
	
	
	
	
	
	return 0;
}
