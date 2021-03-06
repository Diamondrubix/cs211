// CS 211 lab 11
//
//  Written by Pat troy

#include "Point2d.h"


    // follows the exact same parameter rules as printf() 
    void Point2d::dprintf(char *format, ...) {
      // use of the C ellipse to allow for multiple parameters
      if( debug ) {
        printf ("Debug: ");
        va_list alist;
        va_start(alist, format);
        vprintf(format, alist);
        va_end(alist);
      } 
    }

    void Point2d::setDebug (bool b) {
      debug = b;
    } 


   // use of class constructors to initialize the variables
   Point2d::Point2d (int px, int py)
   {
      printf ("In constructor Point2d(%d, %d)\n", px, py);
      x = px;
      y = py;

      // turn off debugging by default
      debug = false;
   }

   // default constructor: set point to (0, 0)
   Point2d::Point2d ( ) 
   {
      printf ("In constructor Point2d()\n");
      x = 0;
      y = 0;

      // turn off debugging by default
      debug = false;
   }


   void Point2d::setX (int px)
   {
     dprintf ("call to setX(%d), previous value %d\n", px, x);
     x = px;
   }

   int Point2d::getX()
   {
     return x;
   }

   void Point2d::setY (int py)
   {
     dprintf ("call to setY(%d), previous value %d\n", py, y);
     y = py;
   }

   int Point2d::getY()
   {
     return y;
   }

   void Point2d::setXY (int px, int py)
   {
      setX(px);
      setY(py);
   }

   double Point2d::distanceFrom (Point2d pt)
   {
     double deltaX = std::abs ( 1.0 * x - pt.getX() );
     double deltaY = std::abs ( 1.0 * y - pt.getY() );

     dprintf ("distanceFrom(): deltaX=%f, deltaY=%f\n", deltaX, deltaY);

     return sqrt ( ( deltaX * deltaX ) + ( deltaY * deltaY ) ); 
   }

   // note this is unsafe since length of buf is never verified
   char*  Point2d::toStr(char* buf)
   {
    sprintf ( buf, "(%d, %d)", x, y);
    return buf;
   } 



