// CS 211 lab 8
//
//  Written by Pat troy

#include <cstdio>
#include <cstdarg>
#include <cmath>
using namespace std;

class Point2d
{
    // data members are almost ALWAYS private
public:
    // the X and Y coordinates for the point
    int x;// Line 201

protected:
    int y;                        // Line 202

    // a way to handle debug mode
private:
    bool debug;                   // LINE 203

public:
    // follows the exact same parameter rules as printf()
    void dprintf(char *format, ...) {
        // use of the C ellipse to allow for multiple parameters
        if( debug ) {
            printf ("Debug: ");
            va_list alist;
            va_start(alist, format);
            vprintf(format, alist);
            va_end(alist);
        }
    }

    void setDebug (bool b) {
        debug = b;
    }


    // use of class constructors to initialize the variables
    Point2d (int px, int py)
    {
        x = px;
        y = py;

        // turn off debugging by default
        debug = false;
    }

    // default constructor: set point to (0, 0)
    Point2d ( )
    {
        x = 0;
        y = 0;
    }


    void setX (int px)
    {
        dprintf ("call to setX(%d), previous value %d\n", px, x);
        x = px;
    }

    int getX()
    {
        return x;
    }

    void setY (int py)
    {
        dprintf ("call to setY(%d), previous value %d\n", py, y);
        y = py;
    }

    int getY()
    {
        return y;
    }

    void setXY (int px, int py)
    {
        setX(px);
        setY(py);
    }

    double distanceFrom (Point2d pt)
    {
        double deltaX = abs ( 1.0 * x - pt.getX() );
        double deltaY = abs ( 1.0 * y - pt.getY() );

        dprintf ("distanceFrom(): deltaX=%f, deltaY=%f\n", deltaX, deltaY);

        return sqrt ( ( deltaX * deltaX ) + ( deltaY * deltaY ) );
    }

    // note this is unsafe since length of buf is never verified
    char*  toStr(char* buf)
    {
        sprintf ( buf, "(%d, %d)", x, y);
        return buf;
    }

};

class Point3d: public Point2d
{
private:
    int z;

public:
    Point3d (int px, int py, int pz)
            : Point2d ( px, py)
    {
        z = pz;
    }

    Point3d ( )
            : Point2d ( 0, 0)
    {
        z = 0;
    }

    void setZ (int pz)
    {
        dprintf ("call to setZ(%d), previous value %d\n", pz, z);
        z = pz;
    }

    int getZ ()
    {
        return z;
    }

    void setXYZ( int px, int py, int pz)
    {
        setXY ( px, py );
        setZ  ( pz );
    }

    double distanceFrom ( Point3d pt )
    {

        double dx = abs ( 1.0 * getX() - pt.getX() );
        double dy = abs ( 1.0 * getY() - pt.getY() );
        dx = abs ( 1.0 * x - pt.getX() );      // LINE 310
        dy = abs ( 1.0 * y - pt.getY() );      // LINE 311

        double dz = abs ( 1.0 * z - pt.getZ() );

        dprintf ("distanceFrom(): deltaX=%f, deltaY=%f, deltaZ=%f\n",
                 dx, dy, dz);

        return sqrt ( (dx * dx) + (dy * dy) + (dz * dz) );
    }

    char* toStr (char* buf)
    {
        sprintf ( buf, "(%d, %d, %d)", getX(), getY(), getZ() );
        return buf;
    }

};

int main ( int argc, char** argv)
{
    char buffer[100]; // buffer of size 100 to print point

    // create an instance of the Point2d class
    Point2d pt1;  // sets to (0, 0) by default

    // Code to test Access Modifiers
    //pt1.x = 1;               // LINE 10
    //pt1.y = 2;               // LINE 11
    //pt1.debug = true;        // LINE 12

    printf ("Current pt1: %s\n", pt1.toStr(buffer) );
    pt1.setDebug (true);
    pt1.setXY(5, -3);
    printf ("Current pt1: %s\n", pt1.toStr(buffer) );

    Point2d pt2 (3, 7);
    printf ("Current pt2: %s\n", pt2.toStr(buffer) );
    printf ("Distance between points %f\n", pt1.distanceFrom(pt2) );
    printf ("Distance between points %f\n", pt2.distanceFrom(pt1) );


    // use of the Point3d class
    printf ("\nWorking with the Point3d class\n\n");
    Point3d pt3 ( 3, 5, -2);
    printf ("Current pt3: %s\n", pt3.toStr(buffer) );
    pt3.setDebug (true);
    pt3.setXYZ(9, 8, 7);
    printf ("Current pt3: %s\n", pt3.toStr(buffer) );

    // code to text Access Modifiers
    //pt3.x = -5;
    //pt3.y = -4;
    //pt3.z = -3
    //pt3.debug = false;

    Point3d pt4;
    printf ("Current pt4: %s\n", pt4.toStr(buffer) );
    printf ("Distance between points %f\n", pt3.distanceFrom(pt4) );
    printf ("Distance between points %f\n", pt4.distanceFrom(pt3) );
}
