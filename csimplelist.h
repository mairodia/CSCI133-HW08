// ============================================================================
// File: CSimpleList.h (Spring 2018)
// ============================================================================
// Header file for the CSimpleList class.
// ============================================================================

#ifndef CSIMPLE_LIST_HEADER
#define CSIMPLE_LIST_HEADER

// enable this #define symbol to see debug output
#define DEBUG_LIST

// type definitions
typedef int     ListType;
enum    ListExType { L_FULL
                   , L_EMPTY
                   , L_ERROR
                   , L_SUCCESS
                   , L_INVALID_INDEX
                   , L_DUPLICATE
                   , L_NOT_EXIST
                };

// constants
const   int     DEFAULT_LISTSIZE = 5;
const   int     MOVE_TO_BACK = 0;
const   int     MOVE_TO_FRONT  = 1;


// exception class for CSimpleList
class   CListEx
{
public:
    CListEx(ListExType  exType) : m_exType(exType) {}
    ListExType  GetExType() const { return  m_exType; }

private:
    ListExType      m_exType;
};


// class declaration
class   CSimpleList
{
public:
    // constructor and destructor
    CSimpleList();
    CSimpleList(const CSimpleList  &otherList);
    ~CSimpleList()  { DestroyList(); }

    // member functions
    int     DestroyList();
    void    GetItem(int  index, ListType  &item) const;
    int     GetNumItems() const { return (m_numItems); }
    void    Insert(int  index, const ListType  &newItem);
    bool    IsEmpty() const { return (0 == m_numItems); }
    bool    IsFull() const { return (m_currMax == m_numItems); }
    void    Remove(int  index);
    void    SetListSize(int  numItems);

    // overloaded operators
    CSimpleList&    operator=(const CSimpleList &rhs);

private:
    // data members
    int         m_currMax;
    int         m_numItems;
    ListType    *m_items;

    // member functions
    void        CopyList(const CSimpleList  &otherList);
    int         MoveItems(int  targetIndex, int  direction);
};

#endif  // CSIMPLE_LIST_HEADER
