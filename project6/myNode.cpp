//
// Created by diamondrubix on 11/20/17.
//

#include "airport.h"


myNode::myNode() {
    size = 0;
    header.next = NULL;
    header.a = NULL;
}


void myNode::add(airport* a){
    node *newer = (node *) malloc(sizeof(node));
    newer->a = a;
    getLast(&header)->next=newer;
    size++;
}

node* myNode::getLast(node* n) {
    if(n->next!=NULL){
        return getLast(n->next);
    }
    return n;
}

airport* myNode::getNAirport(int i) {
    if(i==0){
        return header.next->a;
    }else{
        node* temp = header.next;
        while(i!=0){
            temp = temp->next;
            i--;
        }
        return temp->a;
    }
}

void myNode::deleteEdge(airport *a) {
    node* temp=header.next;
    if(header.next->a == a){
        temp = header.next->next;
        free(header.next);
        header.next=temp;
    }else{
        while(temp->next->a!=a){
            temp=temp->next;
        }
        node* temp2 = temp->next->next;
        free(temp->next);
        temp->next=temp2;
    }
    size--;
}

void myNode::deleteEdgeByValue(int i) {
    node* temp=header.next;
    if(header.next->a->getAirPortNumber() == i){
        temp = header.next->next;
        free(header.next);
        header.next=temp;
    }else{
        while(temp->next->a->getAirPortNumber()!=i){
            temp=temp->next;
        }
        node* temp2 = temp->next->next;
        free(temp->next);
        temp->next=temp2;
    }
    size--;
}



