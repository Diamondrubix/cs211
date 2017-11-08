//
// Created by diamondrubix on 11/2/17.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#ifndef PROJECT5_ARRAYLISTMINE_CPP_H
#define PROJECT5_ARRAYLISTMINE_CPP_H

#endif //PROJECT5_ARRAYLISTMINE_CPP_H
//typedef enum {FALSE = 0, TRUE, NO = 0, YES} boolean;

template <class t> class ArrayList{
private:
    int size;//size of the array
    int leng;//amount of elements in the array
    int end;//location of the last element in the array (prob replace with leng?)
    int growth;
    t* arr;

    void init(){
        size = 2;
        leng = -1;
        end = 0;
        growth = 2;
        t* arr;
    }

public:

    ArrayList(){
        init();
        arr = (t *) malloc ( size * sizeof(t) );
    }

    t add(t a){
        if(leng==size){
            t *temp;
            size = size + growth;
            temp = (t *) malloc ( size * sizeof(t) );
            //temp[size];
            int i;
            for ( i = 0 ; i < leng ; i++)
                temp[i] = arr[i];
            leng = i++;
            free (arr);
            arr = temp;
        }
        leng++;
        arr[leng]=a;
    }

    void pop(){
        leng--;
    }

    void reset(){
        free(arr);
    }

    int isEmpty(){
        if(leng <0){
            return 1;
        }
        return 0;
    }

    t top(){
        return arr[leng];
    }

    //will return the amount of elements in the array
    int length(){
        return leng;
    }

    t get(int i){
        return arr[i];
    }



};