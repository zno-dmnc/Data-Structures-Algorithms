#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  char elem;
  struct node *next;
}*Stack;

typedef enum {FALSE, TRUE} bool;

void init(Stack *s);
void push(Stack *s, char elem);
void pop(Stack *s);
char top(Stack s);
bool isEmpty(Stack s);
void insertBottom(Stack *s, char elem);
void display(Stack s);


int main () {
    Stack s;  
    init(&s);

    push(&s,'D');
    push(&s,'E');
    push(&s,'Z');
    push(&s,'D');
    display(s);
    pop(&s);
    display(s);
    insertBottom(&s, 'O');
    display(s);

    return 0;
}

void init(Stack *s){
    *s = NULL;
}

void push(Stack *s, char elem){
    Stack new = malloc(sizeof(struct node));
    new->elem = elem;
    new->next = *s;
    *s = new;
}

void pop(Stack *s){
    if(isEmpty(*s)==FALSE){
        Stack temp = *s;
        *s = temp->next;
        free(temp);
    }
}

char top(Stack s){
    return (isEmpty(s)!=TRUE) ? s->elem : '!';
}
bool isEmpty(Stack s){
    return (s==NULL) ? TRUE : FALSE;
}

void insertBottom(Stack *s, char elem){
    Stack hold;

    while(isEmpty(*s)==FALSE){
        push(&hold, top(*s));
        pop(s);
    }
    push(s, elem);
    while(isEmpty(hold)==FALSE){
        push(s, top(hold));
        pop(&hold);
    }
}

void display(Stack s){
    printf("Top->\t");
    while(s!= NULL){
        printf("%c\t", top(s));
        s = s->next;
    }
    printf("\n");
    system("pause");
    system("cls");
}