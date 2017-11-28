#include "lab10List.h"

int main (int argc, char** argv)
{
  MyList list1;
  MyList list2;

  // insert some values
  printf ("\nTesting the insert() and show() methods\n");
  list1.insert (5);
  list1.insert (18);
  list1.insert (10);
  list1.show();
  list1.insert (3);
  list1.show();
    
  list2.insert (51);
  list2.insert (68);
  list2.insert (24);
  list2.show();
  list2.insert (93);
  list2.show();
    
  // remove some values
  printf ("\nTesting the remove() method\n");
  list1.remove (10);
  list1.show();
  list1.remove (7);
  list1.show();
  list1.remove (3);
  list1.show();
  list1.remove (18);
  list1.show();
    
  list2.remove (93);
  list2.remove (24);
  list2.remove (51);
  list2.show();
  list2.remove (68);
  list2.show();
  list2.remove (3);
  list2.show();
  list2.remove (18);
  list2.show();
    
  /* add code to test the getListLength and getNthElem methodes */
  printf ("\nTesting the getListLength() and getNthElem() methods\n");
  MyList list3;
  // insert some values and verify they are correct
  list3.insert (6);
  list3.insert (4);
  list3.insert (10);
  list3.insert (2);
  list3.insert (8);
  list3.show();

  /* code to duplicate show( )   */
  /*   for ( int pos = 0 ; pos < list3.getListLength() ; pos++)
   *   {
   *     printf ("%d, ", list3.getNthElem( pos ) );
   *   }
   *   printf("\n");
   */
    
  /* code to sum the values in the list without adding any more methods to the list class */
  /*   int sum = 0;
   *   for ( int pos = 0 ; pos < list3.getListLength() ; pos++)
   *   {
   *     sum = sum + list3.getNthElem( pos );
   *   }
   *   printf("The total of the values in the list is: %d\n", sum);
   */

  // Code to test the Copy Constructor
  printf ("\nTesting the Copy Constructor\n");
  MyList list4 ( list3 );
  list3.show();
  list4.show();
  list4.insert(7);
  list3.show();
  list4.show();

  // Remove all of the nodes from list4
  printf ("\nTesting the removeAll() method\n");
  // list4.removeAll();
  list4.show();

  return 1;
}
