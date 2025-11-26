#include "DLL.hpp"


Node::Node(int data, Node* prev, Node* next)
    : prev(prev), next(next)
{
    this->data = data;
}


DLL::DLL()
    : m_Head(nullptr), m_Tail(nullptr), m_Size(0)
{
}


DLL::~DLL()
{
    Clear();
}


void DLL::Clear()
{
    if (!m_Head)
        return;

    Node* tN = m_Head->next;
    Node* temp = nullptr;

    while (tN && tN != m_Head)
    {
        temp = tN;
        tN = tN->next;

        delete temp;
    }
    
    delete m_Head;

    m_Head = nullptr;
    m_Tail = nullptr;

    m_Size = 0;
}


void DLL::Append(int value)
{
    if (!m_Head)
    {
        m_Head = m_Tail = new Node(value);
        m_Size++;
        return;
    }

    m_Tail->next = new Node(value, m_Tail, m_Tail->next);
    m_Tail = m_Tail->next;
    
    if (m_Head->prev)
        m_Head->prev = m_Tail;

    m_Size++;
}


void DLL::Prepend(int value)
{
    if (!m_Head)
    {
        m_Head = m_Tail = new Node(value);
        return;
    }

    Node* newNode = new Node(value, m_Head->prev, m_Head);
    m_Head->prev = newNode;
    m_Head = newNode;

    if (m_Tail->next)
        m_Tail->next = newNode;

    m_Size++;
}


void DLL::Insert(int value, int target)
{
    Node* curr = Search(target);

    if (!curr)
    {
        std::cout << "Target not found!" << std::endl;
        return;
    }

    Node* newNode = new Node(value, curr, curr->next);
    curr->next = newNode;

    if (newNode->next)
        newNode->next->prev = newNode;

    m_Size++;
}


void DLL::Delete(int target)
{
    Node* toDelete = Search(target);

    if (!toDelete)
    {
        std::cout << "[Delete]: target not found!" << std::endl;
        return;
    }


    if (toDelete->next)
        toDelete->next->prev = toDelete->prev;
    
    if (toDelete->prev)
        toDelete->prev->next = toDelete->next;

    if (toDelete == m_Head)
        m_Head = m_Head->next;
    else if (toDelete == m_Tail)
        m_Tail = m_Tail->prev;

    delete toDelete;

    m_Size--;
}


void DLL::Sort()
{
    if (!m_Head)
    {
        std::cout << "[Sort]: List empty!" << std::endl;
        return;
    }

    Node* curr = m_Head;
    Node* next = nullptr;

    do
    {
        next = curr->next;
        while (next != m_Tail->next)
        {
            if (curr->data > next->data)
            {
                int temp = curr->data;
                curr->data = next->data;
                next->data = temp;
            }

            next = next->next;
        }

        curr = curr->next;
    } while (curr != m_Tail->next);
}


void DLL::MakeCircular()
{
    if (!m_Head) return;
    m_Head->prev = m_Tail;
    m_Tail->next = m_Head;
}


void DLL::BreakCircle()
{
    if (!m_Head) return;
    m_Head->prev = nullptr;
    m_Tail->next = nullptr;
}


void DLL::Print()
{
    Node* tN = m_Head;
    int i = 0;

    std::cout << "[";
    do
    {
        std::cout << tN->data << (i == m_Size - 1 ? "]" : ", ");
        i++;
        tN = tN->next;
    } while (tN != m_Tail->next);
    std::cout << std::endl;
}


Node* DLL::Search(int target)
{
    if (!m_Head)
    {
        std::cout << "[Search]: Empty list!" << std::endl;
        return nullptr;
    }

    Node* tN = m_Head;

    do
    {
        if (tN->data == target)
        {
            return tN;
        }

        tN = tN->next;
    } while (tN != m_Tail->next);
    
    return nullptr;
}


bool DLL::IsCircular()
{
    return m_Head->prev == m_Tail && m_Tail->next == m_Head;
}


Node* DLL::GetHead()
{
    return m_Head;
}


Node* DLL::GetTail()
{
    return m_Tail;
}


int DLL::GetSize()
{
    return m_Size;
}


void DLL::SetHead(Node* head)
{
    m_Head = head;
}


void DLL::SetTail(Node* tail)
{
    m_Tail = tail;
}