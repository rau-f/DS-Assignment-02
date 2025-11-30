#include "Stack.hpp"


StackArray::StackArray(int cap)
    : m_Cap(cap), m_Top(-1), m_Size(0)
{
    m_Data = new int[m_Cap];
}


StackArray::~StackArray()
{
    delete[] m_Data;
}


void StackArray::Push(int value)
{
    if (m_Size == m_Cap)
    {
        std::cout << "StackArray Overflow!" << std::endl;
        return;
    }

    m_Data[++m_Top] = value;
    m_Size++;
}


int StackArray::Pop()
{
    if (IsEmpty())
    {
        std::cout << "StackArray Underflow!" << std::endl;
        return;
    }

    m_Top--;
    m_Size--;

    return m_Data[m_Top + 1];
}


int StackArray::Peek()
{
    if (IsEmpty())
    {
        std::cout << "StackArray is empty!" << std::endl;
        return -1;
    }

    return m_Data[m_Top];
}


bool StackArray::IsEmpty()
{
    return m_Size == 0;
}


void StackArray::Print()
{
    if (IsEmpty())
    {
        std::cout << "StackArray is empty!" << std::endl;
        return;
    }

    for (int i = m_Top; i >= 0; i--)
    {
        std::cout << m_Data[i] << " ";
    }
    std::cout << std::endl;
}