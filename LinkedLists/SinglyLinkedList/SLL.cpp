#include "SLL.hpp"


Node::Node(int data, Node* next)
    : next(next)
{
    this->data = data;
}


SLL::SLL(Node* head)
{
    m_Head = head;
    m_Tail = head;

    if (head)
        m_Size = 1;
    else
        m_Size = 0;
}


SLL::~SLL()
{
    Node* holder;

    while (m_Head)
    {
        holder = m_Head;
        m_Head = m_Head->next;
        delete holder;
    }
}


void SLL::Append(int value)
{
    if (!m_Head)
    {
        m_Head = new Node(value);
        m_Tail = m_Head;
        m_Size++;
        return;
    }

    m_Tail->next = new Node(value);
    m_Tail = m_Tail->next;

    m_Size++;
}


void SLL::Prepend(int value)
{
    if (!m_Head)
    {
        m_Head = new Node(value);
        m_Tail = m_Head;
        m_Size++;
        return;
    }

    Node* newNode = new Node(value);

    newNode->next = m_Head;
    m_Head = newNode;

    m_Size++;
}


void SLL::Insert(int value, int target)
{
    if (!m_Head)
    {
        m_Head = new Node(value);
        m_Tail = m_Head;
        m_Size++;
        return;
    }

    Node* targetNode = Search(target);
    
    if (!targetNode)
    {
        std::cout << "Target not found!" << std::endl;
        return;
    }

    Node* newNode = new Node(value, targetNode->next);
    targetNode->next = newNode;

    m_Size++;
}


void SLL::Delete(int target)
{
    if (!m_Head)
    {
        std::cout << "[Delete]: List Underflow!" << std::endl;
        return;
    }

    Node* curr = m_Head;
    Node* prev = nullptr;

    if (m_Head->data == target)
    {
        m_Head = m_Head->next;
        delete curr;
        m_Size--;
        return;
    }

    while (curr)
    {
        if (curr->data == target)
        {
            prev->next = curr->next;
            delete curr;

            if (!prev->next)
                m_Tail = prev;

            break;
        }

        prev = curr;
        curr = curr->next;
    }
    
    m_Size--;
}


void SLL::Clear()
{
    Node* curr = m_Head;
    
    while (curr != nullptr)
    {
        Node* nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }
    
    m_Head = nullptr;
    m_Tail = nullptr;
    m_Size = 0;
}


Node* SLL::Search(int target)
{
    Node* tN = m_Head;

    while (tN)
    {
        if (tN->data == target)
            return tN;

        tN = tN->next;
    }

    return nullptr;
}


void SLL::Print()
{
    Node* tN = m_Head;

    std::cout << "[";
    while (tN)
    {
        std::cout << tN->data << (tN->next ? ", " : "]");
        tN = tN->next;
    }
    std::cout << std::endl;
}


void SLL::Sort()
{
    if (!m_Head || !m_Head->next)
    {
        std::cout << "Nothing to sort!" << std::endl;
        return;
    }

    for (Node* i = m_Head; i; i = i->next)
    {
        for (Node* j = i->next; j; j = j->next)
        {
            if (j->data < i->data)
            {
                int temp = j->data;
                j->data = i->data;
                i->data = temp;
            }
        }
    }
}

Node* SLL::GetHead()
{
    return m_Head;
}


Node* SLL::GetHead() const
{
    return m_Head;
}


Node* SLL::GetTail()
{
    return m_Tail;
}


Node* SLL::GetTail() const
{
    return m_Tail;
}


int SLL::GetSize()
{
    return m_Size;
}


int SLL::GetSize() const
{
    return m_Size;
}


void SLL::SetHead(Node* head)
{
    m_Head = head;
}