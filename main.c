#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
    int balance;

}node;


node* rotateLeft(node* root){

    node* temp = root->right;
    root->right=temp->left;
    temp->left=root;
    root=temp;
    return root;
}

int main()
{
    return 0;
}
