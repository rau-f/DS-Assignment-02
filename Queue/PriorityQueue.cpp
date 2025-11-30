#include "Queue.hpp"


struct PriorityQueue::Item
{
    int data;
    int pr;
};


PriorityQueue::PriorityQueue(int cap)
    : m_Cap(cap), m_Size(0)
{
    m_Data = new Item[m_Cap];
}


PriorityQueue::~PriorityQueue()
{
    delete[] m_Data;
}


void PriorityQueue::Enqueue(int value, int pr)
{
    if (IsFull())
    {
        std::cout << "Queue Overflow!" << std::endl;
        return;
    }

    if(IsEmpty())
    {
        m_Data[m_Size] = {value, pr};
        m_Size++;
        return;
    }

    m_Data[m_Size] = {value, pr};
    m_Size++;

    int n = m_Size - 1;

    while (n > 0 && m_Data[(n - 1) / 2].pr < m_Data[n].pr)
    {
        Swap(m_Data[n], m_Data[(n - 1) / 2]);
        n = (n - 1) / 2;
    }
}


int PriorityQueue::Dequeue()
{
    if (IsEmpty())
    {
        std::cout << "Queue Underflow!" << std::endl;
        return -1;
    }

    int toReturn = m_Data[0].data;
    m_Data[0] = m_Data[--m_Size];

    int i = 0;
    while (true)
    {
        int left = (2 * i) + 1;
        int right = (2 * i) + 2;
        int bigger = i;

        if (left < m_Size && m_Data[left].pr > m_Data[bigger].pr)
            bigger = left;
        else if (right < m_Size && m_Data[right].pr > m_Data[bigger].pr)
            bigger = right;

        if (bigger == i)
            break;

        Swap(m_Data[i], m_Data[bigger]);
        i = bigger;
    }

    return toReturn;
}


int PriorityQueue::Front()
{
    if (IsEmpty())
    {
        std::cout << "Queue is empty!" << std::endl;
        return -1;
    }

    return m_Data[0].data;
}


void PriorityQueue::Swap(Item &a, Item &b)
{
    Item temp = a;
    a = b;
    b = temp;
}


bool PriorityQueue::IsEmpty()
{
    return m_Size == 0;
}


bool PriorityQueue::IsFull()
{
    return m_Size == m_Cap;
}