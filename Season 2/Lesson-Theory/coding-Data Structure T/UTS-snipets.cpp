#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 9

struct hashNode{
    char name[20];
    int key;
};
int hashFunction(char name[]){
    //COMPLETE THE CODE
    int sum = 0;
    for (int i = 0; i < strlen(name); i++)
    {
        sum += name[i];
    }
    return sum%SIZE;
}
