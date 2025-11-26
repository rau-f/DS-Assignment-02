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


// Task # 05: Merge Two Sorted Doubly Linked Lists
void DLL::Merge(DLL &list2)
{
    Node* tN1 = m_Head;
    Node* tN2 = list2.m_Head;

    if (!tN1)
    {
        m_Head = tN2;
        list2.m_Head = nullptr;
        return;
    }

    if (!tN2)
        return;

    bool wasCircular = IsCircular();
    BreakCircle();

    Node* newHead = nullptr;
    Node* tail = nullptr;

    while (tN1 && tN2)
    {
        Node* smallest;
        if (tN1->data < tN2->data)
        {
            smallest = tN1;
            tN1 = tN1->next;
        }
        else
        {
            smallest = tN2;
            tN2 = tN2->next;
        }

        if (!newHead)
        {
            newHead = smallest;
            tail = smallest;
            tail->prev = nullptr; 
        }
        else
        {
            tail->next = smallest;
            smallest->prev = tail;
            tail = smallest;
        }
    }

    if (tN2)
    {

    }

    m_Head = newHead;
    m_Size += list2.m_Size;

    if (wasCircular)
        MakeCircular();

    list2.m_Head = nullptr;
    list2.m_Tail = nullptr;
}


// Task # 06: Convert Binary Tree to Doubly Linked List
// Pending...


// Task # 07: Find Triplets with Given Sum in a Sorted Doubly Linked List
void DLL::FindTripletsSumToK(int k)
{
    if (m_Size < 3) return;

    bool wasCircular = IsCircular();
    BreakCircle();

    int sum = 0;

    for (Node* i = m_Head; i != nullptr; i = i->next)
    {
        Node* left = i->next;
        Node* right = m_Tail;

        while (left != right && right->next != left)
        {
            sum = i->data + left->data + right->data;
            
            if (sum == k)
            {
                std::cout << "(" << i->data << ", " << left->data << ", " << right->data << ")" << std::endl;
                left = left->next;
                right = right->prev;
            }
            else if (sum < k)
                left = left->next;
            else
                right = right->prev;

            sum = 0;
        }
        
    }

    if (wasCircular)
        MakeCircular();
}


// Task # 08: Merge K Sorted Doubly Linked Lists
void DLL::MergeKSortedLists(int k)
{
    DLL* lists = new DLL[k];

    srand(time(NULL));
    for (int i = 0; i < k; i++)
    {
        int size = (rand() % 4) + 2;
        for (int j = 0; j < size; j++)
        {
            lists[i].Append(rand() % 10);
        }
        
        lists[i].Sort();
        lists[i].Print();
    }
    
    for (int i = 0; i < k; i++)
    {
        Merge(lists[i]);
    }
}