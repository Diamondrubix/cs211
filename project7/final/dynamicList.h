//
// Created by diamondrubix on 12/3/17.
//

#ifndef PROJECT7_DYNAMICLIST_H
#define PROJECT7_DYNAMICLIST_H

#endif //PROJECT7_DYNAMICLIST_H

//
// Created by diamondrubix on 11/17/17.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//typedef enum {FALSE = 0, TRUE, NO = 0, YES} boolean;

template <class t> class dynamicList{
private:
    int leng;//amount of elements in the array
    typedef struct storage{
        t elem;
        storage* next;
    } storage;

    storage* s;

    storage* getLast(storage* s){
        if(s->next==NULL){
            return s;
        }else{
            getLast(s->next);
        }
    }

    t getR(int i,storage* L){
        if(i==0){
            return L->elem;
        }else{
            i=i-1;
            return getR(i,L->next);
        }
    }

public:

    dynamicList(){
        leng = -1;
        s = new storage;
        s->next = NULL;
        s->elem = NULL;
    }


    t add(t a){
        if(s->elem==NULL){
            s->elem = a;
        }else {
            storage* n = new storage;
            n->elem=a;
            n->next=NULL;
            getLast(s)->next=n;
        }
        leng++;

    }

    t addTop(t a){
        storage* n = new storage;
        n->elem=a;
        n->next=s;
        s= n;
        leng++;
    }


    void remove(int i){
        storage* temp;
        if(i==0){
            temp = s->next;
            free(s);
            s=temp;
        }else{
            temp = s;
            while(i!=1){
                temp = temp->next;
                i=i-1;
            }
            storage* other = new storage;
            other =temp->next;
            temp->next = temp->next->next;
            free (other);
        }
        leng = leng-1;
    }

    void reset(){
        //free(arr);
        printf("this doesn't work yet");
    }

    int isEmpty(){
        if(leng <0){
            return 1;
        }
        return 0;
    }


    storage top(){

    }

    //will return the amount of elements in the array
    int length(){
        return leng;
    }

    //get helper


    t get(int i){
        if(i==0){
            return s->elem;
        }else{
            i=i-1;
            return getR(i,s->next);
        }
    }


};
