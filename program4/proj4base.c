/*  Code for the user interface for Lab 4 for CS 211 Fall 2015
 *
 *  Author: Pat Troy
 *  Date: 10/6/2013
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ctype.h> //used for isSpace

typedef enum {FALSE = 0, TRUE, NO = 0, YES} boolean;

boolean debugMode = FALSE;

typedef struct node
{
    char *name;  //name of the group
    int groupSize;
    boolean inRestaurant;
    struct node* next;
} node;


//my functions start here

node* getEndOfQueue(node* m){
    if(m->next !=NULL){
        return getEndOfQueue(m->next);
    }else{
        return m;
    }
}
/*
void addToList(node* m, node* x){
    node* n = (node*) malloc (sizeof(node));
    n= getEndOfQueue(m);
    n->next=x;
}
 */

void addToList(node* m, int size,char* GroupName,boolean onCite){
    node* newer = (node*) malloc (sizeof(node));
    newer->groupSize = size;
    newer->name = GroupName;
    newer->next=NULL;
    newer->inRestaurant=onCite;
    getEndOfQueue(m)->next=newer;
}


boolean doesNameExist(node* m,char* name){
    if(m->next!=NULL){
        if (strcmp(m->next->name, name) == 0){
            return TRUE;
        }else{
            return doesNameExist(m->next,name);
        }
    }else{
        return FALSE;
    }
}


/* forward definition of functions */
void clearToEoln();

/* Read in until the first Non-White-Space character is Read */
/* The white space characters are:
 *      space, tab \t, newline \n, vertical tab \v,
 *      form feed \f, and carriage return \r
 */
int getnextNWSChar ()
{
 int ch;

 ch = getc(stdin);

 if (ch == EOF || ch == '\n')
   return ch;
 while (isspace (ch))
   {
    ch = getc(stdin);
    if (ch == EOF || ch == '\n')
      return ch;
   }
 return ch;
}

/* read in the next Positive Integer or error:    */
/* This is based on the Mathematical definition of a Postive Integer */
/*    zero is not counted as a positive number */
int getPosInt ()
{
 int value = 0;

 /* clear white space characters */
 int ch;
 ch = getc(stdin);
 while (!isdigit(ch))
   {
    if ('\n' == ch)  /* error \n ==> no integer given */
       return 0;
    if (!isspace(ch)) /* error non white space ==> integer not given next */
      {
       clearToEoln();
       return 0;
      }
    ch = getc(stdin);
   }

 value = ch - '0';
 ch = getc(stdin);
 while (isdigit(ch))
   {
    value = value * 10 + ch - '0';
    ch = getc(stdin);
   }

 ungetc (ch, stdin);  /* put the last read character back in input stream */

 /* Integer value of 0 is an error in this program */
 if (0 == value)
    clearToEoln();

 return value;
}

/* read in the name until the end of the input */
char *getName()
{
 /* skip over the white space characters */
 int ch;
 ch = getc(stdin);
 while (isspace(ch))
   {
    if ('\n' == ch)  /* error \n ==> no integer given */
       return NULL;
    ch = getc(stdin);
   }

 char *word;
 int size;
 size = 10;
 word = (char *) malloc (sizeof(char) * size);

 // read in character-by-character until the newline is encountered
 int count = 0;

 while (ch != '\n')
   {

    if (count+1 >= size)
      {
       // to grow an array to make it "dynamically sized" using malloc
       char* temp;
       int i;
       size = size * 2;
       temp = (char *) malloc (sizeof(char) * size);

       // printf ("Growing array from size %d to size %d\n", count, size);
       // copy the characters to the new array
       for (i = 0 ; i < count ; i++)
           temp[i] = word[i];

       free (word);
       word = temp;
      }

    word[count] = ch;
    count++;
    word[count] = '\0';

    // read next character
    ch = getc(stdin);
   }

 if (count > 30)
   {
    count = 30;
    word[count] = '\0';
   }

 /* clear ending white space characters */
 while (isspace (word[count-1]))
   {
    count--;
    word[count] = '\0';
   }

 return word;
}

/* Clear input until next End of Line Character - \n */
void clearToEoln()
{
 int ch;

 do {
     ch = getc(stdin);
    }
 while ((ch != '\n') && (ch != EOF));
}

