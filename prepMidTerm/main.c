#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ctype.h> //used for isSpace

/*
-init
-isempty
-tpo or front
-push or enquire
-pop or dequien
-resetha
 */

typedef enum {FALSE = 0, TRUE, NO = 0, YES} boolean;

typedef struct node
{
    char* name;  //name of the group
    int num;
    struct node* next;
} node;



node* getEndOfQueue(node* m){
    if(m->next !=NULL){
        return getEndOfQueue(m->next);
    }else{
        return m;
    }
}
void addToList(node* m, int counter,char* c){
    node* newer = (node*) malloc (sizeof(node));
    newer->num = counter;
    newer->name=c;
    newer->next=NULL;
    getEndOfQueue(m)->next=newer;
}


int main() {
    printf("Hello, World!\n");

    node n;
    n.name = "first";
    n.next = NULL;
    n.num = 0;
    int ch;
    printf("first input: ");
    ch = getc(stdin);
    int counter = 0;
    //char* mainName[3];
    int size = 3;

    int dex = 0;

    while(counter<10000){
        char* mainName = (char *) malloc (sizeof(char) * size);
        while(ch !='\n'){
            mainName[dex]=ch;
            dex++;
            mainName[dex] = '\0';
            // read next character
            ch = getc(stdin);
        }
        counter ++;
        addToList(&n, counter,mainName);
        printf("new character ");
        ch = getc(stdin);
        dex = 0;


    }

    return 0;
}