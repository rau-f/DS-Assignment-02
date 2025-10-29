#include "ArrayList.hpp"


ArrayList::ArrayList(unsigned int capacity)
    : m_Capacity(capacity), m_Size(0)
{
    m_Data = new int[m_Capacity];
}


ArrayList::~ArrayList()
{
    delete[] m_Data;
}


// Functionality

void ArrayList::Insert(unsigned int index, int value)
{
    if (!IsValidIndex(index))
    {
        std::cerr << "Invalid index!" << std::endl;
        return;
    }

    if (IsFull())
    {
        std::cerr << "List Overflow!" << std::endl;
        return;
    }

    if (index >= m_Size)
    {
        m_Data[m_Size++] = value;
        return;
    }

    for (unsigned int i = m_Size; i >= index; i--)
        m_Data[i] = m_Data[i - 1];
    
    m_Data[index] = value;
    m_Size++;
}


void ArrayList::DeleteValue(int value)
{
    DeleteValueAt(Search(value));
}


void ArrayList::DeleteValueAt(unsigned int index)
{
    if (!IsValidIndex(index))
    {
        std::cerr << "Invalid index!" << std::endl;
        return;
    }

    if (IsEmpty())
    {
        std::cerr << "List Underflow!" << std::endl;
        return;
    }

    if (index > m_Size)
    {
        std::cerr << "Invalid index!" << std::endl;
        return;
    }

    for (unsigned int i = index; i < m_Size - 1; i++)
        m_Data[i] = m_Data[i+1];

    m_Size--;
}


void ArrayList::Print()
{
    std::cout << "List: [";

    for (unsigned int i = 0; i < m_Size; i++)
        std::cout << m_Data[i] << (i == m_Size - 1 ? "" : ", ");

    std::cout << "]" << std::endl;
}


unsigned int ArrayList::Search(int value)
{
    for (unsigned int i = 0; i < m_Size; i++)
        if (m_Data[i] == value) return i;

    return -1; // value not found
}


void ArrayList::UpdateCapacity(unsigned int capacity)
{
    if (capacity == m_Capacity) return;

    if (capacity < m_Capacity)
        m_Size = capacity;

    int* secArray = new int[capacity];
    
    for (unsigned int i = 0; i < m_Capacity; i++)
        secArray[i] = m_Data[i];

    m_Capacity = capacity;

    delete[] m_Data;
    m_Data = secArray;
}


void ArrayList::Sort()
{
    if (!m_Size || m_Size == 1)
    {
        std::cout << "Not enough elements to sort!" << std::endl;
        return;
    }

    SortHalf(0, m_Size - 1);
}


void ArrayList::SortHalf(unsigned int left, unsigned int right)
{
    if (left >= right) return;

    unsigned int mid = (left + right) / 2;

    SortHalf(left, mid);
    SortHalf(mid + 1, right);
    Merge(left, mid, right);
}


void ArrayList::Merge(unsigned int left, unsigned int mid, unsigned int right)
{
    const unsigned int len = right - left + 1;
    int array[len];

    int lIndex = left;
    int rIndex = mid + 1;
    unsigned int i = 0;

    while (lIndex <= mid && rIndex <= right)
    {
        if (m_Data[lIndex] < m_Data[rIndex])
            array[i] = m_Data[lIndex++];
        else
            array[i] = m_Data[rIndex++];

        i++;
    }

    while (lIndex <= mid)
        array[i++] = m_Data[lIndex++];

    while (rIndex <= right)
        array[i++] = m_Data[rIndex++];
    

    i = 0;
    for (unsigned int j = left; i < len; i++, j++)
        m_Data[j] = array[i];
}


void ArrayList::Swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}


// bool Functions

bool ArrayList::IsFull()
{
    return m_Size == m_Capacity;
}


bool ArrayList::IsEmpty()
{
    return m_Size == 0;
}


bool ArrayList::IsValidIndex(unsigned int index)
{
    return (index >= 0 && index < m_Capacity);
}


// Getters

unsigned int ArrayList::GetSize()
{
    return m_Size;
}


unsigned int ArrayList::GetCapacity()
{
    return m_Capacity;
}


// Operator Overloads

int& ArrayList::operator[](unsigned int index)
{
    return m_Data[index];
}


std::ostream& operator << (std::ostream& stream, const ArrayList& list)
{
    stream << "[";
    for (unsigned int i = 0; i < list.m_Size; i++)
        stream << list.m_Data[i] << (i == list.m_Size - 1 ? "" : ", ");
    stream << "]";

    return stream;
}