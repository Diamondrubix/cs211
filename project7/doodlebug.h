//
// Created by diamondrubix on 12/1/17.
//

#ifndef PROJECT7_DOODLEBUG_H
#define PROJECT7_DOODLEBUG_H

#endif //PROJECT7_TEST_H

#include "creature.h"

class doodlebug : public creature
{
private:
    int daysEaten;

public:
    doodlebug (int x1, int y1);

    void spawn(){
        if(isEmpty(x+1,y)){
            c->addTop(new doodlebug(x+1,y));
        }else if(isEmpty(x-1,y)){
            c->addTop(new doodlebug(x-1,y));
        }else if(isEmpty(x,y+1)){
            c->addTop(new doodlebug(x,y+1));
        }else if(isEmpty(x,y-1)){
            c->addTop(new doodlebug(x,y-1));
        }else{

        }
    }

    bool tick(){
        bool eaten = hunt();
        bool spawned = false;
        if(eaten){
            daysEaten=0;
        }else{
            daysEaten++;
        }
        if(daysLived>7){
            spawn();
            daysLived=-1;
            //printf("doodle born");
            spawned = true;
        }
        if(daysEaten>3){
            die();
            //printf("doodle died");
        }
        daysLived++;
        return spawned;
    }

    bool hunt(){
        int i;
        bool killed = false;
        for(i=0;i<=c->length();i++){
            int j;
            if(c->get(i)->getToken()=='A') {
                int antX = c->get(i)->x;
                int antY = c->get(i)->y;
                if (x+1 == antX && y == antY) {
                    c->get(i)->die();
                    movetoPos(x + 1, y);
                    killed = true;
                    break;
                } else if ((x-1 == antX) && y == antY) {
                    c->get(i)->die();
                    movetoPos(x - 1, y);
                    killed = true;
                    break;
                } else if (x == antX && y+1 == antY) {
                    c->get(i)->die();
                    movetoPos(x, y + 1);
                    killed = true;
                    break;
                } else if (x == antX && y-1 == antY) {
                    c->get(i)->die();
                    movetoPos(x, y - 1);
                    killed = true;
                    break;
                } else {

                    }

                }
        }
        if(!killed) {
            move();
        }
        return killed;

    }

};


