//
// Created by diamondrubix on 12/6/17.
//

#ifndef FINALEXAM_DYNAMICLIST_H
#define FINALEXAM_DYNAMICLIST_H

#endif //FINALEXAM_DYNAMICLIST_H
//
// Created by diamondrubix on 11/17/17.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//typedef enum {FALSE = 0, TRUE, NO = 0, YES} boolean;

class dynamicList{
private:
    int leng;//amount of elements in the array
    typedef struct storage{
        int elem;
        storage* next;
    } storage;

    storage* s;

    int getR(int i,storage* L);
    storage* getLast(storage* s);

public:



    dynamicList();
    int add(int a);
    bool doesValueExist(int x);
    void remove(int i);
    int isEmpty();
    void showList();
    void removeAll();
    //will return the amount of elements in the array
    int length();
    int get(int i);


};
