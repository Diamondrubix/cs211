#include "program4Header.h"

void displayListInformation(node m){
    if(m.next!=NULL){
        printf("groupname:%s\tGroupsize:%d\tInReastaurant:%s\n",m.name,m.groupSize,m.inRestaurant?"true":"false");
        displayListInformation(*m.next);
    }else{
        printf("groupname:%s\tGroupsize:%d\tInReastaurant:%s\n",m.name,m.groupSize,m.inRestaurant?"true":"false");
    }
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

void retrieveAndRemove (node* m,int tableSize){
    if(m->next!=NULL) {
        if (tableSize >= m->next->groupSize && m->next->inRestaurant) {//table > size (this looks really ugly)
            node *ptr = m->next;
            if(m->next->next!=NULL) {
                m->next = m->next->next;
            }else{
                m->next=NULL;
            }
            free(ptr);//double check, make sure this actually works.
        }else{
            retrieveAndRemove(m->next,tableSize);
        }
    }else{
        printf("no suitable groups available");
    }
}
