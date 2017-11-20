#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "airport.h"
//#include "dynamicArray.h"

class TravelNetwork
{
private:
    // Create the Data Members for the Travel Network here
    dynamicArray<airport*>* airports;

public:

    // Use a constructor to initialize the Data Members for Travel Network
    TravelNetwork() //: airports(10)
    {
        airports = new dynamicArray<airport*>(10);

    }


    // The main loop for reading in input
    void processCommandLoop (FILE* inFile)
    {
        char  buffer[300];
        char* input;

        input = fgets ( buffer, 300, inFile );   // get a line of input
        int numInput;
        // loop until all lines are read from the input
        while (input != NULL)
        {
            // process each line of input using the strtok functions
            char* command;
            command = strtok (input , " \n\t");
            //printf("\nINPUT%s\n",input);
            //printf("\nCOMMAND%s\n",);

            printf ("*%s*\n", command);

            if ( command == NULL )
                printf ("Blank Line\n");

            else if ( strcmp (command, "q") == 0)
                exit(1);

            else if ( strcmp (command, "?") == 0)
                showCommands();

            else if ( strcmp (command, "t") == 0)
                doTravel();

            else if ( strcmp (command, "r") == 0) {

                sscanf(strtok(NULL, " \n\t"), "%d", &numInput);
                doResize(numInput);
            }

            else if ( strcmp (command, "i") == 0)
                doInsert();

            else if ( strcmp (command, "d") == 0)
                doDelete();

            else if ( strcmp (command, "l") == 0)
                doList();

            else if ( strcmp (command, "f") == 0)
                doFile();

            else if ( strcmp (command, "#") == 0)
                ;

            else
                printf ("Command is not known: %s\n", command);

            input = fgets ( buffer, 300, inFile );   // get the next line of input

        }
    }

    void showCommands()
    {
        printf ("The commands for this project are:\n");
        printf ("  q \n");
        printf ("  ? \n");
        printf ("  # \n");
        printf ("  t <int1> <int2> \n");
        printf ("  r <int> \n");
        printf ("  i <int1> <int2> \n");
        printf ("  d <int1> <int2> \n");
        printf ("  l \n");
        printf ("  f <filename> \n");
    }

    void doTravel()
    {
        int val1 = 0;
        int val2 = 0;

        // get an integer value from the input
        char* next = strtok (NULL, " \n\t");
        if ( next == NULL )
        {
            printf ("Integer value expected\n");
            return;
        }
        val1 = atoi ( next );
        if ( val1 == 0 && strcmp (next, "0") != 0)
        {
            printf ("Integer value expected\n");
            return;
        }

        // get another integer value from the input
        next = strtok (NULL, " \n\t");
        if ( next == NULL )
        {
            printf ("Integer value expected\n");
            return;
        }
        val2 = atoi ( next );
        if ( val2 == 0 && strcmp (next, "0") != 0)
        {
            printf ("Integer value expected\n");
            return;
        }


        printf ("Performing the Travel Command from %d to %d\n", val1, val2);



    }

    void doResize(int v)
    {
        int val1 = v;
        printf ("Performing the Resize Command with %d\n", val1 );
        delete(airports);
        airports = new dynamicArray<airport*>(val1);


    }

    void doInsert()
    {
        int val1;
        int val2;
        sscanf(strtok(NULL, " \n\t"), "%d", &val1);
        sscanf(strtok(NULL, " \n\t"), "%d", &val2);

        //printf("\nval1 %d val2 %d\n",val1,val2);

        airport* a;
        airport* b;
        if(!checkExist(val1)){
            a = new airport(val1);
            airports->add(a);
        }else{
            a=getAirport(val1);
        }
        if(!checkExist(val2)) {
            b = new airport(val2);
            airports->add(b);
        }else{
            b=getAirport(val2);
        }

        a->addEdge(b);

        //airports->add(new airport())

    }
    //returns the airport with the code
    airport* getAirport(int code){
        int i;
        for(i=0; i<airports->length();i++){
            if(airports->get(i)->getAirPortNumber()==code){
                return airports->get(i);
            }
        }
    }

    //return 1 if it exists
    int checkExist(int code){
        int i;
        for(i=0; i<airports->length();i++){
            if(airports->get(i)->getAirPortNumber()==code){
                return 1;
            }
        }
        return 0;
    }

    void doDelete()
    {

    }

    void doList()
    {

    }

    void doFile()
    {
        // get a filename from the input
        char* fname = strtok (NULL, " \n\t");
        if ( fname == NULL )
        {
            printf ("Filename expected\n");
            return;
        }

        printf ("Performing the File command with file: %s\n", fname);

        // next steps:  (if any step fails: print an error message and return )
        //  1. verify the file name is not currently in use
        //  2. open the file using fopen creating a new instance of FILE*
        //  3. recursively call processCommandLoop() with this new instance of FILE* as the parameter
        //  4. close the file when processCommandLoop() returns
    }
};

int main (int argc, char** argv)
{
    // set up the variable inFile to read from standard input
    FILE* inFile = stdin;

    // set up the data needed for the airport adjcency list
    TravelNetwork airportData;

    // call the method that reads and parses the input
    airportData.processCommandLoop (inFile);

    printf ("Goodbye\n");
    return 1;
}