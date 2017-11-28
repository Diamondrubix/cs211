#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


int debug;

typedef struct Stacker //<---what does this name do? only the name after the declaration matters no?
{
    char* stack; //the pointer to the dynamic array that actually holds the stack
    int size;    //the integer variable specifying the current size of the dynamic array
    int top;    //the integer variable specifying the top of the stack (how much of the array is “inUse”)
} Stack;

char opposite(char x){
    char* open = "({[<";
    char* closed = ")}]>";
    int i =0;
    for(i; i<4;i++){
        if(x==open[i]){
            return closed[i];
        }
        if(x==closed[i]){
            return open[i];
        }
    }
    return 'e';

}

int openBracket(char x){
    char *open = "(<[{";
    int size = 4;
    int i =0;
    for(i; i<size;i++){
        if(x==open[i]){
            return 1;
        }
    }
    return 0;
}
int closedBracket(char x){
    char *open = ")>]}";
    int size = 4;
    int i =0;
    for(i; i<size;i++){
        if(x==open[i]){
            return 1;
        }
    }
    return 0;
}

void init (Stack* s)
{
    s->size = 2;
    s->stack = (char*) malloc ( sizeof (char) * s->size );
    s->top  = -1;
}

void pop (Stack* s)
{
    if (debug)
        printf ("%c being pushed",s->stack[s->top]);
    s->top = s->top - 1;
}

void push (Stack* s, char val) {
    /* check if enough space currently on stack and grow if needed */
    if (debug){
        printf ("%c being pushed",val);
    }
    //if(s->stack[0]!=nullprt){ //maybe there is a better way to do this?
    s->top = s->top + 1;
    //}

    if(s->top == s->size) {
        char *temp;
        s->size = s->size + 2;
        temp = (char *) malloc((s->size) * sizeof(char));
        int i = 0;
        for (i; i < s->size-2 ; i++)
            temp[i] = s->stack[i];
        free(s->stack);
        s->stack = temp;
    }
    /* add val onto stack */
    s->stack[s->top] = val;
    //  s->top = s->top + 1;
}


int bracket(char x){
    char *bra = "({[<>]})";
    int i =0;
    for(i; i<8;i++){
        if(x==bra[i]){
            return 1;
        }
    }
    return 0;
}

int checker(char* chain,int length){
    Stack stack;
    init(&stack);

    printf("\n%s",chain);
    int i =0;
    for(i; i<length;i++){
        if(bracket(chain[i])) {
            printf(" ");
            if (openBracket(chain[i])) {
                push(&stack, chain[i]);

            }

            if (closedBracket(chain[i])) {
                if (stack.top < 0) {
                    printf("^ missing a %c", opposite(chain[i]));
                    return 1;
                }

                if (stack.stack[stack.top] == opposite(chain[i])) {
                    pop(&stack);
                } else {
                    int j = 0;
                    for (j; j < stack.top; j++) {
                        char test1 = stack.stack[stack.top - j];
                        char test2 = opposite(chain[i]);
                        //still dosn't entirely work
                        if (stack.stack[stack.top - j] == opposite(chain[i])) {
                            printf("^ missing a %c", opposite(chain[i]));
                            return 1;
                        }
                    }
                    printf("^ expecting a %c", opposite(stack.stack[stack.top]));
                    return 1;
                }
            }
        }
    }

    int tet = stack.top;
    if(stack.top!=-1){
        printf("^ expecting a %c",opposite(stack.stack[stack.top]));
        return 1;
        //printf("missing a %c",opposite(stack.stack[stack.top]));
    }
    return 0;
}

int main(int argc, char** argv){

    printf("Program 2!\n");
    debug = 0;
    int dex = 0;
    for (dex; dex < argc; dex++){
        if ('-' == argv[dex][0]){
            if('d'==argv[dex][1]){
                debug = 1;
                printf("DEBUG MODE\n");
            }
        }
    }

    //char *fgets(char *str, int n, FILE *stream);
    //fgets(chain, 300, stdin);


    char **array;
    int numLines = 2;
    int numChars = 15;

    array = malloc(numLines * sizeof(char*));
    int i = 0;
    for (i; i < numLines; i++)
        array[i] = malloc((numChars+1) * sizeof(char));

    int counter =-1;
    char cont;
    do{
        counter++;
        if(counter>=numLines){
            char **temp;
            numLines = numLines+2;
            if (debug)
                printf ("array grown to %d\n",numLines);
            temp = malloc(numLines * sizeof(char*));
            int yer=0;
            for(yer;yer<numLines-2;yer++){
                temp[yer]=array[yer];
            }
            free(array);
            array = temp;
            int d = counter;
            for(d;d<=numLines;d++){
                array[d] = malloc((numChars+1) * sizeof(char));
                //printf("okokok");
            }
        }
        fgets(array[counter], numChars, stdin);
        cont = array[counter][0];

    }while(cont !='q');

    //char *chain = "((<<>>))";
    int j = 0;
    for(j; j<=counter-1;j++){
        if(!checker(array[j],numChars)){
            printf("^ expression balanced");
        }
    }


    printf("\n");




    return 0;
}