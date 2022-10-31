#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    int* newData;
    int* nodeData;

    NODE* node;

    newData=(int*)malloc(sizeof(int));
    *newData=7;
    node=createNode(newData);

    nodeData=(int*)node->dataPtr;

    printf("Data from node: %d\n",*nodeData);
    printf("Data from node: %d\n",&nodeData);
    printf("Data from node: %d\n",nodeData);

    return 0;
}
