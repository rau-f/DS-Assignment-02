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
    if (!m_Head)
    {
        m_Head = list2.m_Head;
        m_Tail = list2.m_Tail;
        m_Size = list2.m_Size;
        list2.m_Head = nullptr;
        list2.m_Tail = nullptr;
        list2.m_Size = 0;
        return;
    }

    if (!list2.m_Head)
        return;
    
    this->BreakCircle();
    list2.BreakCircle();

    Node dummy(0);
    Node* last = &dummy;
    
    Node* a = m_Head;
    Node* b = list2.m_Head;

    while (a && b)
    {
        if (a->data <= b->data)
        {
            last->next = a;
            a->prev = last;
            a = a->next;
        }
        else
        {
            last->next = b;
            b->prev = last;
            b = b->next;
        }

        last = last->next;
    }

    Node* rest = (a ? a : b);

    if (rest)
    {
        last->next = rest;
        rest->prev = last;

        while (last->next)
            last = last->next;
    }

    m_Head = dummy.next;
    m_Tail = last;
    m_Size += list2.m_Size;
    m_Head->prev = nullptr;

    list2.m_Head = nullptr;
    list2.m_Tail = nullptr;
    list2.m_Size = 0;
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


// Task # 09: Reverse Doubly Linked List in Groups of K
void DLL::ReverseInGroups(int k)
{
    if (k <= 1 || !m_Head) return;
    
    Node* current = m_Head;
    Node* prevTail = nullptr;
    Node* newHead = nullptr;
    
    while (current) {
        Node* groupStart = current;
        int count = 0;
        
        // Count k nodes
        while (current && count < k)
        {
            current = current->next;
            count++;
        }
        
        if (count < k)
        {
            // Connect remaining nodes
            if (prevTail)
                prevTail->next = groupStart;
            else
                newHead = groupStart;
            if (groupStart)
                groupStart->prev = prevTail;

            break;
        }
        
        // Reverse k nodes
        Node* prev = nullptr;
        Node* temp = groupStart;

        for (int i = 0; i < k; i++)
        {
            Node* next = temp->next;
            temp->next = prev;
            temp->prev = next;
            if (prev) prev->prev = temp;
            prev = temp;
            temp = next;
        }
        
        // Connect with previous group
        if (prevTail)
        {
            prevTail->next = prev;
            prev->prev = prevTail;
        }
        else
            newHead = prev;

        prevTail = groupStart;
    }
    
    m_Head = newHead;
    
    // Update tail
    m_Tail = m_Head;

    while (m_Tail && m_Tail->next)
        m_Tail = m_Tail->next;
}


// Task # 10: Split a Circular Doubly Linked List into Two Halves
void DLL::SplitCircularIntoHalves(DLL& list1, DLL& list2)
{
    if (!m_Head || !IsCircular())
    {
        list1 = *this;
        return;
    }

    int count = m_Size;

    // Find middle node
    Node* middle = m_Head;
    for (int i = 0; i < count / 2 - 1; i++)
    {
        middle = middle->next;
    }

    Node* firstHead = m_Head;
    Node* secondHead = middle->next;

    // Make first half circular
    middle->next = firstHead;
    firstHead->prev = middle;

    // Make second half circular
    Node* tail = m_Tail;
    tail->next = secondHead;
    secondHead->prev = tail;

    // Set up the two lists
    list1.SetHead(firstHead);
    list1.SetTail(middle);
    list1.m_Size = count / 2;

    list2.SetHead(secondHead);
    list2.SetTail(tail);
    list2.m_Size = m_Size - count / 2;

    m_Head = m_Tail = nullptr;
    m_Size = 0;
}