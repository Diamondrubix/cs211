#include "program4Header.h"



//only used in totalonWaitList
int totalOnWaitListRec(node m,int counter){
    if(m.next!=NULL){
        counter++;
        return totalOnWaitListRec(*m.next,counter);
    }
    return counter;
}
//returns amount of people on waitlist. only used in one place
int totalOnWaitList(node m){
    int counter = 1;
    if(m.next!=NULL){
        return totalOnWaitListRec(*m.next,counter);
    }
    return 0;
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


 // add code to perform this operation here
    if(doesNameExist(m,name)) {
        printf ("Group \"%s\" is behind the following groups\n", name);
        int ahead = countGroupsAhead(m, name);
        printf("there are %d group(s) ahead of %s\n", ahead, name);
        displayGroupsSizeAhead(m, name);
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

