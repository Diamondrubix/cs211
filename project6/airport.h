//
// Created by diamondrubix on 11/19/17.
//

#ifndef PROJECT6_AIRPORT_H
#define PROJECT6_AIRPORT_H

#endif //PROJECT6_AIRPO

#include <jmorecfg.h>
#include "dynamicArray.h"
#include "myNode.h"

template <class t> class myNode{
private:
    t* a;
    myNode* getLast(myNode* i);

public:
    myNode* next;
    myNode();
    void add(airport* i);
    myNode* getNext();
    airport* setAirport(airport* i); //set element
    void delElement(airport* i); //delete airport//im not consistent cuz i wanna turn this into a generic later.
    airport* getElem();

};

class airport{
private:
    //airport** destinations;
    //dynamicArray<airport*> destinations;
    myNode* edges;
    boolean visited;
    int airportNumber;

    void deleteUtil(myNode* e,airport* a);

public:
    airport(int num) //: destinations(5)
    {
        visited = false;
        airportNumber = num;
        edges = new myNode();
    }

    void addEdge(airport* i);//adds a edge
    void deleteEdge(airport* i);
    int getAirPortNumber();


};