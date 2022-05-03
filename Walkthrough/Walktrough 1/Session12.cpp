#include <stdio.h>

int temp[] = {};

int fibo(int n){
    // base case
    if(n <= 1 ){
        return n;
    }
    return fibo(n-1) + fibo(n-2);
}

int fibo_memoized(int n){
    // base case
    if (temp[n] != 0){
        return temp[n];
    }

    temp[n] = fibo(n-1) + fibo(n-2);

    return temp[n];
}

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

void printArr(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
        
    }
    puts("");
}

int binarySearch(int arr[], int left,int right, int x){
    if(right >= left){
        int middle  =(right+left)/ 2;

        if(arr[middle] == x){
            return middle;
        }

        if(arr[middle] > x){
            return binarySearch(arr,middle+1,right,x);
        }else{
            return binarySearch(arr,left,middle-1,x);
        }
    }
    return -1;
}


int main(){
    // printf("%d\n",fibo_memoized(6));

    int arr[] = {3,5,2,4,1,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,size-1);
    printf("%d",binarySearch(arr,0,size-1,3));


    return 0;
}