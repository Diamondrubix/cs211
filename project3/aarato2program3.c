#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <jmorecfg.h>

int debugmode = 0;

typedef struct mazeStruct
{
    int x,y;
    struct mazeStruct* next;
} linkedList;

/*old
typedef struct nodeStruct
{
    char arr[32][32];
    int xsize, ysize;
    int xstart, ystart;
    int xend, yend;
} maze; */
typedef struct nodeStruct
{
    char **arr;  /* allows for a maze of size 30x30 plus outer walls */
    int xsize, ysize;
    int xstart, ystart;
    int xend, yend;
} maze;

void pushStack(int x,int y,linkedList **m){
    linkedList* ptr = (linkedList*) malloc (sizeof(linkedList));
    ptr->x=x;
    ptr->y=y;
    ptr->next = *m;       /* note that hd must be "de-referenced" when used */
    *m = ptr;
    if(debugmode) {
        printf("x:%d y:%d were added to the stack", ptr->x, ptr->y);
    }
}
//return 1 is the stack is empty, otherwise removes the stop element in the stack
//this function sort of doubles as the isempty function as well.
int pop(linkedList** hd)
{
    linkedList* ptr = *hd;
    if (ptr->next != NULL)
    {
        if(debugmode){
            printf("x:%d y:%d were popped",ptr->x,ptr->y);
        }
        *hd = ptr->next;
        free (ptr);
        return 0;
    }else{
        return 1;
    }
}
//prints stack in reverse

void printReverseStack(linkedList *hd)
{
    if (hd == NULL) {
        return;
    }
    printReverseStack(hd->next);
    printf("x is %d y is %d \n",hd->x, hd->y);
}

//only ever used for debuging.
void printStack(linkedList* hd){
    int counter =0;
    while(hd!=NULL) {
        counter++;
        printf("%d:x is %d y is %d ",counter, hd->x, hd->y);
        hd = hd->next;
    }
}

linkedList* initStack(int x,int y){
    linkedList* l = (linkedList*) malloc (sizeof(linkedList));
    l->x=x;
    l->y=y;

    return l;
}

//HE NEVER SAID I ACTUALLY NEED TO USE THIS FUNCTION, JUST THAT IT NEEDS TO EXIST
linkedList* returnTop(linkedList* hd){
    //insert complext algortithm
    return hd;  
    //for the record I understand that this function would arguably improve readability, but still...
}
//will return a 1 if empty 0 otherwise. I never use this function either because I merged it with the pop function. it made more sense to do it that way
boolean isEmpty(linkedList** hd){
    if(hd==NULL){
        return TRUE;
    }else{
        return FALSE;
    }
}

//inits the maze stuct
void initMaze(int argc,char ** argv,maze *m1,int xpos,int ypos,int i,int j,FILE *src){
    /* verify the proper number of command line arguments were given */
    /*
    if(argc != 2) {
        printf("Usage: %s <input file name>\n", argv[0]);
        exit(-1);
    }
     */
    if(argc >3){
        printf("Usage: %s <input file name>\n", argv[0]);
        printf("\ntoo many inputs. You should only have -d for debug and the file name at most!");
        exit(-1);
    }


    /* Try to open the input file. */
    int open = 1;
    //this if statment is not actually used for debuging, its just a convenient shortcut
    if(debugmode){
        if(strcmp(argv[1],"-d")==0){
            open=2;
        }
    }
    if ( ( src = fopen( argv[open], "r" )) == NULL )
    {
        printf ( "Can't open input file: %s", argv[1] );
        exit(-1);
    }

    /* read in the size, starting and ending positions in the maze */
    fscanf (src, "%d %d", &m1->xsize, &m1->ysize);
    fscanf (src, "%d %d", &m1->xstart, &m1->ystart);
    fscanf (src, "%d %d", &m1->xend, &m1->yend);
    /* print them out to verify the input */


    if(m1->xsize<1 || m1->ysize<1){
        printf("grid size is invalid\n");
        exit(-1);
    }
    if(m1->ystart>m1->ysize || m1->ystart<0 || m1->xstart>m1->xsize || m1->xstart<0){
        printf("invalid start possition");
        exit(-1);
    }

    printf ("size: %d, %d\n", m1->xsize, m1->ysize);
    printf ("start: %d, %d\n", m1->xstart, m1->ystart);
    printf ("end: %d, %d\n", m1->xend, m1->yend);

    //this bit inits the maze array
    m1->arr = malloc((m1->xsize+2) * sizeof(char*));
    for (i=0; i < m1->xsize+2; i++)
        m1->arr[i] = malloc((m1->ysize+2) * sizeof(char));

    /* initialize the maze to empty */
    for (i = 0; i < m1->xsize+2; i++) {
        for (j = 0; j < m1->ysize + 2; j++)
            m1->arr[i][j] = '.';
    }

    /* mark the borders of the maze with *'s */
    for (i=0; i < m1->xsize+2; i++)
    {
        m1->arr[i][0] = '*';
        m1->arr[i][m1->ysize+1] = '*';
    }
    for (i=0; i < m1->ysize+2; i++)
    {
        m1->arr[0][i] = '*';
        m1->arr[m1->xsize+1][i] = '*';
    }

    /* mark the starting and ending positions in the maze */
    m1->arr[m1->xstart][m1->ystart] = 's';
    m1->arr[m1->xend][m1->yend] = 'e';

    /* mark the blocked positions in the maze with *'s */
    while (fscanf (src, "%d %d", &xpos, &ypos) != EOF)
    {
        m1->arr[xpos][ypos] = '*';
    }
}

