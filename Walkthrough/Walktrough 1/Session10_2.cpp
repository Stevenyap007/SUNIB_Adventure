#include <stdio.h>

void swap(int *a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;


}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    int j;

    for (j = low; j < high; j++)
    {
        if(arr[j] < pivot){
            i++;
            swap(&arr[j], &arr[i]);
        }
    }

    swap(&arr[i+1], &arr[high]);

    return (i+1);
    
}

//Quick Sort
void quickSort(int arr[], int low, int high){
    // base case
    if (low == high){
        return;
    }

    int pivot = partition(arr,low,high);

    quickSort(arr,low,pivot-1);
    quickSort(arr,pivot,high);



}


void printArray(int arr[],int size){
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	
}

int main(){

    int arr[] = {5,7,4,9,1,10,11,6,3,8,2};
	int size = (int) sizeof(arr)/sizeof(arr[0]);

    quickSort(arr,0,size-1);

    printArray(arr,size);





    return  0;
}