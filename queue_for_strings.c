#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 50

typedef struct node{
    char data[MAX];
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

void enqueue(QUEUE *q,char data[]){
    node* newNode=(node*)malloc(sizeof(node));
    strcpy(newNode->data,data);
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
void emptyQueue(QUEUE *q){
    node* temp = q->front;
    while(temp != NULL){
        dequeue(q);
        temp=temp->next;
    }
}

void displayQueue(QUEUE* q){
    node* temp = q->front;
    if(temp == NULL)
        printf("Kuyruk bos veya bulunamadi!!\n");
    else{
        while(temp != NULL){
            printf("%s ",temp->data);
            temp=temp->next;
        }
    }
}

bool isSymbol(char str[]){//stringin + - * veya / olup olmadigini kontrol eden fonksiyon
    bool a=(!strcmp(str,"+"))?true:(!strcmp(str,"-"))?true:(!strcmp(str,"*"))?true:(!strcmp(str,"/"))?true:false;
        return a;
}

void calculatePrefix(char str[][MAX],int n){

    char buffer [sizeof(int)*8+1];//itoi fonksiyonu icin gerekli(itoi -> integer ifadeyi stringe cevirme)
    int numberCount=0,symbolCount=0,k=0,sayac=1;
    QUEUE *q= createQueue();
    QUEUE *q2= createQueue();
    node *temp;

    for(int i=0;i<n;i++){//string olarak alinan prefix ifade kuyruga ekleniyor
        enqueue(q,str[i]);
        if(isSymbol(str[i])==true)//ekleme islemi yapilirken ayni sirada sembol sayisi ve sayilarin sayisi bulunuyor
            symbolCount++;
        else
            numberCount++;
    }

    if(numberCount-symbolCount==1){//hesaplanabilir bi prefix ifade icin sayilarin sayisi sembollerden 1 fazla olmalidir
        printf("Prefix Ifade\n");displayQueue(q); printf("\n\n");

        while(q->count != 1){//kuyurukta tek bir ifade kalana kadar calisan dongu
            printf("%d. Tarama\n",sayac++);
            temp= q->front;

            while(k<=q->count){//her bir tarama adimi
                k=0;
                //prefix ifadeyi hesaplayan kosullar
                if(isSymbol(temp->data)==true && isSymbol(temp->next->data)== false && isSymbol(temp->next->next->data)== false ){
                    dequeue(q);//sembol kuyruktan cikariliyor

                    if(!strcmp(temp->data,"+")){
                        enqueue(q2,itoa(atoi(temp->next->data)+atoi(temp->next->next->data),buffer,10));
                    }
                    else if(!strcmp(temp->data,"-")){
                        enqueue(q2,itoa(atoi(temp->next->data)-atoi(temp->next->next->data),buffer,10));
                    }
                    else if(!strcmp(temp->data,"*")){
                        enqueue(q2,itoa(atoi(temp->next->data)*atoi(temp->next->next->data),buffer,10));
                    }
                    else if(!strcmp(temp->data,"/")){
                        enqueue(q2,itoa(atoi(temp->next->data)/atoi(temp->next->next->data),buffer,10));

                    }
                    dequeue(q);dequeue(q);//sayilar kuyruktan cikariliyor
                    temp= q->front;
                }
                else{//eger ki isaretten sonra iki adet sayi yoksa durumu
                    enqueue(q2,temp->data);
                    dequeue(q);
                    temp=q->front;
                }
            k++;
            }

        displayQueue(q2);printf("\n");
        emptyQueue(q);//q kuruguna tarama sonucu elde edilen yeni degerlerin atanmasi icin bosaltiliyor

        while(q2->count!=0){//q kuruguna q2 kuyrugundaki elemanlar ekleniyor
            enqueue(q,q2->front->data);
            dequeue(q2);
            }

        printf("\n");
        }

    }
    else
        printf("Gecersiz girdi!!\n");
}

int main()
{
    printf("----------------------------------------------\n");
    char str1[13][MAX]={"-","+","*","9","+","2","8","*","+","4","8","6","3"};
    calculatePrefix(str1,13);
    printf("----------------------------------------------\n");

    char str2[7][MAX]={"*","+","5","7","-","3","2"};
    calculatePrefix(str2,7);
    printf("----------------------------------------------\n");

    char str3[9][MAX]={"/","+","8","9","3","17","+","3","8"};
    calculatePrefix(str3,9);
    printf("----------------------------------------------\n");
    return 0;
}
