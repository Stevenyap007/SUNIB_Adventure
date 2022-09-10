#include <stdio.h>
#include <malloc.h>

struct Node{
    int value;
    Node* left, *right;
    int height;
};

Node* newNode(int value){
    Node* temp= (Node*)malloc(sizeof(Node));
    temp->value =  value;
    temp->left = temp->right = NULL;
    temp->height = 1;

    return temp;
}

int max(int a,int b){
    return (a > b) ? a : b;
}

int getHeight(Node* node){
    // klo misalnya gaada data maka heightnya 0
    if(!node){
        return 0;
    } 

    return node->height;
}

int getBalance(Node* node){
    if(!node){
        return 0;
    }

    return getHeight(node->left) - getHeight(node->right);
}

Node* leftRotate(Node* root){
    Node* rightRoot = root->right;
    Node* leftSubtree = rightRoot->left;

    rightRoot->left = root;
    root->right = leftSubtree;

    root->height = max(getHeight(root->left),getHeight(root->right));
    rightRoot->height = max(getHeight(root->left), getHeight(root->right));

    return rightRoot;
}

Node* rightRotate(Node* root){
    Node* leftRoot = root->left;
    Node* rightSubtree = leftRoot->right;

    leftRoot->right = root;
    root->left = rightSubtree;

    root->height = max(getHeight(root->left),getHeight(root->right));
    leftRoot->height = max(getHeight(root->left), getHeight(root->right));

    return leftRoot;
}

Node* balanceTree(Node* root){
    root->height = 1 + max(getHeight(root->left),getHeight(root->right));
    int balance = getBalance(root);
    int leftBalance = getBalance(root->left);
    int rightBalance = getBalance(root->right);

    // kasus 1
    // LEFT LEFT -> right rotation
    if(balance > 1 && leftBalance >= 0){
        return rightRotate(root);
    }
    // kasus 2
    // LEFT RIGHT -> left rotation, baru right rotation
    else if(balance > 1 && leftBalance < 0 ){
        root->left = leftRotate(root);
        return rightRotate(root);
    }
    // kasus 3
    // RIGHT RIGHT -> left rotation
    else if(balance < -1 && rightBalance <= 0){
        return leftRotate(root);
    }
    // kasus 4
    // RIGHT LEFT -> right rotation, baru left rotation
    else if(balance < -1 && rightBalance > 0){
        root->right = rightRotate(root);
        return leftRotate(root);
    }

    return root;
}

Node* insert(Node* root,int value){
    if(!root){
        return newNode(value);
    }
    else if(value < root->value){
        // ke kiri
        root->left = insert(root->left, value);
    }
    else if (value > root->value){
        // ke kanan
        root->right = insert(root->right,value);
    }
    else{
        return balanceTree(root);
    }
}

void preOrder(Node* root){
    if(root){
        printf("%d - %d\n",root->value,root->right);
        preOrder(root->left);
        preOrder(root->right);
    }
}


bool searchValue(Node* root, int value){
    if (!root){
        puts("Value not Found");
        return false;
    }
    else if( value > root->value){
        return searchValue(root->right,value);
    }
    else if( value < root->value){
        return searchValue(root->left,value);
    }

    // berarti udah ketemu
    if(root->value == value)
        return true;
}

Node* getPredecessor(Node* root){
    // node paling kanan di subtree kiri root
    Node* curr = root->left;
    while (curr->right)
    {
        curr = curr->right;
    }
    return curr;
}

Node* getsucessor(Node* root){
    Node* curr = root->right;
    while (curr->left)
    {
        curr = curr->left;
    }
    return curr;
}


Node* deleteNode(Node* root, int value){
    if(!root)
        return NULL;

    else if( value > root->value){
        root->right = deleteNode(root->right, value);
    }
    else if(value < root->value){
        root->left = deleteNode(root->left, value);
    }
    else if( value == root->value){
        // kasus klo dia punya 1 anak
        if (!root->left || !root->right){
            Node* temp = NULL;
            // klo analnya yang ada si left, maka temp = left, klo gak maka temp = right

            temp = (root->left) ? root->left : root->right;
            free(root);
            root = NULL;

            return temp;
        }


        // kasus klo dia punya 2 anak
        // predecessor -> node paling kanan di bagian subtree kiri root
        // sucessor -> node paling kiri di bangian subtree kanan root
        Node* pred = getPredecessor(root);
        root->value = pred->value;

        // klo sucessor ganti deletenya si node kanan
        root->left = deleteNode(root->left, pred->value);
    }

    return balanceTree(root);
}

Node* popAll(Node* root){
    while (root)
    {
        root = deleteNode(root,root->value);
    }

    return root;
}


int main(){

    Node* root = NULL;
    root = insert(root,5);
    preOrder(root);
    root = insert(root,1);
    preOrder(root);
    root = insert(root,7);
    preOrder(root);
    root = insert(root,9);
    preOrder(root);
    root = insert(root,10);
    preOrder(root);

    return 9;
}