#include "Queue.hpp"


struct QueueList::Node
{
    int data;
    Node* next;
};


QueueList::QueueList()
    : m_Front(nullptr), m_Rear(nullptr), m_Size(0)
{
}


void QueueList::Enqueue(int value)
{
    if (IsEmpty())
        m_Front = m_Rear = new Node{value, nullptr};
    else
    {
        m_Rear->next = new Node{value, nullptr};
        m_Rear = m_Rear->next;
    }

    m_Size++;
}


int QueueList::Dequeue()
{
    if (IsEmpty())
    {
        std::cout << "Queue is empty!" << std::endl;
        return -1;
    }

    Node* node = m_Front;
    m_Front = m_Front->next;

    int retValue = node->data;
    delete node;

    m_Size--;

    return retValue;
}


int QueueList::Front()
{
    if (IsEmpty())
    {
        std::cout << "Queue is empty!" << std::endl;
        return -1;
    }

    return m_Front->data;
}


bool QueueList::IsEmpty()
{
    return m_Size == 0;
}