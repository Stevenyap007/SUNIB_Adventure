#include<stdio.h>
#include<malloc.h>

struct data{
    int number;
    struct data *left, *right;
    int height;
};

int max(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}

int getHeight(struct data *curr){
    if(curr == NULL){
        return 0;
    }
    return curr->height;
}

int updateHeight(struct data *curr){
    if(curr == NULL){
        return 0;
    }
    return 1 + max(getHeight(curr->left),getHeight(curr->right));
}

int getBalance(struct data *curr){
    if(curr == NULL){
        return 0;
    }
    return getHeight(curr->left) - getHeight(curr->right);
}

struct data *rightRotate(struct data *x){
    struct data *y = x->left;
    struct data *temp = y->right;

    y->right = x;
    x->left  = temp;

    x->height = updateHeight(x);
    y->height = updateHeight(y);

    return y;
}

struct data *leftRotate(struct data *x){
    struct data *y = x->right;
    struct data *temp = y->left;

    y->left = x;
    x->right  = temp;

    x->height = updateHeight(x);
    y->height = updateHeight(y);

    return y;
}

struct data *createNewData(int number){
    struct data *newData = (struct data*)malloc(sizeof(struct data));
    newData->number = number;
    newData->left = newData->right = NULL;
    newData->height = 1;
    return newData;
}

struct data *insertNewdata(struct data *curr,int number){
    if(curr == NULL){
        return createNewData(number);
    }

    if(number < curr->number){
        curr->left = insertNewdata(curr->left, number);
    }else if(number> curr->number){
        curr->right = insertNewdata(curr->right, number);
    }else{
        return curr;
    }

    curr->height = updateHeight(curr);

    int balance = getBalance(curr);

    // Left Left Case
    if(balance > 1 && number < curr->left->number){
        //right Rotate
        return rightRotate(curr);
    }
    // Right Right Case
    else if(balance < -1 && number > curr->right->number){
        return leftRotate(curr);
    }
    // Left Right Case
    else if(balance > 1 && number > curr->left->number){
        //Left Rotate
        curr->left = leftRotate(curr->left);
        //Right ROtate
        return rightRotate(curr);
    }
    // Right Left Case
    else if(balance < -1 && number > curr->right->number){
        //Left Rotate
        curr->right = leftRotate(curr->right);
        //Right ROtate
        return leftRotate(curr);
    }

    return curr;


}

struct data *searchNumber(struct data *curr,int search){
    if(curr==NULL){
        return curr;
    }

    if(search < curr->number){
        return searchNumber(curr->left,search);
    }else if (search > curr->number){
        return searchNumber(curr->right,search);
    }

    return curr;
}

void inOrder(struct data *curr){
    if(curr != NULL){
        inOrder(curr->left);
        printf("%d (%d)\n",curr->number,curr->height);
        inOrder(curr->right);
    }
}

int main(){

    struct data *root = NULL;
    root = insertNewdata(root,10);
    root = insertNewdata(root,20);
    root = insertNewdata(root,30);
    root = insertNewdata(root,40);
    root = insertNewdata(root,35);
    inOrder(root);
    
    if(searchNumber(root,5) == NULL){
        printf("Not Found\n");
    }else{
        printf("Found\n");
    }

    

    return 0;
}