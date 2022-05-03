#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define size 5

struct node{
    int key;
    char name[20];
    struct node *next;
}*head[size],*tail[size],*newNode,*ptr;

int hashFunction(char name[]){
    //urut abjad
    return tolower(name[0]) - 97;    
}

void insert(char name[]){
    int hashVal= hashFunction(name);
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->key = hashVal;
    strcpy(newNode->name,name);
    newNode->next = NULL;

    if(head[hashVal] == NULL){
        head[hashVal] = tail[hashVal] = newNode;
    }else{
        tail[hashVal]->next=newNode;
        tail[hashVal]=newNode;
    }
}

int search(char name[]){
    int hashVal = hashFunction(name);
    ptr = head[hashVal];

    if(head[hashVal] ==NULL){
        return -1;
    }else{
        while(ptr != NULL && strcmp(ptr->name,name)!=0){
            ptr = ptr->next;
        }
        if(strcmp(ptr->name,name)==0){
            return hashVal;
        }else{
            return -1;
        }
    }  
}

void Delete(char name[]){
    int res = search(name);
    struct node *prePtr;
    ptr=head[res];
    prePtr = head[res];

    if(res == -1){
        printf("Data not Found..\n");
    }else{
        while(ptr != NULL && strcmp(ptr->name,name)!=0){
            prePtr = ptr;
            ptr = ptr->next;
        }if(ptr==head[res]){
            head[res]=head[res]->next;
            free(ptr);
        }else if(ptr==tail[res]){
            prePtr->next=NULL;
            free(ptr);
            tail[res]=prePtr;
        }else{
            prePtr->next=ptr->next;
            free(ptr);
        }
    }
}

void deleteAll(){
    for (int i = 0; i < size; i++){
        if(head[i] != NULL){
            while(head[i] != NULL){
                ptr = head[i];
                head[i] = head[i]->next;
                free(ptr);
            }
        }
    }  
}

void display(){
    printf("Hash Value | \n");
    printf("---------------\n");
    for (int i = 0; i < size; i++){
        if(head[i]!=NULL){
            ptr=head[i];
            printf("%d | ",ptr->key);
            while(ptr != NULL){
                if(ptr->next != NULL){
                    printf("%s -> ",ptr->name);
                }else{
                    printf("%s ",ptr->name);
                }
                ptr = ptr->next;
            }printf("\n");
        }
    }
}

int main(){
    int choose,res;
    char name[20];
    do{
        system("cls");
        printf("hashing using chainingg\n");
        printf("============================\n\n");
        display();
        printf("\n1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Delete All\n");
        printf("5. Exit\n");
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
                deleteAll();
            case 5:
                exit(0);
                break;
            default:
                printf("Choose the correct menu!!\n");

        }
    }while (choose !=5);





    return 0;
}