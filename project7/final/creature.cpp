//
// Created by diamondrubix on 12/1/17.
//
#include "creature.h"

//creature::creature(int x1, int y1) {

creature::creature(int x1, int y1) {
    rowSize = 20;
    colSize = 20;
    x = x1;
    y = y1;
    daysLived=0;
    moved = false;
    token='c';
    char test[] = "creature";
    //c = new dynamicArray<creature>();
}

bool creature::isEmpty(int xpos, int ypos) {
    int i;
    for(i=0; i<=c->length();i++){
        if(c->get(i)->x == xpos && c->get(i)->y==ypos){
            return false;
        }
    }
    return true;
}

char creature::getToken(){
    return token;
}

void creature::spawn() {
    printf("you wanna spawn something?");
}

void creature::die(){
    int i;
    for(i=0;i<=c->length();i++){
        int testx = c->get(i)->x;
        int testy = c->get(i)->y;
        if(testx==x&& y==testy){
            c->remove(i);

            break;
        }
    }
}


void creature::movetoPos(int x1, int y1) {
    x=x1;
    y=y1;
}

bool creature::tick() {
    //printf("creatures can't move silly");
    moved = true;
    return false;
}

void creature::move(){
    int rx = (rand() % 4);
    //int ry = (rand() % 2)-1;
    if (rx == 0) {
        if (x+1 >= 0 && x+1 < rowSize && isEmpty(x+1, y)) {
            movetoPos(x+1, y);
        }
    }else if(rx == 1){
        if (x-1 >= 0 && x-1 < rowSize && isEmpty(x-1, y)) {
            movetoPos(x-1, y);
        }
    }else if(rx ==2){
        if (y+1 >= 0 && y+1 < colSize && isEmpty(x, y+1)) {
            movetoPos(x, y+1);
        }
    }else if(rx ==3){
        if (y-1 >= 0 && y-1 < colSize && isEmpty(x, y-1)) {
            movetoPos(x, y-1);
        }
    }
}



