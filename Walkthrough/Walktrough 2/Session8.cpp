#include <stdio.h>
#include <malloc.h>

//Min Heap
int heap[30];
int size = 0;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b ;
    *b = temp;
}

int getParentPos(int pos){
    return (pos-1)/2;
}

int getLeftChildPos(int pos){
    return pos * 2 + 1;
}

int getRightChildPos(int pos){
    return pos * 2 + 2;
}

//minheap
void insert(int value){
    heap[size] = value;
    
    // bandingin dengan parent
    int idx = size;
    while(idx != 0 && heap[getParentPos(idx)] > heap[idx]){
        swap(&heap[getParentPos(idx)],&heap[idx]);
        idx = getParentPos(idx);
    }
    
    size++;
}
// maxheap
// void insert(int value){
//     heap[size] = value;
    
//     // bandingin dengan parent
//     int idx = size;
//     while(idx != 0 && heap[getParentPos(idx)] < heap[idx]){
//         swap(&heap[getParentPos(idx)],&heap[idx]);
//         idx = getParentPos(idx);
//     }
    
//     size++;
// }
void minHeap(int idx){
    int largest = idx;
    int left = getLeftChildPos(idx);
    int right = getRightChildPos(idx);

    if(left < size && heap[largest] > heap[left]){
        largest = left;
    }

    if(right < size && heap[largest] > heap[right]){
        largest = right;
    }

    if(largest != idx){
        swap(&heap[idx],&heap[largest]);
        minHeap(largest);
    }
}

// void maxHeap(int idx){
//     int largest = idx;
//     int left = getLeftChildPos(idx);
//     int right = getRightChildPos(idx);

//     if(left < size && heap[largest] < heap[left]){
//         largest = left;
//     }

//     if(right < size && heap[largest]< heap[right]){
//         largest = right;
//     }

//     if(largest != idx){
//         swap(&heap[idx],&heap[largest]);
//         minHeap(largest);
//     }
// }


void deleteHeap(){
    heap[0] = heap[size-1];
    size--;
    minHeap(0);
}

void printAll(){
    for (int i = 0; i < size; i++)
    {
        printf("%d. %d\n",i,heap[i]);
    }
    
}

int main(){

    insert(10);
    insert(1);
    insert(2);
    insert(5);
    insert(6);
    insert(7);
    insert(8);
    printAll();

    puts("");
    deleteHeap();
    printAll();



    return 0;
}