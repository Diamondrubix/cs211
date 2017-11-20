//
// Created by diamondrubix on 11/20/17.
//

#include "airport.h"

myNode::myNode() {
    next = NULL;
    airport* a;
}

myNode* myNode::getLast(myNode *i) {
    if(next!=NULL){
        return getLast(next);
    }
    return this;
}

void myNode::add(airport* i) {
    getLast(next)->setAirport(i);
}

airport* myNode::setAirport(airport *i) {
    a=i;
}


myNode* myNode::getNext() {
    return next;
}

airport* myNode::getElem(){
    return a;
}

void myNode::delElement(airport* i) {

}