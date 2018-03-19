// ============================================================================
// File: ListDriver.cpp (Spring 2018)
// ============================================================================
// This is a driver program to test the list ADT "CSimpleList".  It creates a
// list, inserts items into the list and displays the list contents.  It also
// allows the user to remove and insert items in the list.
// ============================================================================

#include    <iostream>
#include    <limits>
#include    <cstdlib>
#include    <cctype>
using namespace std;
#include    "csimplelist.h"

// function prototypes
void    DisplayList(const CSimpleList  &list);
void    DisplayMenu();
void    FlushInstream(istream  &inStream = cin);



// ==== main ==================================================================
//
// ============================================================================

int     main()
{
    bool                bLoop = true;
    char                selection;
    CSimpleList         myList;
    int                 intVal;
    int                 index;

    // let the user manipulate the list
    do  {
        DisplayMenu();
        cout << "Please enter a selection: ";

        cin >> selection;
        switch (toupper(selection))
            {
            case   'A':
                // try to get a valid item and index from the user
                cout << "Please enter a value to add to the list: ";
                if (!(cin >> intVal))
                    {
                    cout << "Error reading int, please try again...\n" << endl;
                    FlushInstream();
                    continue;
                    }

                cout << "Please enter a zero-based index for the new item: ";
                if (!(cin >> index))
                    {
                    cout << "Error reading int, please try again...\n" << endl;
                    FlushInstream();
                    continue;
                    }

                // insert the new item into the list
                try {
                    myList.Insert(index, intVal);
                    }
                catch (const CListEx  &ex)
                    {
                    if (L_FULL == ex.GetExType())
                        {
                        cout << "Sorry, the list is currently full...\n";
                        }
                    else if (L_INVALID_INDEX == ex.GetExType())
                        {
                        cout << "Sorry, invalid index...\n";
                        }
                    }
                break;

            case   'R':
                // if the list is empty, display an error message
                if (myList.IsEmpty())
                    {
                    cout << "Sorry, the list is currently empty...\n" << endl;
                    continue;
                    }

                // try to get a valid index from the user
                cout << "Please enter a zero-based index for the item "
                                                        << "to remove: ";
                if (!(cin >> index))
                    {
                    cout << "Error reading int, please try again...\n" << endl;
                    FlushInstream();
                    continue;
                    }

                // remove the item from the list
                try {
                    myList.Remove(index);
                    }
                catch (const CListEx  &ex)
                    {
                    if (L_INVALID_INDEX == ex.GetExType())
                        {
                        cout << "Sorry, invalid index...\n";
                        }
                    }
                break;

            case   'D':
                cout << "Here is the current list:\n";
                DisplayList(myList);
                break;

            case   'Q':
                bLoop = false;
                break;

            default:
                cout << "Unrecognized selection; please try again..." << endl;
                FlushInstream();
                break;
            }

        cout << endl;

        } while (true == bLoop);

    return  0;

}  // end of "main"



// ==== DisplayMenu ===========================================================
//
// This function displays a list of options to stdout.
//
// Input:  nothing
//
// Output: nothing
//
// ============================================================================

void    DisplayMenu()
{
    cout << "A)dd an item\n";
    cout << "R)emove an item\n";
    cout << "D)isplay the list\n";
    cout << "Q)uit\n";

}  // end of "DisplayMenu"



// ==== DisplayList ===========================================================
//
// This function displays the current contents of the list to the standard
// output stream.
//
// Input:
//      list    -- a const reference to a CSimpleList object
//
// Output:
//      Nothing.
//
// ============================================================================

void    DisplayList(const CSimpleList  &list)
{
    int             index;
    ListType        listItem;

    for (index = 0; index < list.GetNumItems(); ++index)
        {
        list.GetItem(index, listItem);
        cout << listItem << endl;
        }
}  // end of "DisplayList"



// ==== FlushInstream =========================================================
//
// This function displays the current contents of the list to the standard
// output stream.
//
// Input:
//      list    -- a const reference to a CSortedList object
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
} // end of "FlushInstream"

