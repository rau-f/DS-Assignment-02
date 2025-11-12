#include "SLL.hpp"


// Task # 01: Reverse Linked List
Node* SLL::Reverse()
{
    if (IsEmpty())
    {
        std::cout << "list underflow!" << std::endl;
        return nullptr;
    }

    Node* prev = m_Head;
    Node* tN = m_Head->next;
    Node* next;

    while (tN)
    {
        next = tN->next;
        tN->next = prev;

        prev = tN;
        tN = next;
    }

    m_Head->next = nullptr;

    Node* temp = m_Head;
    m_Head = m_Tail;
    m_Tail = temp;

    return m_Head;
}


// Task # 02: Merge Two Sorted Lists
Node* SLL::Merge(Node* tN2)
{
    if (!m_Head || !tN2) return nullptr;

    Node* newHead, *newTN;
    Node* tN1 = m_Head;

    while (tN1 && tN2)
    {
        if (tN1->data < tN2->data)
        {
            if (!newHead)
                newHead = newTN = tN1;
            else
            {
                newTN->next = tN1;
                newTN = newTN->next;
            }

            tN1 = tN1->next;
        }
        else
        {
            if (!newHead)
                newHead = newTN = tN2;
            else
            {
                newTN->next = tN2;
                newTN = newTN->next;
            }
            
            tN2 = tN2->next;
        }
    }

    if (tN1)
        newTN->next = tN1;
    else if (tN2)
        newTN->next = tN2;

    return newHead;
}


// Task # 05: Linked List Cycle Detection
bool SLL::DetectCycle()
{
    
}