/* Print out a list of the commands for this program */
void printCommands()
{
 printf ("The commands for this program are:\n\n");
 printf ("q - to quit the program\n");
 printf ("? - to list the accepted commands\n");
 printf ("a <size> <name> - to add a group to the wait list\n");
 printf ("c <size> <name> - to add a call-ahead group to the wait list\n");
 printf ("w <name> - to specify a call-ahead group is now waiting in the restaurant\n");
 printf ("r <table-size> - to retrieve the first waiting group that can fit at the available table size\n");
 printf ("l <name> - list how many groups are ahead of the named group\n");
 printf ("d - display the wait list information\n");

 /* clear input to End of Line */
 clearToEoln();
}

void doAdd (node *m)
{
 /* get group size from input */
 int size = getPosInt();
 if (size < 1)
   {
    printf ("Error: Add command requires an integer value of at least 1\n");
    printf ("Add command is of form: a <size> <name>\n");
    printf ("  where: <size> is the size of the group making the reservation\n");
    printf ("         <name> is the name of the group making the reservation\n");
    return;
   }

 /* get group name from input */
 char *name = getName();
 if (NULL == name)
   {
    printf ("Error: Add command requires a name to be given\n");
    printf ("Add command is of form: a <size> <name>\n");
    printf ("  where: <size> is the size of the group making the reservation\n");
    printf ("         <name> is the name of the group making the reservation\n");
    return;
   }


 // add code to perform this operation here
    //node n;
    //n.name = name;
   // n.groupSize = size;
    //n.inRestaurant = FALSE;
    if(!doesNameExist(m,name)) {
        printf ("Adding group \"%s\" of size %d\n", name, size);
        addToList(m, size, name, TRUE);
    }else{
        printf("%s is already in the queue!",name);
    }
    //addToList(m,&n);
}


void doCallAhead (node* m)
{
 /* get group size from input */
 int size = getPosInt();
 if (size < 1)
   {
    printf ("Error: Call-ahead command requires an integer value of at least 1\n");
    printf ("Call-ahead command is of form: c <size> <name>\n");
    printf ("  where: <size> is the size of the group making the reservation\n");
    printf ("         <name> is the name of the group making the reservation\n");
    return;
   }

 /* get group name from input */
 char *name = getName();
 if (NULL == name)
   {
    printf ("Error: Call-ahead command requires a name to be given\n");
    printf ("Call-ahead command is of form: c <size> <name>\n");
    printf ("  where: <size> is the size of the group making the reservation\n");
    printf ("         <name> is the name of the group making the reservation\n");
    return;
   }

    if(!doesNameExist(m,name)) {
        printf("Call-ahead group \"%s\" of size %d\n", name, size);
        // add code to perform this operation here

        addToList(m, size, name, FALSE);
    }else{
        printf("%s is already in the queue!",name);
    }

}

boolean updateStatus(node *m,char* name){
    if(m->next!=NULL){
        if (strcmp(m->next->name, name) == 0){
            if(m->next->inRestaurant){
                return FALSE;
            }
            m->next->inRestaurant = TRUE;
            return TRUE;
        }else{
            return updateStatus(m->next,name);
        }
    }

}

void doWaiting (node *m)
{
 /* get group name from input */
 char *name = getName();
 if (NULL == name)
   {
    printf ("Error: Waiting command requires a name to be given\n");
    printf ("Waiting command is of form: w <name>\n");
    printf ("  where: <name> is the name of the group that is now waiting\n");
    return;
   }

 // add code to perform this operation here
    if(doesNameExist(m,name)) {
        if(updateStatus(m,name)) {
            printf("Waiting group \"%s\" is now in the restaurant\n", name);
        }else{
            printf("%s is already in the restaurant.",name);
        }
    }else{
        printf("%s is not in the queue", name);
    }

}

void retrieveAndRemove (node* m,int tableSize){
    if(m->next!=NULL) {
        if (tableSize >= m->next->groupSize && m->next->inRestaurant) {//table > size (this looks really ugly)
            node *ptr = m->next;
            if(m->next->next!=NULL) {
                m->next = m->next->next;
            }else{
                m->next=NULL;
            }
            free(ptr);//this probably works
        }else{
            retrieveAndRemove(m->next,tableSize);
        }
    }else{
        printf("no suitable groups available");
    }
}

