#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int elem[5];
    int count;
}LIST;

void insertPos(LIST *L, int item, int pos){
    if(L->count!=0 && L->count<5){
        memmove(&L->elem[pos+1], &L->elem[pos], sizeof(int)*(L->count-pos));
        L->elem[pos] = item;
        L->count++;
    }
    else{
        L->elem[0] = item;
        L->count++;
    }
}
void insertFront(LIST *L, int item){
    if(L->count!=5){
        for(int i=L->count;i>0;i--){
            L->elem[i] = L->elem[i-1];
        }

        L->elem[0] = item;
        L->count++;
    }
    
}

void print(LIST L){
    for(int i=0;i<L.count;i++){
        printf("%d\t", L.elem[i]);
    }
}

int main(){
    LIST *L = NULL;
    L = malloc(sizeof(LIST));
    L->count = 0;
    insertFront(L, 5);
    insertFront(L, 2);
    insertFront(L, 1);
    insertFront(L, 6);
    insertPos(L, 10, 2);
    print(*L);


}