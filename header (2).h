#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct{

    void* dataPtr;
    struct node* link;

} NODE;

NODE* createNode(void* itemPtr){

    NODE* nodePtr;
    nodePtr=(NODE*)malloc(sizeof(NODE));
    nodePtr->dataPtr=itemPtr;
    nodePtr->link=NULL;
    return nodePtr;

}
#endif // HEADER_H_INCLUDED
