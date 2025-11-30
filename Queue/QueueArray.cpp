#include "Queue.hpp"


QueueArray::QueueArray(int cap)
    : m_Front(-1), m_Rear(-1), m_Cap(cap), m_Size(0)
{
    m_Data = new int[m_Cap];
}


QueueArray::~QueueArray()
{
    delete[] m_Data;
}


void QueueArray::Enqueue(int value)
{
    if (IsFull())
    {
        std::cout << "Queue Overflow!" << std::endl;
        return;
    }

    if (IsEmpty())
        m_Front = m_Rear = 0;
    else
        m_Rear = (m_Rear + 1) % m_Cap;

    m_Data[m_Rear] = value;
    m_Size++;
}


int QueueArray::Dequeue()
{
    if (IsEmpty())
    {
        std::cout << "Queue Underflow!" << std::endl;
        return;
    }

    int index = m_Front;
    m_Front = (m_Front + 1) % m_Cap;

    m_Size--;

    return m_Data[index];
}


int QueueArray::Front()
{
    if (IsEmpty())
    {
        std::cout << "Queue is empty!" << std::endl;
        return -1;
    }

    return m_Data[m_Front];
}


bool QueueArray::IsEmpty()
{
    return m_Size == 0;
}


bool QueueArray::IsFull()
{
    return m_Size == m_Cap;
}


// Task # 04: Reverse first k elements
void QueueArray::ReverseKElem(int k)
{
    if (k <= 0) return;
    if (k > m_Size)
    {
        std::cout << "Not enough elements!" << std::endl;
        return;
    }

    int* array = new int[k];
    for (int i = 0; i < k; i++)
        array[i] = Dequeue();
    
    for (int i = k - 1; i >= 0; i--)
        Enqueue(array[i]);

    for (int i = 0; i < m_Size - k; i++)
        Enqueue(Dequeue());

    delete[] array;
}


// Task # 05: Check Palindrome
bool QueueArray::IsPalindorme()
{
    if (IsEmpty())
    {
        std::cout << "Queue is empty!" << std::endl;
        return true;
    }

    int front = m_Front;
    int rear = m_Rear;
    int size = m_Size;

    int* array = new int[size / 2];

    for (int i = 0; i < size / 2; i++)
        array[i] = Dequeue();
    
    if (size % 2 != 0)
        Dequeue();

    for (int i = (size / 2) - 1; i >= 0; i++)
        if (array[i] != Dequeue())
        {
            m_Front = front;
            m_Rear = rear;
            return false;
        }

    m_Front = front;
    m_Rear = rear;
    m_Size = size;
    
    return true;
}