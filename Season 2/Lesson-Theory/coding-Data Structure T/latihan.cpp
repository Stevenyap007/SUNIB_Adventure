#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define size 120

struct node{
    char id[10];
    char name[100];
    int age;
    char jobDesk[100];
    char researchName[100];
    char researchDesc[100];
    int MemberCount;
    int toolUsed;
    struct node* next;
    struct node* prev;
}*table[size],*newNode,*ptr;

node* scan_data(){
    node *newNode = (struct node*)malloc(sizeof(node));

    do{
        printf("Insert your leader name [min 5 char]: ");
        scanf(" %[^100\n]", newNode->name);
    } while(strlen(newNode->name) < 5);

    do{
        printf("Insert your leader age [25 - 60]: ");
        scanf("%d", &newNode->age);
    } while(newNode->age < 25 || newNode->age > 60);

    do{
        printf("Insert your jobdesk [Gather Sample | Researching Sample | Documentation]: ");
        scanf(" %[^100\n]", newNode->jobDesk);
    } while((strcmp(newNode->jobDesk, "Gather Sample") != 0) && (strcmp(newNode->jobDesk, "Researching Sample") != 0) && (strcmp(newNode->jobDesk, "Documentation") != 0));

    do{
        char temp[100];
        printf("Input research name [ends with \"Research\"]: ");
        scanf(" %[^100\n]", temp);
        bool flag = false;
        for(int i = 0; temp[i] != '\0'; i++) {
            if(temp[i] == ' ') {
                flag = true;
                break;
                }
            }
            if(flag) {
                char *lastWord = strrchr(temp, ' ') + 1;
                if(strcmp(lastWord, "Research") == 0)
                strcpy(newNode->researchName, temp); 
                break;
                }
    }while(true);

    do{
        printf("Input research description [length between 10-50]: ");
        scanf(" %[^100\n]", newNode->researchDesc);
    }while(strlen(newNode->researchDesc) < 10 || strlen(newNode->researchDesc) > 50);

    do{
        printf("Input amount of research members [more than 5]: ");
        scanf("%d", &newNode->MemberCount);
    }while(newNode->MemberCount < 5);

    do{
        printf("Insert amount of tools that has been used [more than 0]: ");
        scanf("%d", &newNode->toolUsed);
    } while(newNode->toolUsed < 1);
    
    srand(time(0));
    int d = rand() % 9 + 0;
    int m = rand() % 9 + 0;
    int y = rand() % 9 + 0;
    sprintf(newNode->id, "RE%d%d%d", d, m, y);

    printf("Successfully Added New Product\n");
    newNode->next = NULL;
    return newNode;
}

int hashFunction(char id[]){
    int sum = 0;
    for (int i = 0; i < strlen(id); i++)
    {
        sum += id[i];
    }
    return sum%size;
}

void insert(){
    node *toInsert = scan_data();
    int idx = hashFunction(toInsert->id);

    if(table[idx] == NULL){
        table[idx] = toInsert;
    } else {
        node *curr = table[idx];

        while(curr != NULL){
            curr = curr->next;
        }

        curr = toInsert;
    }
}


int display(){
    int count = 0;
    for(int i = 0; i<size; i++)
    {
        if(table[i] != NULL){
            node *curr = table[i];
            count = 1;
            while(curr != NULL){
                if(curr->next != NULL){
                    printf("Research Number %d \n", hashFunction(curr->id));
                    printf("Research ID: %s\n", curr->id );
                    printf("Research Name: %s\n", curr->researchName);
                    printf("Research Description: %s\n", curr->researchDesc);
                    printf("Leader Name: %s\n", curr->name);
                    printf("Leader Job : %s\n", curr->jobDesk);
                    printf("Research Member: %d\n", curr->MemberCount);
                    printf("Tools used: %d\n", curr->toolUsed);
                    printf("==========================================================\n");
                }else{
                    printf("Research Number %d \n", hashFunction(curr->id));
                    printf("Research ID: %s\n", curr->id );
                    printf("Research Name: %s\n", curr->researchName);
                    printf("Research Description: %s\n", curr->researchDesc);
                    printf("Leader Name: %s\n", curr->name);
                    printf("Leader Job : %s\n", curr->jobDesk);
                    printf("Research Member: %d\n", curr->MemberCount);
                    printf("Tools used: %d\n", curr->toolUsed);
                }
            curr = curr->next;
            }         
        }
    }
    if(count == 0){
        printf("There is no research\n");
        printf("Press enter to continue...\n");
        return -1;
    }
}

void Delete(){
    if(display() == -1){
        return;
    }else{
        char temp[100];
        printf("Input ID you want to delete: ");
        scanf("%s",temp);
        int idx = hashFunction(temp);
        if(table[idx] != NULL && strcmp(table[idx]->id, temp) == 0){
            node *toDelete = table[idx];
            free(toDelete);
            toDelete = NULL;
            printf("Sucessfully deleted.");
        }else{
            node *curr = table[idx], *prev = NULL;
            while(curr != NULL && strcmp(curr->id, temp) != 0){
                prev = curr;
                curr = curr->next;
            }
            if(curr != NULL && strcmp(curr->id, temp) == 0){
                prev->next = curr->next;
                free(curr);
                curr = NULL;
                printf("Sucessfully deleted.");
            }else{
                printf("NOT FOUND! Can't delete\n");
            }
        }
        
    }      
}





int main(){
    int choose,res;
    do{
    system("cls");
    printf("Scitek Lab\n");
    printf("============\n");
    printf("1. Add Research\n");
    printf("2. View Research\n");
    printf("3. Delete Research\n");
    printf("4. Exit\n");
    printf("Option: ");
    scanf("%d", &choose);
    switch(choose){
            case 1:
                insert();
                puts("");
                getchar();
                getchar();
                break;
            case 2:
                display();
                getchar();
                getchar();
                break;
            case 3:
                Delete();
                getchar();
                getchar();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Choose the correct menu!!\n");
        }
    }while (choose !=5);

    
    return 0;
}