#include<stdio.h>
#include"stacks1.h"
int init(struct stacks1** sPtrPtr){
    *sPtrPtr=(struct stacks1*)malloc(sizeof(struct stacks1));
    if (*sPtrPtr==NULL){
        return 0;
    }
    (*sPtrPtr)->top=NULL;
    return 1;
}
int isEmpty(struct stacks1* sPtr){
    if (sPtr->top==NULL){
        return 1;
    }
    return 0;
}
int isFull(struct stacks1* sPtr){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    if (temp==NULL){
        return 1;
    }
    free(temp);
    return 0;
}
int push(struct stacks1* sPtr, type data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    if (newNode==NULL){
        return 0;
    }
    newNode->data=data;
    newNode->next=sPtr->top;
    sPtr->top=newNode;
    return 1;
}
int peek(struct stacks1* sPtr, type* dataPtr){
    if (isEmpty(sPtr)){
        return 0;
    }
    (*dataPtr)=sPtr->top->data;
    return 1;
}
int pop(struct stacks1* sPtr, type* dataPtr){
    if (isEmpty(sPtr)){
        return 0;
    }
    *dataPtr=sPtr->top->data;
    struct Node* temp=sPtr->top;
    sPtr->top=sPtr->top->next;
    free(temp);
    return 1;
}
int destroy(struct stacks1** sPtrPtr){
    type data;
    while(!isEmpty(*sPtrPtr)){
        pop(*sPtrPtr,&data);
    }
    free(*sPtrPtr);
    *sPtrPtr=NULL;
    return 1;
}
