// ===========================================================================================
// File: cqueue.cpp
// ===========================================================================================
// Programmer: Jennifer King
// Date: 3/18/2018
// Project: CQueue
// Professor: Scott Edwards
// Class: CSCI 133F | TR 9:30AM
// Description:
//              This file implelements all the CQueue member functions and constructors.
// ===========================================================================================
#include <iostream>
using namespace std;
#include "cqueue.h"
#include "csimplelist.h"

int CQueue::DestoryQueue()
{
    m_list.DestroyList();
}

void CQueue::Dequeue()
{
    if(IsEmpty() == true)
        {
        CListEx ex(L_EMPTY);
        }
    else
        {
        m_list.Remove(0);
        m_list.SetListSize(m_list.GetNumItems());
        }
}

void CQueue::Dequeue(QueueType &queueItem)
{
    if(IsEmpty() == true)
        {
        CListEx ex(L_EMPTY);
        }
    else
        {
        queueItem = m_list.GetItem(0, queueItem)
        Remove(0);
        m_list.SetListSize(m_list.GetNumItems());
        }
void CQueue::Enqueue(const QueueType &newItem)
{
    if(IsFull() == true)
        {
        CListEx ex(L_FULL);
        }
    else
        {
        int index;
        index = m_list.GetNumItems();
        m_list.Insert(index, newItem);
        }
}

void Retrieve(QueueType &item) const
{
    for(int index = 0; index < m_list.GetNumItems; index++)
        {
        GetItem(index, item);
        }
}
