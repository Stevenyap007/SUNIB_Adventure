#include <stdio.h>
#include <malloc.h>

struct BST
{
    int number;
    struct BST *left,*right;
};

struct BST *createNewNode(int number){
    struct BST *curr = (struct BST *)malloc(sizeof(struct BST));
    curr->number = number;
    curr->left = curr->right = NULL;
    return curr;
}

struct BST *insertNewNode(struct BST *curr,int number){
    if  (curr == NULL){
        return createNewNode(number);
    }

    if(number<curr->number){
        curr->left = insertNewNode(curr->left,number);
    }else if(number > curr->number){
        curr->right = insertNewNode(curr->right,number);
    }

    return curr;
}

void inOrder(struct BST *curr){
    if(curr != NULL){
        inOrder(curr->left);
        printf("Number : %d\n", curr->number);
        inOrder(curr->right);
    }
}

void preOrder(struct BST *curr){
    if(curr != NULL){
        printf("Number : %d\n", curr->number);
        preOrder(curr->left);
        preOrder(curr->right);
    }
}

void postOrder(struct BST *curr){
    if(curr != NULL){
        preOrder(curr->left);
        preOrder(curr->right);
        printf("Number : %d\n", curr->number);
    }
}

struct BST *searching(struct BST *curr, int search){
    if(curr == NULL)
        return curr;

    if(search < curr->number){
        return searching(curr->left, search);
    }else if ( search > curr->number){
        return searching(curr->right, search);
    } 

    return curr;  
}

struct BST *leftMostRightNode(struct BST *curr){
    struct BST *temp = curr->left;
    while(temp->right != NULL)
        temp = temp -> right;

    return temp;
}

struct BST *pop(struct BST *curr, int number){
    if (curr == NULL)
        return curr;
    
    if(number < curr->number){
        curr->left = pop(curr->left, number);
    }else if (number > curr->number){
        curr->right = pop(curr->right, number);
    }else{
        if(curr->left == NULL && curr->right == NULL){
            free(curr);
            return NULL;
        }else if(curr->left == NULL){
            struct BST *temp = curr->right;
            free(curr);
            return temp;
        }else if(curr->right == NULL){
            struct BST *temp = curr->left;
            free(curr);
            return temp;
        }else{
            struct BST *temp = leftMostRightNode(curr);
            curr->number = temp->number;

            curr->left = pop(curr->left,temp->number);
        }
    }

    return curr;
}

struct BST *update(struct BST*curr,int number, int updatedNumber){
    curr = pop(curr,number);
    return insertNewNode(curr,updatedNumber);
}

int  main(){
    struct BST *root = NULL;
    root = insertNewNode(root, 10);
    insertNewNode(root,5);
    insertNewNode(root,2);
    insertNewNode(root,6);
    insertNewNode(root,15);
    insertNewNode(root,11);


    // struct BST *curr = searching(root,12);
    // if(curr == NULL){
    //     printf("Not Found!\n");
    // }else{
    //     printf("Found!\n");
    // }

    // root = pop(root,6);
    // root = pop(root,10);
    update(root,10,16);
    inOrder(root);
    // puts("");
    // preOrder(root);
    // puts("");
    // postOrder(root);













    return 0;
}