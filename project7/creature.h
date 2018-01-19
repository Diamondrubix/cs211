//
// Created by diamondrubix on 12/1/17.
//

#ifndef PROJECT7_CREATURE_H
#define PROJECT7_CREATURE_H


#ifdef _MSC_VER
#pragma once
//#endif  // _MSC_VER
#endif //PROJECT7_CREATURE_H

#include <string>
#include "dynamicList.h"



class creature{
protected:
    bool moved;
    char token;
    int daysLived;
    const int rowSize = 20;
    const int colSize = 20;
    //char name[];

public:
    int x;
    int y;
    //static dynamicArray<creature*>* c;
    static dynamicList<creature*>* c;
    creature(int x1,int y1);
    static bool isEmpty(int xpos,int ypos);
    char getToken();
    virtual void spawn();
    void die();
    void movetoPos(int x1,int y1);
    virtual bool tick();
    void move();



};
#endif  // HEADER_FILE