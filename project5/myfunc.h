/* sample .h file */

/* include all libraries here */
#include <stdio.h>
#include "arrayListMine.h"

/* put any #define statements here */
//typedef enum {FALSE = 0, TRUE, NO = 0, YES} boolean;
/* put any structure declarations here */
extern int debugmode;

/* list any needed function prototypes here */
int eval(int v1,int v2, char op);
int postfix(ArrayList<int> *nums, ArrayList<char> *ops);
int popAndEval(ArrayList<int> *nums, ArrayList<char> *ops);

//boolean isEmpty();
//void push(int data); //will change int to data
//int top(); //change int to data
//void pop();
//void reset();