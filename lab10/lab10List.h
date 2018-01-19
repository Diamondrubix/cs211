#include <cstdio>

// The node class for the linked list
class MyLNode
{
 private:
  int elem;
  MyLNode* next;
  
 public:
  MyLNode (int v1);
  MyLNode (int v1, MyLNode* n);
  
  void setElem (int e);
  int getElem ();
  void setNext (MyLNode* n);
  MyLNode* getNext();
};

class MyList
{
 private:
  MyLNode* head;
  
 public:
  MyList();
  MyList(const MyList &param);
  void show();
  int getListLength();
  void insert (int v1);
  void remove (int v1);
};


