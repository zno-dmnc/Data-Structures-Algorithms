#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char elem;
    struct node* next;
}*NodePtr;

typedef struct{
    NodePtr front;
    NodePtr rear;
}*Queue, queue;


void initialize(Queue *q);
void display(Queue q);
void enqueue(Queue q, char elem);
void dequeue(Queue q);
void search();
int main(){
    Queue q;
    initialize(&q);
    enqueue(q, 'a');
    enqueue(q, 'z');
    enqueue(q, 'n');
    display(q);
    dequeue(q);
    printf("\n\n");
    display(q);
}

void initialize(Queue *q){
    Queue temp = malloc(sizeof(queue));
    temp->front = NULL;
    temp->rear = NULL;
    *q = temp;
}

void enqueue(Queue q, char elem){
    // NodePtr temp = malloc(sizeof(struct node));
    // temp->elem = elem;
    NodePtr temp = malloc(sizeof(struct node));
    if(temp!=NULL){
        temp->elem = elem;
        temp->next = NULL;
    } 

    if((q)->front!=NULL){
        (q)->rear->next = temp;
        (q)->rear = temp; 
    }
    else{
        (q)->front = temp;
        (q)->rear = temp;
    }

}
void dequeue(Queue q){
    NodePtr temp;
    if((q)->front!=NULL){
        temp = q->front;
        q->front = q->front->next;
        if(q->front == NULL){
            q->rear = NULL;
        }
        free(temp);
    }
}

void display(Queue q){
    NodePtr trav = q->front;
    while(trav!=NULL){
        printf("%c\t", trav->elem);
        trav = trav->next;
    }

    printf("\nFRONT: %C", q->front->elem);
    printf("\nREAR: %c", q->rear->elem);
}