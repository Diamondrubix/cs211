//
// Created by diamondrubix on 12/6/17.
//

#include "dynamicList.h"

dynamicList::dynamicList() {
    leng = -1;
    s = new storage;
    s->next = NULL;
    s->elem = -999998; //yeah well null is 0 for some reason. Will work as long as first element is not -999998
}

int dynamicList::add(int a) {
    if(s->elem==-999998){
        s->elem = a;
    }else {
        storage* n = new storage;
        n->elem=a;
        n->next=NULL;
        getLast(s)->next=n;
    }
    leng++;

}

bool dynamicList::doesValueExist(int x) {
    storage* temp = s;
    while(temp!=NULL){
        if(temp->elem==x){
            return true;
        }
        temp=temp->next;
    }
    return false;
}

void dynamicList::remove(int i) {
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

int dynamicList::isEmpty() {
    if(leng <0){
        return 1;
    }
    return 0;
};


void dynamicList::showList() {
    storage* temp = s;

    if(leng >-1) {
        do {
            printf("%d ", temp->elem);
            temp = temp->next;

        } while ((temp != NULL));
    }else{
        printf("list is empty\n");
    }

}

void dynamicList::removeAll() {
    while(leng>-1){
        remove(leng);
    }
    s = new storage;
    s->elem=-999998;
    s->next=NULL;
}

int dynamicList::length() {
    return leng;
}

int dynamicList::get(int i) {
    if(i==0){
        return s->elem;
    }else{
        i=i-1;
        return getR(i,s->next);
    }
}

int dynamicList::getR(int i, storage *L) {
    if(i==0){
        return L->elem;
    }else{
        i=i-1;
        return getR(i,L->next);
    }
}


dynamicList::storage * dynamicList::getLast(storage *s) {
    if(s->next==NULL){
        return s;
    }else{
        getLast(s->next);
    }
}


