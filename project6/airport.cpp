//
// Created by diamondrubix on 11/19/17.
//

#include "airport.h"


void airport::addEdge(airport* i) {
    edges->add(i);
    //destinations.add(i);
}

void airport::deleteEdge(airport* a){
    if(edges->getElem()==a){
        myNode* temp = edges->next;
        delete(edges);
        edges=temp;
    }

    deleteUtil(edges,a);
}

void airport::deleteUtil(myNode *e, airport *a) {
    if(e->next->getElem()==a){
        if(e->next->next!=NULL){
            myNode* temp = edges->next->next;
            delete(edges->next);
            edges->next=temp;
        }else{
            delete(edges->next);
        }
    }
}

int airport::getAirPortNumber(){
    return airportNumber;
}