#include <stdio.h>
#include <stdlib.h>

struct node {
int key;
struct node *left;
struct node *right;
} *root;

bool search(struct node *curr, int find){
//COMPLETE THE CODE!
    if(curr == NULL)
        return false;
    if(curr->key == find){
        return true;
    }

    if(find < curr->key){
        return search(curr->left, find);
    }else if ( find > curr->key){
        return search(curr->right, find);
    } 
}
int heightBinaryTree(struct node *node){
//COMPLETE THE CODE!
   if(node == NULL) return 0;
    else{
        int leftChild = heightBinaryTree(node->left);
        int rightChild = heightBinaryTree(node->right);
        if(leftChild > rightChild){
            return leftChild + 1;
        } else {
            return rightChild + 1;
        }
    }
}


