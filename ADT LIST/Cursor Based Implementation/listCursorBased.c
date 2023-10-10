/* CURSOR BASED IMPLEMENTATION
    -> Implementation used by languages that do not support pointers
    -> Combination of Array & Linked List
    -> Basically uses ARRAY for its data structure
    but manipulates the elements like a LINKED LIST

*/

#include <stdio.h>
#define MAX 6

typedef struct{ //Definition of data type "node"
    char data;
    int next;
}node; 

typedef struct{ //Definition of data type "VirtualHeap"
    node Nodes[MAX];
    int avail;
}VirtualHeap;

typedef int LIST;


void initialize(VirtualHeap *VH, LIST *L);
void display(VirtualHeap VH, LIST L);
void insertFront(VirtualHeap *VH, LIST *L, char item);
int allocSpace(VirtualHeap *VH);
void insertLast(VirtualHeap *VH, LIST *L, char item);
void deleteItem(VirtualHeap *VH, LIST *L, char item);
void deallocSpace(VirtualHeap *VH, int temp);


int main(){
    VirtualHeap VH;
    LIST L;

    initialize(&VH, &L);
    insertFront(&VH, &L, 'F');
    insertFront(&VH, &L, 'O');
    insertFront(&VH, &L, 'I');
    insertFront(&VH, &L, 'D');
    insertLast(&VH, &L, 'A');
    insertLast(&VH, &L, 'Z');
    display(VH, L);
    printf("DELETED: ");
    deleteItem(&VH, &L, 'I');
    display(VH, L);


}
void initialize(VirtualHeap *VH, LIST *L){
    /*
        -> if the list is EMPTY then L = -1
        -> if the list is FULL then Avail = -1
    */
    *L = -1;
    int i;
    for(i=0;i<MAX-1;i++){
        VH->Nodes[i].next = i+1;
    }
    VH->Nodes[i].next = -1;
    VH->avail = 0; //Start of the Avail (DEPENDS ON THE GIVEN)
}
void display(VirtualHeap VH, LIST L){
    LIST trav;
    for(trav=L; trav!=-1; trav = VH.Nodes[trav].next){
        printf("%c\t", VH.Nodes[trav].data);
    }

}

/*Code below is shorter version

void insertFront(VirtualHeap *VH, LIST *L, char item){
    LIST temp = VH->avail;

    VH->Nodes[temp].data = item;
    VH->avail = VH->Nodes[temp].next;
    VH->Nodes[temp].next = *L;
    *L = temp;
}

*/

void insertFront(VirtualHeap *VH, LIST *L, char item){
    LIST temp;

    temp = allocSpace(VH); // equivalent to malloc
    if(temp!=-1){ // checks if full
        VH->Nodes[temp].data = item;
        VH->Nodes[temp].next = *L;
        *L = temp;
    }
    
}

int allocSpace(VirtualHeap *VH){
    /*
        Basically, returns the available index 
        and changes the available to the link of the available node

        returns -1 if list is full;
    */
    int retval = -1;

    if(VH->avail!=-1){
        retval = VH->avail;
        VH->avail = VH->Nodes[VH->avail].next;
    }
    return retval;

}
void insertLast(VirtualHeap *VH, LIST *L, char item){
    LIST *trav, temp;
    for(trav=L; *trav!=-1; trav = &VH->Nodes[*trav].next){} // traversal of Cursor Based Implementation
    if(VH->avail != -1){ // checks if full
        temp = allocSpace(VH); // equivalent to malloc
        VH->Nodes[temp].data = item;
        VH->Nodes[temp].next = *trav;
        *trav = temp;
    }
}


/* Code below is shorter version
void deleteItem(VirtualHeap *VH, LIST *L, char item){
    LIST *trav, temp;
    for(trav=L; *trav!=-1 && VH->Nodes[*trav].data!=item; trav = &VH->Nodes[*trav].next){}
    if(VH->avail!=1){
        temp = *trav;
        *trav = VH->Nodes[*trav].next;
        VH->Nodes[temp].next = VH->avail;
        VH->avail = temp;
    }
    
}
*/

void deleteItem(VirtualHeap *VH, LIST *L, char item){
    LIST *trav, temp;
    for(trav=L; *trav!=-1 && VH->Nodes[*trav].data!=item; trav = &VH->Nodes[*trav].next){} //traversal
    if(VH->avail!=1){ // checks if full
        temp = *trav;
        *trav = VH->Nodes[*trav].next;
        deallocSpace(VH, temp); // equivalent to free()
    }
    
}

void deallocSpace(VirtualHeap *VH, int temp){
    /*
        Basically changes the link of the current NODE to the current AVAIL

        then changes the current AVAIL to the value of the index

        It is still present in the memory but you can overwrite it
    */

    (VH)->Nodes[temp].next = (VH)->avail; // the link of the current node is the current avail
    (VH)->avail = temp; // avail is the temp index
}