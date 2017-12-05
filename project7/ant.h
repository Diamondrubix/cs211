//
// Created by diamondrubix on 12/3/17.
//
#ifndef PROJECT7_ANT_H
#define PROJECT7_ANT_H

#endif //PROJECT7_ANT_H


//#include "creature.h"

class ant : public creature
{
private:

public:
    ant (int x1, int y1) : creature(x1,y1){
        token='A';
    }

    void spawn(){
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


    bool tick(){
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

};


