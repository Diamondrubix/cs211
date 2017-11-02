#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ctype.h> //used for isSpace (required for my compiler, works on bert too)

typedef enum {FALSE = 0, TRUE, NO = 0, YES} boolean;

typedef struct node
{
    int num;
    struct node* next;
} node;

//isEmpty
boolean isEmpty(node m){
    if(m.next==NULL){
        return TRUE;
    }
    return FALSE;
}
//front
node* front(node* m){
    if(m->next !=NULL){
        return front(m->next);
    }else{
        return m;
    }
}
//enqueue will add it as long as it is not a 0
void enqueue(node* m, int num){
    if(num !=0) {//this is only so i don't have to make 3 if statements below checking for 0 before enqueue
        node *newer = (node *) malloc(sizeof(node));
        newer->num = num;
        newer->next = m->next;
        m->next = newer;
    }
}

//should never be run on the header
void dequeue (node* m){
    if(m->next->next==NULL) {
        node *ptr = m->next->next;
        free(ptr);
        m->next=NULL;

    }else{
        dequeue(m->next);
    }
}

node init(){
    node* newer = (node*) malloc (sizeof(node));
    newer->num=0;
    newer->next=NULL;
    return *newer;
}


int main() {
    printf("MidTerm Program\n");

    node positive = init();
    node negative = init();
    node fours = init();

    int value =1;
    printf("use 0 to mark the end of your list of numbers\n");
    printf("enter your values: ");
    while(value !=0) {
        scanf("%d", &value);
        if(value>0){
            enqueue(&positive ,value);
        }else{
            enqueue(&negative, value);
        }
        if(value%4==0){
            enqueue(&fours,value);
        }
    }
    int counter = 0;
    printf("\nPositive values entered were:\n");
    while(!isEmpty(positive)){
        value = front(&positive)->num;
        printf("%5d",value);
        dequeue(&positive);
        counter ++;
        if(counter >7){
            printf("\n");
            counter = 0;
        }
    }

    printf("\n\nNegative values entered were:\n");
    counter = 0;
    while(!isEmpty(negative)){
        value = front(&negative)->num;
        printf("%5d ",value);
        dequeue(&negative);
        counter ++;
        if(counter >7){
            printf("\n");
            counter = 0;
        }
    }
    printf("\n\nThe Multiples of 4 entered were:\n");
    counter = 0;
    while(!isEmpty(fours)){
        value = front(&fours)->num;
        printf("%5d ",value);
        dequeue(&fours);
        counter ++;
        if(counter >7){
            printf("\n");
            counter = 0;
        }
    }
    printf("\n");

    printf("End of program");





    return 0;
}