#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node* leftNode;
    struct node* rightNode;
};
typedef struct node Node;


bool isLeaf(Node* node){
    if(node->leftNode==NULL && node->rightNode==NULL)
        return true;
    else
        return false;
}

void addNode(Node* root,int data){
    Node* newNode=(Node*)malloc(sizeof(Node));
    Node* parent;
    Node* iter;
    int flag=0;
    newNode->data=data;
    newNode->leftNode=NULL;
    newNode->rightNode=NULL;

    iter=root;

    while(iter!=NULL){
        parent=iter;
        if(data > iter->data)
            iter=iter->rightNode;
        else if(data < iter->data)
            iter=iter->leftNode;
        else{
            flag=6;
            break;
        }
    }

    if(flag!=0)
        printf("Node already exists!!\n");
    else if(data > parent->data)
        parent->rightNode=newNode;
    else
        parent->leftNode=newNode;
}

void deleteNode(Node* root,int data){
    Node* iter=root;
    Node* search; Node* prev;
    int flag=0;

    while(iter!=NULL){

        if(data > iter->data){
            prev=iter;
            iter=iter->rightNode;
        }
        else if(data < iter->data){
            prev=iter;
            iter=iter->leftNode;
        }
        else if(iter->data==data){//dugum bulundu
            flag=6;
            search=iter;
            break;
        }
    }

    if(flag==0){
        printf("Node not found!!\n");
        return NULL;
    }
    if(isLeaf(search)){
            if(prev->leftNode==search)
                prev->leftNode=NULL;
            else
                prev->rightNode=NULL;
        printf("%d (l)silindi\n",search->data);free(search);

    }
    else if(search->leftNode!=NULL && search->rightNode!=NULL){//dugum iki cocuga sahipse
        //not finished yet!!
    }
    else{
        if(search->leftNode!=NULL){
            prev->rightNode=search->leftNode;
        }
        else
            prev->leftNode=search->rightNode;
        printf("%d silindi\n",search->data);free(search);
    }
}

Node* min(Node* root){
    Node* iter=root;
    while(iter!=NULL){
            if(iter->leftNode == NULL)
                return iter;
            iter=iter->leftNode;
    }
}
Node* max(Node* root){
    Node* iter=root;
    while(iter!=NULL){
            if(iter->rightNode == NULL)
                return iter;
            iter=iter->rightNode;
    }
}

void inorder(Node* root)
{
    if (root != NULL) {
        inorder(root->leftNode);
        printf("%d ",root->data);
        inorder(root->rightNode);
    }
}

int main()
{
    Node* root=(Node*)malloc(sizeof(Node));
    root->data=30;
    root->leftNode=NULL;
    root->rightNode=NULL;

    addNode(root,36);
    addNode(root,45);
    addNode(root,10);
    addNode(root,15);
    addNode(root,28);
    addNode(root,16);
    addNode(root,9);
    addNode(root,31);
    addNode(root,57);
    addNode(root,87);
    addNode(root,317);
    addNode(root,61);
    //deleteNode(root,9);

    inorder(root);
    printf("Min:%d, Max:%d\n",min(root)->data,max(root)->data);

    return 0;
}
