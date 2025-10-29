#include "ArrayList.hpp"


// Task # 01: Remove Duplicates from Sorted Array
void ArrayList::RemoveDuplicates()
{
    for (unsigned int i = 0; i < m_Size; i++)
        for (unsigned int j = i+1; j < m_Size; j++)
            if (m_Data[i] == m_Data[j])
                DeleteValueAt(j--);

    int* secArray = new int[m_Size];

    for (unsigned int i = 0; i < m_Size; i++)
        secArray[i] = m_Data[i];

    delete[] m_Data;
    m_Data = secArray;
}


// Task # 02: Longest Consecutive Sequence
void ArrayList::PrintLongestSeq()
{
    unsigned int prevSqLen = 1, prevStart = 0;      // To hold previous sequence data
    unsigned int sqLen = 1, start = 0;              // To hold current sequence data
    int prevVal = m_Data[0], currVal;

    Sort();
    RemoveDuplicates();

    for (unsigned int i = 1; i < m_Size; i++)
    {
        currVal = m_Data[i];

        if (currVal == prevVal + 1)
        {
            if (sqLen == 1)
                start = i - 1;

            sqLen++;
        }
        else if (prevSqLen < sqLen)
        {
            prevStart = start;
            prevSqLen = sqLen;
            sqLen = 1;
        }

        prevVal = currVal;
    }

    if (prevSqLen < sqLen)
    {
        prevStart = start;
        prevSqLen = sqLen;
    }

    unsigned int count = prevSqLen + prevStart;

    std::cout << "Longest Sequence: [";
    for (unsigned int i = prevStart; i < count; i++)
        std::cout << m_Data[i] << (i == count - 1 ? "]" : " ");
}


// Task # 03: Find Triplets that Sum to Zero
void ArrayList::PrintTriplets()
{

}