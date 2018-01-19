//
// Created by diamondrubix on 12/4/17.
//
#include "ant.h"


ant::ant(int x1, int y1) : creature (x1, y1)
{
    //name = "doodlebug";
    token = 'A';

};

void ant::spawn() {
    if(isEmpty(x+1,y)){
        c->add(new ant(x+1,y));
    }else if(isEmpty(x-1,y)){
        c->add(new ant(x-1,y));
    }else if(isEmpty(x,y+1)){
        c->add(new ant(x,y+1));
    }else if(isEmpty(x,y-1)){
        c->add(new ant(x,y-1));
    }else{

    }
}

bool ant::tick() {
    move();
    bool spawned = false;
    if(daysLived>3){
        spawn();
        spawned=true;
        daysLived=-1;
    }
    daysLived++;

    return spawned;
}


