#include <stdio.h>

struct Student{
    char nim[10];
    char name[100];
    int age;
};

void changeValue(int *ptr){
    *ptr = 100;
}

// void printArray(int arr[], int size){
//     for (int i = 0; i < size; i++)
//     {
//         printf("%d\n",arr[i]);
//     }
    
// }

void printArray(int (*arr)[10], int size){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    
}

int main(){

    // int number[10];
    // for (int i = 0; i < 10; i++)
    // {
    //     number[i] = i+1;
    // }
    
    // printf("%d\n",number[9]);


    // int number = 10;
    // int *ptr = &number;
    // // *ptr = 100;
    // changeValue(&number);


    // printf("%d\n", number);

    // int arr[] = {1,2,3,4};

    // int *ptr = arr;

    // for (int i = 0; i < 4; i++)
    // {
    //     // printf("%d\n", arr[i]);
    //     printf("%d\n", *ptr++);
    // }
    
    // printArray(arr,4);

    int arr[10][10];

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            arr[i][j] = i+j;
        }
    }

    printArray(arr,10);

    // struct Student s[3];
    // for (int i = 0; i < 3; i++)
    // {
    //     printf("[%d]\n", i);
    //     scanf("%[^\n]", s[i].nim);
    //     getchar();
    //     scanf("%[^\n]", s[i].name);
    //     getchar();
    //     scanf("%d", &s[i].age);
    //     getchar();
    // }
    
    

    // printf("Data Mahasiswa\n");
    // for (int j = 0; j < 3; j++)
    // {
    //     printf("Nim : %s\n", s[j].nim);
    //     printf("Nama : %s\n", s[j].name);
    //     printf("Umur : %d\n", s[j].age);

    // }
    
    
    


    










    return 0;
}