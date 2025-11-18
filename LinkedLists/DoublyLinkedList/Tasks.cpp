#include "DLL.hpp"


// Task # 01: Insert a Node in a Sorted Doubly Linked List
void DLL::InsertInSortedList(int value)
{
    if (!m_Head)
    {
        Append(value);
        return;
    }

    Node* tN = m_Head;
    
    do
    {
        if (value < tN->data) break;
        tN = tN->next;
    } while (tN->next != m_Tail->next);

    if (tN == m_Tail && tN->data < value)
    {
        Append(value);
        return;
    }

    if (tN == m_Head)
    {
        Prepend(value);
        return;
    }

    Node* newNode = new Node(value, tN->prev, tN);
    tN->prev = newNode;

    if (newNode->prev)
        newNode->prev->next = newNode;

    m_Size++;
}


// Task # 02: Delete All Occurrences of a Given Key
void DLL::DelOuccKey(int key)
{
    Node* toDelete = Search(key);

    while (toDelete)
    {
        Delete(toDelete->data);
        toDelete = Search(key);
    }
}


// Task # 03: Find Pairs with a Given Sum
void DLL::PrintPairs(int sum)
{
    if (!m_Head)
    {
        std::cout << "[PrintPairs]: List Empty!" << std::endl;
        return;
    }

    Node* left = m_Head;
    Node* right = m_Tail;

    std::cout << left->data << " " << right->data << std::endl;

    while (left->data <= right->data)
    {
        if (left->data + right->data > sum)
        {
            right = right->prev;
        }
        else if (left->data + right->data < sum)
        {
            left = left->next;
        }
        else
        {
            std::cout << "(" << left->data << ", " << right->data << ") ";
            left = left->next;
            right = right->prev;
        }
        
    }
}


// Task # 04: Rotate Doubly Linked List by N Nodes
void DLL::RotateByN(int n)
{
    if (n > m_Size)
    {
        std::cout << "[RotateByN]: Rotation not possible!" << std::endl;
        return;
    }

    bool wasCircular = IsCircular();
    MakeCircular();

    for (int i = 0; i < n; i++)
    {
        m_Head = m_Head->next;
        m_Tail = m_Tail->next;
    }

    if (!wasCircular)
        BreakCircle();
}


// Task # 04: Merge Two Sorted Doubly Linked Lists
DLL* DLL::Merge(DLL &list2)
{
    if (!m_Head && !list2.GetHead())
    {
        std::cout << "[Merge]: Both lists empty!" << std::endl;
        return nullptr;
    }

    Node* tN1 = m_Head;
    Node* tN2 = list2.GetHead();

    DLL* newList = new DLL();

    while (tN1 && tN2)
    {
        if (tN1->data < tN2->data)
        {
            newList->Append(tN1->data);
            tN1 = tN1->next;
        }
        else
        {
            newList->Append(tN2->data);
            tN2 = tN2->next;
        }
    }

    while (tN1)
    {
        newList->Append(tN1->data);
        tN1 = tN1->next;
    }

    while (tN2)
    {
        newList->Append(tN2->data);
        tN2 = tN2->next;
    }

    return newList;
}


// Task # 06: Convert Binary Tree to Doubly Linked List