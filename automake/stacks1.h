#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
#define type int
struct Node{
    type data;
    struct Node* next;
};
struct stacks1{
    struct Node* top;
};
int init(struct stacks1**);
int push(struct stacks1*, type);
int pop(struct stacks1*, type*);
int peek(struct stacks1*, type*);
int isEmpty(struct stacks1*);
int isFull(struct stacks1*);
int destroy(struct stacks1**);
