#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    char productName[100];
    long price;
    int quantity;
    struct Product *next, *prev;
}*head, *tail;

struct Product *createNewProduct(char productName[],long price,int quantity){
    struct Product *newProduct = (struct Product *)malloc(sizeof(struct Product));
    strcpy(newProduct->productName, productName);
    newProduct->price  = price;
    newProduct->quantity = quantity;
    newProduct->next = newProduct->prev = NULL;

    return newProduct;
}

void pushHead(char productName[],long price,int quantity){
    struct Product *curr  = createNewProduct(productName, price, quantity);


    if (head == NULL)
    head = tail = curr;
    else {
        curr->next = head;
        head->prev = curr;
        head = curr;
    }

}

void pushTail(char productName[],long price,int quantity){
    struct Product *curr  = createNewProduct(productName, price, quantity);


    if (head == NULL)
    head = tail = curr;
    else {
        tail->next = curr;
        curr->prev = tail;
        tail = curr;
    }

}

void pushMid(char productName[],long price,int quantity){
    struct Product *curr  = createNewProduct(productName, price, quantity);


    if (head == NULL)
    head = tail = curr;
    else {
        if(strcmp(head->productName, productName) >= 0)
            pushHead(productName,price,quantity);
        else if(strcmp(tail->productName, productName) <= 0)
            pushTail(productName,price,quantity);
        else{
            struct Product *temp = head->next;
            while(strcmp(temp->productName,productName) < 0){
                    temp = temp->next;
            }
            curr->next = temp;
		    curr->prev = temp->prev;
		    temp->prev->next = curr;
		    temp->prev = curr;
        }
        

    }

}

void popHead(){
    if(head  != NULL){
        if(head == tail){
            free(head);
            head = tail =NULL;
        }else{
            head = head->next;
            free(head->prev);
            head->prev = NULL;
        }
        
    }
}

void popTail(){
    if(head  != NULL){
        if(head == tail){
            free(head);
            head = tail =NULL;
        }else{
            tail = tail->prev;
            free(tail->next);
            head->next = NULL;
        }
        
    }
}

void popMid(char productName[]){
    if(head  != NULL){
        if(head == tail){
            if(strcmp(head->productName, productName) == 0){
                free(head);
                head = tail =NULL;
            }
        }else{
            if(strcmp(head->productName, productName) == 0 ){
                popHead();
            }else if(strcmp(tail->productName, productName) == 0 ){
                popTail();
            }else{
                struct Product *temp = head->next;
                while(temp != tail && strcmp(temp->productName,productName) != 0){
                    temp = temp->next;
                }
                if(strcmp(temp->productName, productName) == 0){
                    temp->next->prev = temp->prev;
                    temp->prev->next = temp->next;

                    free(temp);
                }
            }
            
        }
        
    }

}

struct Product *search(char productName[]){
    if (head != NULL){
        struct Product *temp = head;
        while(temp != tail && strcmp(temp->productName,productName) != 0){
            temp = temp->next;
        }

        if(strcmp(temp->productName,productName) == 0){
            return temp;
        }
    }

    return NULL;
}


void printAll(){
    struct Product *curr = head;
    while(curr != NULL){
        printf("Product Name : %s\n", curr->productName);
        printf("Product Price : %ld\n", curr->price);
        printf("Product Quantity : %d\n\n", curr->quantity);
        curr = curr->next;
    }
}

int main(){

    pushMid("C",1000,10);
    pushMid("E",1000,10);
    pushMid("A",1000,10);
    pushMid("D",1000,10);
    pushMid("B",1000,10);

    
    // popTail();
    popMid("C");
    popMid("A");
    popMid("E");
    popMid("E");
    // popMid("B");
    // popMid("D");
    printAll();


    // struct Product *p = search("A");
    // if(p == NULL){
    //     printf("data notfound\n");
    // }else{
    //     printf("Product Name : %s\n", p->productName);
    //     printf("Product Price : %ld\n", p->price);
    //     printf("Product Quantity : %d\n\n", p->quantity);
    // }

    







    return 0;
}