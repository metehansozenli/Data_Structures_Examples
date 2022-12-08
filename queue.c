#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef struct node{
    int data;
    struct node* next;

}node;

typedef struct{
    int count;
    node* front;
    node* rear;

}QUEUE;

QUEUE *createQueue(){

    QUEUE *queue=(QUEUE*)malloc(sizeof(QUEUE));
    if(queue!=NULL){
        queue->front=NULL;
        queue->rear=NULL;
        queue->count=0;
    }
    return queue;
}

void dequeue(QUEUE *q){
    if(q->count==0)
        printf("Kuyruk Bos!\n");
    else {
        node *deleteN=q->front;

        if(q->count==1){
            q->front=NULL;
            q->rear=NULL;
        }
        else
            q->front=q->front->next;
        q->count--;
        free(deleteN);
    }
}

void enqueue(QUEUE *q,int data){
    node* newNode=(node*)malloc(sizeof(node));
    newNode->data=data;
    newNode->next=NULL;

    if(q->count==MAX)
        printf("Kuyruk Dolu!\n");
    else{
        if(q->front == NULL)
            q->front=newNode;
        else
            q->rear->next=newNode;

        q->rear=newNode;
        (q->count)++;//queueye eleman ekledikten sonra queuede bulunan counteri artirir.
    }
}

void displayQueue(QUEUE* q){
    node* temp = q->front;
    if(temp == NULL)
        printf("Kuyruk bos veya bulunamadi!!\n");
    else{
        while(temp != NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}

int main()
{
    QUEUE * q1 = createQueue();
    QUEUE * q1 = createQueue();
    QUEUE * q1 = createQueue();

    enqueue(q1,2);
    enqueue(q1,234);
    enqueue(q1,65);
    enqueue(q1,3);
    dequeue(q1);
    displayQueue(q1);
    return 0;
}
