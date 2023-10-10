#include <stdio.h>
#include <stdlib.h>

#define size 5

typedef char *ElemArray, Elemtype;
typedef struct stackType{
    ElemArray E;
    int top;
} *Stack;

typedef enum {FALSE, TRUE} bool;

void initialize(Stack *S){
    (*S) = (struct stackType*)malloc(sizeof(struct stackType));
    (*S)->E = (Elemtype*)malloc(sizeof(Elemtype)*size);
    (*S)->top = size;
}

bool isFull(Stack S){
    return(S->top == 0)? TRUE: FALSE;
}

bool isEmpty(Stack S){
    return(S->top == size)? TRUE: FALSE;
}

Elemtype retrieveTop(Stack S){
    return(isEmpty(S) == FALSE)? S->E[S->top]: '!';
}

void push(Stack *S, char data){
    if(isFull(*S) == FALSE){
        (*S)->E[(--(*S)->top)] = data;
    }
} 

Elemtype pop(Stack *S){
    Elemtype retval = '0';
    if(isEmpty(*S) == FALSE){
        retval = (*S)->E[((*S)->top)];
        ++(*S)->top;
    }

    return retval;
}

int main(){
    Stack S;
    initialize(&S);
    bool full = isFull(S);

    bool empty = isEmpty(S);

    retrieveTop(S);

    push(&S, 'x');
    push(&S, 'g');
    push(&S, 's');

    printf("\nTop - %c", retrieveTop(S));

    Elemtype popped = pop(&S);
    printf("\nPopped - %c", popped);

    printf("\nTop - %c", retrieveTop(S));
}