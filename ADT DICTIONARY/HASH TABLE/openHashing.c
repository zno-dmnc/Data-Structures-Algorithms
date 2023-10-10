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

void initialize(Dictionary dict);
void insert(Dictionary D, Student S);
int hash(int x);
void display(Dictionary D);

int main(){

    Dictionary dict;
    Student s1={21104308, "Rob", "Lim", ' ', 4};
    Student s2={21104304, "Zed", "Abellana", 'P', 4};
    Student s3={21104304, "Zedo", "Abellana", 'P', 4};
    Student s4={21104308, "Onnez", "Abellana", 'P', 4};
    Student s5={21104304, "Dominic", "Abellana", 'P', 4};
    initialize(dict);
    insert(dict, s1);
    insert(dict, s2);
    insert(dict, s3);
    insert(dict, s4);
    insert(dict, s5);
    display(dict);

}

void initialize(Dictionary dict){
    int i;
    for(i=0;i<SIZE;i++){
        dict[i] = NULL;
    }
}

void insert(Dictionary D, Student S){
    int hashValue = hash(S.idNumber);
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

void display(Dictionary D){
    int i;
    for(i=0;i<SIZE;i++){
        while(D[i]!=NULL){
            printf("INDEX: %d\n", i);
            printf("ID: %d\n", D[i]->data.idNumber);
            printf("NAME: %s, %s %c\n", D[i]->data.LN, D[i]->data.FN, D[i]->data.MI);
            printf("YEAR LEVEL: %d\n\n", D[i]->data.year);
            D[i] = D[i]->next;
        }
    }
}