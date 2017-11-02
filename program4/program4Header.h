/* sample .h file */

/* include all libraries here */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ctype.h> //used for isSpace

/* put any #define statements here */

typedef enum {FALSE = 0, TRUE, NO = 0, YES} boolean;

extern boolean debugMode;
/* put any structure declarations here */
typedef struct node
{
    char *name;  //name of the group
    int groupSize;
    boolean inRestaurant;
    struct node* next;
} node;
/* list any needed function prototypes here */
int calcMax( int a, int b );

int main();
node* getEndOfQueue(node* m);
void clearToEoln();
int getNextNWSChar();
int getPosInt();
char* getName();
void printCommands();

void doAdd(node* m);
void doCallAhead(node* m);
void doWaiting(node* m);
void doRetrieve(node* m);
void doList(node* m);
void doDisplay();

void addToList(node* m, int size,char* GroupName,boolean onCite);
boolean doesNameExist(node* m,char* name);
boolean updateStatus(node *m,char* name);
void retrieveAndRemove (node* m,int tableSize);
int countGroupsAhead(node* m,char* name);
void displayGroupsSizeAhead(node *m,char* name);
void displayListInformation(node m);
