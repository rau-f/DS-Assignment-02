#include "SLL.hpp"


// Task # 01: Reverse Linked List
Node* SLL::Reverse()
{
    if (!m_Head)
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


// Task # 03: Middle of the Linked List
Node* SLL::FindMiddleNode()
{
    int size = 0;
    Node* tN = m_Head;

    while (tN)
    {
        size++;
        tN = tN->next;
    }

    tN = m_Head;
    
    for (int i = 0; i < size / 2; i++)
        tN = tN->next;

    return tN;
}


// Task # 04: Remove Nth node from end
void SLL::RemoveNodeFromEnd(int n)
{
    if (!m_Head)
    {
        std::cout << "RemoveNFE]: List underflow!" << std::endl;
        return;
    }

    Delete(Search(m_Size - n)->data);
}


// Task # 05: Linked List Cycle Detection
bool SLL::DetectCycle()
{
    Node* addreses[m_Size];
    Node* tN = m_Head;

    for (int i = 0; i < m_Size; i++)
    {
        addreses[i] = tN;
        tN = tN->next;
    }

    for (int i = 0; i < m_Size; i++)
        for (int j = i + 1; j < m_Size; j++)
        {
            if (addreses[i] == addreses[j])
                return true;
        }

    return false;
}


// Task # 07: Reorder List
void SLL::Reorder()
{
    Node* tN = m_Head;

    SLL firstHalf;
    SLL secHalf;

    for (int i = 0; i < m_Size / 2; i++, tN = tN->next)
    {
        firstHalf.Append(tN->data);
    }

    while (tN)
    {
        secHalf.Append(tN->data);
        tN = tN->next;
    }
    
    Clear();

    Node* tN1 = firstHalf.GetHead();
    Node* tN2 = secHalf.GetHead();

    while (tN1 && tN2)
    {
        Append(tN1->data);
        Append(tN2->data);

        tN1 = tN1->next;
        tN2 = tN2->next;
    }
    
    if (tN2) Append(tN2->data);
}


// Task # 08: Remove Duplicates from Sorted List
void SLL::RemoveDupFromSortedList()
{
    if (m_Size < 1) return;

    Node* curr = m_Head;
    Node* nextNode = curr->next;

    while (nextNode)
    {
        if (curr->data == nextNode->data)
        {
            Node* temp = nextNode->next;
            delete nextNode;
            m_Size--;

            curr->next = nextNode = temp;
        }
        else
        {
            curr = nextNode;
            nextNode = nextNode->next;
        }
    }
}


// Task # 09: Reverse Nodes in k-Group
void SLL::ReverseKElem(int k)
{
    if (!m_Size || !k || k == 1)
        return;

    if (m_Size == k)
    {
        Reverse();
        return;
    }

    Node* tN = m_Head;
    SLL kList;
    SLL leftOver;

    for (int i = 0; i < k; i++)
    {
        kList.Append(tN->data);
        tN = tN->next;
    }

    while (tN)
    {
        leftOver.Append(tN->data);
        tN = tN->next;
    }
    
    Clear();
    tN = m_Head;

    kList.Reverse();

    tN = kList.GetHead();
    while (tN)
    {
        Append(tN->data);
        tN = tN->next;
    }
    
    tN = leftOver.GetHead();
    while (tN)
    {
        Append(tN->data);
        tN = tN->next;
    }
}