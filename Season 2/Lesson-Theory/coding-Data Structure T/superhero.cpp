#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define size 10

struct node{
    int key;
    char name[20];
}*superhero[size];

int hashFunction(char name[]){

    int sum  = 0;
    for (int i = 0; i < strlen(name); i++)
    {
        sum = sum+name[i];
    }
    return sum%size;
}

void insert(char name[]){
    struct node *newNode;
    int hashVal= hashFunction(name);
    newNode =(struct node *)malloc(sizeof(struct node));
    newNode->key = hashVal;
    strcpy(newNode->name,name);
    int i = hashVal;
    if (superhero[hashVal] == NULL){
        superhero[hashVal] = newNode;
    }else{
        while (i != size){
            if(superhero[i] == NULL){
                superhero[i] = newNode;
                superhero[i]->key = i;
                return;
            }else{
                i++;
                if(i>=size){
                    i = 0;
                }    
            }
        }printf("table is full..\n");
    }
}

void display(){
    for (int i = 0; i < size; i++)
    {
        if(superhero[i] != NULL){
            printf("| %d | %s\n", superhero[i]->key,superhero[i]->name);
        }
    }puts(" ");
    
}

void height_BTree(int node){
    int MAX_height = node - 1;
    int MIN_height = log(node);

    printf("MAX height of a binary tree is = %d\n",MAX_height);
    printf("MIN height of a binary tree is = %d\n",MIN_height);
}


int main(){

    // soal nomor 2 b
    // ironman (756), spiderman (963), superman (875), batman (627), thor (445), hulk (436), captain (736), joker (539)
    
    insert("ironman");
    insert("spiderman");
    insert("superman");
    insert("batman");
    insert("thor");
    insert("hulk");
    insert("captain");
    insert("joker");
    display();


    // Soal nomor 4 c
    height_BTree(5);




    return 0;
}