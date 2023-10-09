#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int *elem;
    int count;
}LIST;

void insertPos(LIST *L, int item, int pos){
    if(L->count!=0 && L->count<5){
        L->count++;
        L->elem = realloc(L->elem, sizeof(int)*L->count);
        memmove(&L->elem[pos+1], &L->elem[pos], sizeof(int)*(L->count-pos));
        L->elem[pos] = item;
    }
    else{
        L->elem = realloc(L->elem, sizeof(int)*(++L->count));
        L->elem[0] = item;
    }
}
void insertFront(LIST *L, int item){
    if(L->count<5&&L->count!=0){
        L->elem = realloc(L->elem, sizeof(int)*(++L->count));
        memmove(&L->elem[1], &L->elem[0], sizeof(int)*(L->count-1));
        L->elem[0] = item;
    }
    else{
        L->elem = realloc(L->elem, sizeof(int)*(++L->count));
        L->elem[0] = item;
    }
    
}

void print(LIST L){
    for(int i=0;i<L.count;i++){
        printf("%d\t", L.elem[i]);
    }
}

LIST* initialize(){
    LIST *L = malloc(sizeof(LIST));
    L->count = 0;
    return L;
}

int main(){
    
    LIST *L = NULL;
    L = initialize();
    L->elem = malloc(sizeof(int)*L->count);

    insertFront(L, 3);
    insertFront(L, 9);
    insertFront(L, 5);
    insertPos(L, 10, 1);
    print(*L);

}