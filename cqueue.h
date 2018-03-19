// ============================================================================
// File: cqueue.h (Spring 2018)
// ============================================================================
// Header file for the CQueue class.
// NOTE: This version supports exception handling.
// ============================================================================

#ifndef CQUEUE_H
#define CQUEUE_H

#include    "csimplelist.h"

// type definitions
typedef ListType    QueueType;   // can use other basic types here

// enumerated list for the exception class
enum    QueueExType { Q_EMPTY, Q_ERROR };

// exception class for CQueue
class   CQueueEx
{
public:
    CQueueEx(QueueExType  exType) : m_exType(exType) {}
    QueueExType  GetExType() const { return  m_exType; }

private:
    QueueExType      m_exType;
};

class   CQueue
{
public:
    // constructors and destructor
    CQueue() {}

    // member functions
    int     DestroyQueue();
    void    Dequeue();
    void    Dequeue(QueueType  &queueItem);
    void    Enqueue(const QueueType  &newItem);
    void    Retrieve(QueueType  &item) const;
    bool    IsEmpty() const { return (m_list.IsEmpty()); }

private:
    // data members
    CSimpleList m_list;
};

#endif  // CQUEUE_H
