// ============================================================================
// File: QueueDriver.cpp (Spring 2018)
// ============================================================================
// Programmer: Jennifer King
// Date: 3/18/2018
// Project: CQueue
// Professor: Scott Edwards
// Class: CSCI 133F | TR 9:30AM
// Description:
//              This is the test driver for the CQueue ADT.  It creates a local queue
//              object and allows the user to insert and remove items to and from the
//              queue.
// ============================================================================

#include    <iostream>
using namespace std;
#include    <stdlib.h>
#include    <ctype.h>
#include        "csimplelist.h"
#include    "cqueue.h"

// function prototypes
void    DisplayMenu();
void    FlushInstream(istream  &inStream = cin);


// ==== main ==================================================================
//
// ============================================================================

int     main()
{
    bool                bLoop = true;
    char                selection;
    CQueue              myQueue;
    int                 intVal;
    int                 numItems;

    // let the user manipulate the list
    do  {
        DisplayMenu();

        // get the user selection
        cout << "\nPlease enter your selection: ";
        cin >> selection;

        // call the appropriate member function
        switch (toupper(selection))
            {
            case   'A':     // add an item to the queue
                cout << "Please enter a value to add to the queue: ";
                if (!(cin >> intVal))
                    {
                    cout << "Error reading int, please try again...\n";
                    FlushInstream();
                    continue;
                    }
                // add the new item to the queue
                try {
                    myQueue.Enqueue(intVal);
                    cout << intVal << " added to the queue" << endl;
                    }
                catch (const CQueueEx  &queueEx)
                    {
                    if (Q_ERROR == queueEx.GetExType())
                        {
                        cout << "Error inserting " << intVal << "..." << endl;
                        }
                    }
                break;

            case   'R':     // remove an item from the queue
                try {
                    myQueue.Dequeue(intVal);
                    cout << intVal << " removed from the queue" << endl;
                    }
                catch (const CQueueEx  &queueEx)
                    {
                    if (Q_EMPTY == queueEx.GetExType())
                        {
                        cout << "Queue is already empty..." << endl;
                        }
                    else
                        {
                        cout << "Unable to dequeue an item..." << endl;
                        }
                    }
                break;

            case   'C':     // clear the queue of all items
                numItems = myQueue.DestroyQueue();
                cout << "There"
                     << (numItems == 1 ? " was " : " were " )
                     << numItems
                     << " item"
                     << (numItems == 1 ? " " : "s ")
                     << "removed from the queue."
                     << endl;
                break;

            case   'Q':     // quit the program
                bLoop = false;
                break;

            default:
                cout << "Unrecognized selection; please try again...\n\n";
                break;
            }

        cout << endl;

        } while (true == bLoop);

    return 0;

}  // end of "main"

// ==== DisplayMenu ===========================================================
//
// This function simply displays the list of menu options available to the
// user.
//
// Input:  nothing
// Output: nothing
//
// ============================================================================

void    DisplayMenu(void)
{
    cout << "A)dd an item to the queue\n";
    cout << "R)emove an item from the queue\n";
    cout << "C)lear the queue\n";
    cout << "Q)uit\n";

}  // end of "DisplayMenu"



// ==== FlushInstream =========================================================
//
// This function displays the current contents of the list to the standard
// output stream.
//
// Input:
//      inStream    -- a reference to the input stream to flush
//
// Output:
//      Nothing.
//
// ============================================================================

void    FlushInstream(istream  &inStream)
{
    char        inChar;

    inStream.clear();
    while (false == inStream.eof())
        {
        inStream.get(inChar);
        if ('\n' == inChar)
            {
            break;
            }
        }

}  // end of "FlushInstream"
