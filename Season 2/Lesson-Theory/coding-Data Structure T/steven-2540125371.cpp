#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define size 30

struct node{
    int tagId;
    char username[100];
    char email[100];
    char phonenumber[15];
    struct node *next;
    struct node *prev;
}*table[size],*newNode;

int periksa(char nama[]){
    for (int i = 0; i < size; i++)
    {
        if(nama[i] < 65 || nama[i] > 122){
            return -1;
            break;
        }
    }
    return 0;
}

node * scan_data(){
    newNode = (struct node*)malloc(sizeof(struct node));
    int id = 0;
    do{
        printf("Enter your Username [ 1 - 20 char and not with special character ]: ");
        scanf("%s",newNode->username);
    }while(periksa(newNode->username) == -1);
    
    do{
        char temp[100];
        printf("Enter your email [ ends with '.com' ] : ");
        scanf("%s",temp);
        bool flag = false;
        for (int i = 0; i < temp[i]!= '\0'; i++)
        {
            if(temp[i] == ' '){
                flag = true;
                break;
            }
        }
        if(flag) {
            char *lastword =  strrchr(temp, ' ') + 1;
            if(strcmp(lastword, ".com")==0){
                strcpy(newNode->username,temp);
                break;
            }
        }
    }while(true);

    do{
        printf("Enter your phone number [ starts with '0' ] : ");
        scanf("%s",newNode->phonenumber);
    }while(newNode->phonenumber[0] != '0');

    if(id <= size){
        id++;
        newNode->tagId=id;
    }
    
    newNode->prev = NULL;
    newNode->next = NULL;
}

int hashFunction(char name[]){
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += name[i];
    }
    return sum%size;
}

void insert(){
    node *toInsert = scan_data();
    int idx =  hashFunction(toInsert->username);

    if(table[idx] == NULL ){
        table[idx] = toInsert;
    }else{
        node *curr = table[idx];
        while(curr != NULL){
            curr = curr->next;
        }
        curr = toInsert;
    }
}

void Delete(){
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if(table[i] != NULL){
            node *curr = table[i];
            count = 1;
            while(curr != NULL){
                if(curr->next){
                    printf("Tag ID : %d\n",curr->tagId);
                    printf("Username : %s\n",curr->username);
                    printf("Email : %s\n",curr->email);
                    printf("Phone Number : %s\n",curr->phonenumber);
                    printf("======================================\n");
                }else{
                    printf("Tag ID : %d\n",curr->tagId);
                    printf("Username : %s\n",curr->username);
                    printf("Email : %s\n",curr->email);
                    printf("Phone Number : %s\n",curr->phonenumber);
                }
                curr = curr->next;
            }
        }
    }
    if(count == 0){
        printf("No accout yet!\n\n");
        printf("Create account first!! \n");
        printf("Press enter to continue");
        return;
    }else{
        int temp;
        int idx;
        printf("Enter your tagID to be deleted: \n");
        scanf("%d",temp);
        for (int i = 0; i < size; i++)
        {
           if(table[i]->tagId == temp){
               idx = hashFunction(table[i]->username);
           }
        }
        
        if(table[idx] != NULL && table[idx]->tagId == temp){
            node *todelete = table[idx];
            
            printf("Account that was deleted\n");
            printf("------------------------\n");
            printf("Tag ID : %d\n",todelete->tagId);
            printf("Username : %s\n",todelete->username);
            printf("Email : %s\n",todelete->email);
            printf("Phone Number : %s\n",todelete->phonenumber);
            free(todelete);
            todelete = NULL;
            printf("\n\nPress enter to continue..\n");
        }else{
            node *curr = table[idx], *prev = NULL;
            while(curr != NULL && curr->tagId != temp){
                prev = curr;
                curr = curr->next;
            }
            if(curr != NULL && curr->tagId != temp == 0){
                prev->next = curr->next;
                free(curr);
                curr = NULL;
                printf("Account that was deleted\n");
                printf("------------------------\n");
                printf("Tag ID : %d\n",curr->tagId);
                printf("Username : %s\n",curr->username);
                printf("Email : %s\n",curr->email);
                printf("Phone Number : %s\n",curr->phonenumber);
                printf("\n\nPress enter to continue..\n");
            }else{
                printf("tag ID not found..\n");
                printf("\n\nPress enter to continue..\n");
            }
        }
        
        
    }
    

}

int main(){
int choose;
do
{
    // system("cls");
    printf("Biscord Gaming!!\n");
    printf("------------------\n");
    printf("1. Register new User\n");
    printf("2. Delete user\n");
    printf("3. Exit\n");
    printf("Choose : ");
    scanf("%d",&choose);
    switch (choose){
    case 1:
        insert();
        getchar();
        getchar();
        break;
    case 2:
        Delete();
        getchar();
        getchar();
        break;
    case 3:
        exit(0);
        break;
    default:
        printf("Choose the correct menu!!\n");
    }
} while (choose != 4);




    return 0;
}