//displays the maze
void displayMaze(maze *m1){
    int i;
    int j;
    /* print out the initial maze */
    for (i = 0; i < m1->xsize+2; i++)
    {
        for (j = 0; j < m1->ysize+2; j++)
            printf ("%c", m1->arr[i][j]);
        printf("\n");
    }
}


//this empties the stack and removes all linked lists
void resetStack(linkedList** hd){
    linkedList* ptr = *hd;
    while(ptr != NULL) {
        *hd = ptr->next;
        free(ptr);
        ptr = *hd;
    }
}


int main (int argc, char **argv)
{
    maze m1;

    int xpos, ypos;
    int i,j;
    int dex;
    boolean mazeHasSolution = TRUE;
    for(dex=1;dex<argc;dex++){
        if(strcmp(argv[dex],"-d")==0){
            debugmode=1;
        }
    }
    //printf("here is the argv %s\n",argv[2]);

    FILE *src;

    initMaze(argc,argv,&m1,xpos,ypos,i,j,src);
    displayMaze(&m1);
    printf("\n");

    linkedList* node = initStack(m1.xstart,m1.ystart);

    int stackempty = 0;
    while(!stackempty){

        if(debugmode) {
            displayMaze(&m1);
        }
        if(m1.arr[node->x+1][node->y] !='*'&& m1.arr[node->x+1][node->y] !='v'){
            m1.arr[node->x+1][node->y] ='v';
            pushStack(node->x+1,node->y,&node); // how to let pushstack accept a pointer and not need node=
        }
        else if(m1.arr[node->x][node->y+1] !='*'&& m1.arr[node->x][node->y+1] !='v'){
            m1.arr[node->x][node->y+1] ='v';
            pushStack(node->x,node->y+1,&node);
        }
        else if(m1.arr[node->x-1][node->y] !='*'&& m1.arr[node->x-1][node->y] !='v'){
            m1.arr[node->x-1][node->y] ='v';
            pushStack(node->x-1,node->y,&node);
        }
        else if(m1.arr[node->x][node->y-1] !='*'&& m1.arr[node->x][node->y-1] !='v'){
            m1.arr[node->x][node->y-1] ='v';
            pushStack(node->x,node->y-1,&node);
        }else{
            stackempty=pop(&node);
            if(stackempty){
                printf("maze has no solutions");
                mazeHasSolution = FALSE;
            }
        }
        //honestly should be using this for loop for the entire thing but I only thought of it after I already made the monstrosity above.
        for(i=-1;i<2;i++){
            for(j=-1;j<2;j++){
                if(m1.arr[node->x+j][node->y+i] =='e'){
                    stackempty=1;
                }
            }
        }

    }

    printf("\nfinal display\n");
    displayMaze(&m1);
    printf("\n");
    //printStack(node);
    if(mazeHasSolution) {
        printReverseStack(node);
    }
    //printf("\n");
    resetStack(&node);
    for(i=0;i<m1.xsize;i++){
        free(m1.arr[i]);
    }
    free(m1.arr);
    //printStack(node);
    printf("\n");

}
