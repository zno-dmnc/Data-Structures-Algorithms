#include <stdio.h>
#define EMPTY -1
#define DELETED -99
#define SIZE 8

typedef struct{
    int idNumber;
    char FN[20];
    char LN[20];
    char MI;
    int yearLevel;
}studType;

typedef studType Dictionary[SIZE];
typedef enum{TRUE, FALSE} bool;

void initialize(Dictionary D);
int hash(int x);
bool member(Dictionary D, studType elem);
void insert(Dictionary D, studType S);
void display(Dictionary D);
bool isFull(Dictionary D);

int main(){

    Dictionary D;
    studType s1={21104308, "Rob", "Lim", ' ', 4};
    studType s2={21104304, "Zed", "Abellana", 'P', 4};
    studType s3={21104304, "Zedo", "Abellana", 'P', 4};
    studType s4={21104308, "Onnez", "Abellana", 'P', 4};
    studType s5={21104304, "Dominic", "Abellana", 'P', 4};
    studType s6={21104312, "Leighanne", "Abellana", 'B', 4};
    studType s7={21104234, "Gab", "Bers", 'P', 4};
    studType s8={21234234, "Angel", "Bers", 'P', 4};
    studType s9={21145634, "John", "Bers", 'P', 4};

    initialize(D);

    insert(D, s1);
    insert(D, s2);
    insert(D, s3);
    insert(D, s4);
    insert(D, s5);
    insert(D, s6);
    insert(D, s7);
    insert(D, s8);
    insert(D, s9);

    display(D);

    return 0;
}

void initialize(Dictionary D){
    int i;
    for(i=0;i<SIZE;i++){
        D[i].idNumber = EMPTY;
    }

}
int hash(int x){
    int sum = 0;
    while(x>0){
        sum+=x%10;
        x/=10;
    }
    return sum%SIZE;
}

bool member(Dictionary D, studType elem){
    int index = hash(elem.idNumber);
    bool retval = FALSE;


    while (D[index].idNumber != EMPTY && D[index].idNumber != DELETED) {

        retval = TRUE; 
        index = (index + 1) % SIZE;
    }
    return retval; 
}


// bool member(Dictionary D, studType elem){
//     int index = hash(elem.idNumber);
//     bool retval = FALSE;

//     if (index >= 0 && index < SIZE) {
//         if (D[index].idNumber != EMPTY || D[index].idNumber != DELETED) {
//             while (D[index].idNumber != EMPTY) {
//                 if (D[index].idNumber == elem.idNumber) {
//                     retval = TRUE; 
//                 }
//                 index = (index + 1) % SIZE;
//             }
//         }

//     }
//     return retval; 
// }

void insert(Dictionary D, studType S){
    int inx = hash(S.idNumber);
    if(isFull(D)!=TRUE){
        if(member(D, S)==TRUE){
            for(;D[inx].idNumber != EMPTY && D[inx].idNumber != DELETED; inx = (inx+1)%SIZE){}
        }
        
        D[inx] = S;
        printf("INSERTED!!\n\n");
    }
    else{
        printf("Dictionary is already full!\n\n");
    }
    
}

void display(Dictionary D){
    int i;
    for(i=0;i<SIZE;i++){
        if(D[i].idNumber != EMPTY || D[i].idNumber != DELETED){
            printf("INDEX: %d\n", i);
            printf("ID: %d\n", D[i].idNumber);
            printf("NAME: %s, %s %c\n", D[i].LN, D[i].FN, D[i].MI);
            printf("YEAR LEVEL: %d\n\n", D[i].yearLevel);
        }
    }
}

bool isFull(Dictionary D){
    int i;
    for(i=0;i<SIZE && D[i].idNumber!=EMPTY && D[i].idNumber!=DELETED; i++){}
    return (i<SIZE) ? FALSE : TRUE;
}