void doRetrieve (node* m)
{
 /* get table size from input */
 int size = getPosInt();
 if (size < 1)
   {
    printf ("Error: Retrieve command requires an integer value of at least 1\n");
    printf ("Retrieve command is of form: r <size>\n");
    printf ("  where: <size> is the size of the group making the reservation\n");
    return;
   }
 clearToEoln();
 printf ("Retrieve (and remove) the first group that can fit at a tabel of size %d\n", size);

    retrieveAndRemove(m,size);

}
//only used in countGroupsAhead
int countGroupAheadRec(node* m,char* name, int counter){
    counter++;
    if(m->next!=NULL) {
        if (strcmp(m->next->name, name) != 0) {
            return countGroupAheadRec(m->next, name,counter);
        }else{
            return counter;
        }
    }else{
        return -1;
    }

}
//will return -1 if name is missing
int countGroupsAhead(node* m,char* name){
    int counter = 0;
    if(m->next!=NULL) {
        if (strcmp(m->next->name, name) != 0) {
            return countGroupAheadRec(m->next, name,counter);
        }
    }
    return 0;
}

void displayGroupsSizeAhead(node *m,char* name){
    if(m->next!=NULL){
        if (strcmp(m->next->name, name) != 0){
            printf("groupname:%s\tGroupsize:%d\tInReastaurant:%s\n",m->next->name,m->next->groupSize,m->next->inRestaurant?"true":"false");
            displayGroupsSizeAhead(m->next,name);
        }
    }
}

void doList (node* m)
{
 /* get group name from input */
 char *name = getName();
 if (NULL == name)
   {
    printf ("Error: List command requires a name to be given\n");
    printf ("List command is of form: l <name>\n");
    printf ("  where: <name> is the name of the group to inquire about\n");
    return;
   }


 // add cdode to perform this operation here
    if(doesNameExist(m,name)) {
        printf ("Group \"%s\" is behind the following groups\n", name);
        int ahead = countGroupsAhead(m, name);
        printf("there are %d group(s) ahead of %s\n", ahead, name);
        displayGroupsSizeAhead(m, name);
    }
}

//only used in totalonWaitList
int totalOnWaitListRec(node m,int counter){
    if(m.next!=NULL){
        counter++;
        return totalOnWaitListRec(*m.next,counter);
    }
    return counter;
}
//returns amount of people on waitlist.
int totalOnWaitList(node m){
    int counter = 1;
    if(m.next!=NULL){
        return totalOnWaitListRec(*m.next,counter);
    }
    return 0;
}

void displayListInformation(node m){
    if(m.next!=NULL){
        printf("groupname:%s\tGroupsize:%d\tInReastaurant:%s\n",m.name,m.groupSize,m.inRestaurant?"true":"false");
        displayListInformation(*m.next);
    }else{
        printf("groupname:%s\tGroupsize:%d\tInReastaurant:%s\n",m.name,m.groupSize,m.inRestaurant?"true":"false");
    }
}
void doDisplay (node* m)
{
 clearToEoln();
 printf ("Display information about all groups\n");

    // add code to perform this operation here
    int waitListSize = totalOnWaitList(*m);
    if(waitListSize ==0){
        printf("the queue is empty\n");
    }else {
        printf("the waitListSize is %d\n", waitListSize);
        displayListInformation(*m->next);
    }
    //printf("groupName: %c")
}


int main (int argc, char **argv)
{

    char *input;
    int ch;

    printf ("Starting Restaurant Wait List Program\n\n");
    printf ("Enter command: ");

    int dad = 20;
    //delcares the end of que
    node queue;
    queue.groupSize=0;
    queue.next = NULL;
    char* test;

    while ((ch = getnextNWSChar ()) != EOF)
    {
    /* check for the various commands */
        //queue.next->name = test;
        if ('q' == ch)//done
          {
           printf ("Quitting Program\n");
           return (0);
          }
        else if ('?' == ch)//done
          {
           printCommands();
          }
        else if('a' == ch)//done
          {
           doAdd(&queue);
          }
        else if('c' == ch)//done
          {
           doCallAhead(&queue);
          }
        else if('w' == ch)//done
          {
           doWaiting(&queue);
          }
        else if('r' == ch)//done
          {
           doRetrieve(&queue);
          }
        else if('l' == ch)//done
          {
           doList(&queue);
          }
        else if('d' == ch) //done
          {
           doDisplay(&queue);
          }
        else if('\n' == ch)
          {
           /* nothing entered on input line     *
            * do nothing, but don't give error  */
          }
        else
          {
           printf ("%c - in not a valid command\n", ch);
           printf ("For a list of valid commands, type ?\n");
           clearToEoln();
          }
        //printf("the string is %s",queue.next->name);
        printf ("\nEnter command: ");
    }

    printf ("Quiting Program - EOF reached\n");
    return 1;
}
