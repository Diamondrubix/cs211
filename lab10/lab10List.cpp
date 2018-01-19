#include "lab10List.h"


MyLNode::MyLNode (int v1)
{
  elem = v1;
  next = NULL;
}
  
MyLNode::MyLNode (int v1, MyLNode* n)
{
  elem = v1;
  next = n;
}

void MyLNode::setElem (int e)
{
  elem = e;
}

int MyLNode::getElem ()
{
  return elem;
}

void MyLNode::setNext (MyLNode* n)
{
  next = n;
}

MyLNode* MyLNode::getNext()
{
  return next;
}

MyList::MyList()
{
  head = NULL;
}
 
void MyList::show()
{
  while (head != NULL)
  {
    printf ("%d, ", head->getElem());
    head = head->getNext();
  }
  printf ("\n");
}

void MyList::insert (int v1)
{
  MyLNode* tmp = new MyLNode (v1);
  
  // this code just inserts the node at the beginning of the list
  tmp->setNext (head);
  head = tmp;
}

void MyList::remove (int v1)
{
  
}


int MyList::getListLength(){
  MyLNode* head1 = head;
}

MyList::MyList(const MyList &param){

  while(head->getNext()!=NULL){

  }
}

