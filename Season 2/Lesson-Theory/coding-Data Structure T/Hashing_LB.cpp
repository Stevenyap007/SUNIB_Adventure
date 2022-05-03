#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 5

struct node{
    int key;
    char name[20];
}*tabel[size];

void init(){
    for (int i = 0; i < size; i++)
    {
        tabel[i] = NULL;
    }
    
}

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
    int i = hashVal+1;
    if (tabel[hashVal] == NULL){
        tabel[hashVal] = newNode;
    }else{
        while (i != size){
            if(tabel[i] == NULL){
                tabel[i] = newNode;
                tabel[i]->key = i;
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

int search(char name[]){
    int hashVal = hashFunction(name);
    int i = hashVal+1;
    if(hashVal == NULL){
        return -1;
    }else if(strcmp(tabel[hashVal]->name,name)==0){
        return hashVal;  
    }else{
        while (i != hashVal){
            if (strcmp(tabel[i]->name,name)==0){
                return i;
            }else if(tabel[i] == NULL){
                i++;
                i=i%size;
                continue;
            }else{
                i++;
                i=i%size;
            }
        }
    }return -1;
}

void Delete(char name[]){
    int res = search(name);
    if(res==-1){
        printf("Name not Found..\n");
    }else{
        free(tabel[res]);
        tabel[res] == NULL;
    }
}

void display(){
    for (int i = 0; i < size; i++)
    {
        if(tabel[i] != NULL){
            printf("|| %d || %s\n", tabel[i]->key,tabel[i]->name);
        }
    }puts(" ");
    
}

int main(){
    int choose,res;
    init ();
    char name[20];

    do{
        system("cls");
        printf("hashing using Linear Probing\n");
        printf("============================\n\n");
        display();
        printf("\n1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4.Exit\n");
        printf("Choose 1 menu: ");
        scanf("%d",&choose);
        getchar();

        switch(choose){
            case 1:
                printf("Insert Name: ");
                gets(name);
                insert(name);
                getchar();
                break;
            case 2:
                printf("Search Name: ");
                gets(name);
                res = search(name);
                if (res == -1){
                    printf("Name not Found\n");
                }else{
                    printf("Name %s found at index [%d]",name,res);
                }
                getchar();
                break;
            case 3:
                printf("Delete Name ");
                gets(name);
                Delete(name);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Choose the correct menu!!\n");

        }
    }while (choose !=4);





    return 0;
}

