#include "Stack.hpp"


struct StackList::Node
{
    int data;
    Node* next;
};


StackList::StackList()
    : m_Top(nullptr)
{
}


void StackList::Push(int value)
{
    if (IsEmpty())
    {
        m_Top = new Node{value, nullptr};
        return;
    }

    Node* temp = m_Top;
    m_Top = new Node{value, temp};
}


void StackList::Pop()
{
    if (IsEmpty())
    {
        std::cout << "Stack Underflow!" << std::endl;
        return;
    }

    Node* temp = m_Top;
    m_Top = m_Top->next;

    delete temp;
}


int StackList::Peek()
{
    if (IsEmpty())
    {
        std::cout << "Stack is empty!" << std::endl;
        return -1;
    }

    return m_Top->data;
}


bool StackList::IsEmpty()
{
    return m_Top == nullptr;
}