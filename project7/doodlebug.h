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

    void spawn();

    bool tick();

    bool hunt();

};


