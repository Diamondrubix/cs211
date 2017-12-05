#include "GridDisplay.h"
//#include "creature.h"
#include "doodlebug.h"
#include "ant.h"


dynamicList<creature*>* creature::c = new dynamicList<creature*>();


void clearGrid(GridDisplay* gd){
    int i;
    int j;
    for(i=0; i<gd->getCol();i++){
        for(j=0;j<gd->getrows();j++){
            gd->setChar(j,i,'.');
        }
    }
}


void updateGrid(GridDisplay* gd){
    //updates grid
    int i;
    clearGrid(gd);
    for(i=0; i<=creature::c->length();i++){
        gd->setChar(creature::c->get(i)->y,creature::c->get(i)->x,creature::c->get(i)->getToken());
    }

    gd->showGrid();

}

int main ( int argc, char** argv )
{

    int sleepTime = 1000;
    if(argc>1) {
        if (strcmp(argv[1], "-d") == 0) {
            sscanf(argv[2], "%d", &sleepTime);
        }
        if (strcmp(argv[2], "-d") == 0) {
            sscanf(argv[1], "%d", &sleepTime);
        }
    }

    const int rowSize = 20;
    const int colSize = 20;
    srand(time(NULL));


    GridDisplay gd(rowSize, colSize);
    gd.showGrid ( );

    //setup
    int r1;
    int r2;
    int i; //spawn doodlebug
    for (i = 0; i < 5; i++) {
        r1 = rand() % colSize;
        r2 = rand() % rowSize;
        //updateGrid(&gd);
        //printf("\n%d %d %d",i,r1,r2);
        if (creature::isEmpty(r1, r2)) {
            creature::c->add(new doodlebug(r1, r2));
        } else {
            i--;
        }
    }
    //spawn ants
    for (i = 0; i < 100; i++) {
        r1 = rand() % colSize;
        r2 = rand() % rowSize;
        //updateGrid(&gd);
        //printf("\n%d %d %d",i,r1,r2);
        if (creature::isEmpty(r1, r2)) {
            creature::c->add(new ant(r1, r2));
        } else {
            i--;
        }
    }

    /*
    creature::c->add((new doodlebug(1,2)));

    creature::c->add(new ant(0,0));
    creature::c->add(new ant(1,0));
    creature::c->add(new ant(1,1));
    creature::c->add(new ant(2,1));
    creature::c->add(new ant(2,2));
     */


    updateGrid(&gd);


    //tick
    int tick = 200;
    while(tick>=0) {
        gd.mySleep ( sleepTime );
        for(i=0;i<=creature::c->length();i++){
            if(creature::c->get(i)->tick()){
                i++;
            }
            //creature::c->get(i)->die();
            //updateGrid(&gd);
        }

        updateGrid(&gd);
        tick=tick-1;
    }


    //gd.mySleep ( 1000 );
    /*updateGrid(&gd);
    char ch = (char) ( (int) 'a' + i );
    gd.setChar(i,i, ch);

    gd.showGrid ( );
     */


 return 1;
}
    
