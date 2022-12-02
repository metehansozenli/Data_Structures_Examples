#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 50

typedef struct{
    char data[size];
    int top;
}stack;

stack s;


void push(char data){
    if(s.top==(size-1))
        printf("Stack Dolu!!\n");
    else
        s.data[++s.top]=data;
}

void pop(){
    if(s.top==-1)
        printf("Stack Bos!!\n");
    else
        s.top--;
}

void displayStack(){
    for(int i=s.top;i>-1;i--)
        printf(" %c\n",s.data[i]);
}

int main()
{
    s.top=-1;
    push('M');
    push('E');
    push('T');
    push('E');
    push('H');
    push('A');
    push('N');
    displayStack();
    pop();
    pop();
    pop();
    printf("\n\n");
    displayStack();

    return 0;
}
