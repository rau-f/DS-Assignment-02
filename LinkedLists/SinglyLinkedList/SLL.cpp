#include "SLL.hpp"


Node::Node(int data, Node* next)
{
    this->data = data;
    this->next = next;
}


SLL::SLL(Node* head)
{
    m_Head = head;
    m_Tail = head;
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
    if (IsEmpty())
    {
        m_Head = new Node(value);
        m_Tail = m_Head;
        return;
    }

    m_Tail->next = new Node(value);
    m_Tail = m_Tail->next;
}


void SLL::Prepend(int value)
{
    if (IsEmpty())
    {
        m_Head = new Node(value);
        m_Tail = m_Head;
        return;
    }

    Node* newNode = new Node(value);

    newNode->next = m_Head;
    m_Head = newNode;
}


void SLL::Insert(int value, int target)
{
    if (IsEmpty())
    {
        m_Head = new Node(value);
        m_Tail = m_Head;
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
    if (IsEmpty() || !m_Head->next)
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


bool SLL::IsEmpty()
{
    return (m_Head == nullptr);
}


Node* SLL::GetHead()
{
    return m_Head;
}


Node* SLL::GetHead() const
{
    return m_Head;
}


void SLL::SetHead(Node* head)
{
    m_Head = head;
}