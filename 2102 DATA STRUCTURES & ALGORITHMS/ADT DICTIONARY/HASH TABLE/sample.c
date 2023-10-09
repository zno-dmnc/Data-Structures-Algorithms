#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

typedef struct {
    unsigned long int idNumber;
    char FN[20];
    char LN[20];
    char MI;
    int year;
}Student;

typedef struct node{
    Student data;
    struct node *next;
}*NodePtr;

typedef NodePtr Dictionary[SIZE];


/*Open or external hashing: Allows sets in potentially unlimited space, no size limits;
CLosed or internal hashing: Uses fixed stoage space, imposes set size limits;*/

//Hash Tables and Open Hashing

void initialize(NodePtr dict[]);
void insert(Dictionary D, Student S);
int hash(int x);

int main(){

    Dictionary dict;
    Student s1={21104308, "Rob", "Lim", ' ', 4};

    initialize(dict);
    insert(dict, s1);

}

void initialize(NodePtr dict[]){
    int i;
    for(i=0;i<SIZE;i++){
        dict[i] = NULL;
    }
}

void insert(Dictionary D, Student S){
    int hashValue = hash(S.idNumber);
    printf("%u", hashValue);
    NodePtr *trav, new;
    for(trav = &D[hashValue];*trav!=NULL;trav = &(*trav)->next){}
    new = malloc(sizeof(struct node));
    new->data = S;
    new->next = NULL;
    *trav = new;
}

int hash(int x){
    int sum = 0;
    while(x>0){
        sum += x % 10; // Extract and add the last digit
        x /= 10; // Remove the last digit
    }
    return sum % SIZE; // Assuming B is defined elsewhere in your code

}