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
    for (unsigned int i = 0; i < m_Size; i++)
        for (unsigned int j = i + 1; j < m_Size; j++)
            for (unsigned int k = j + 1; k < m_Size; k++)
            {
                if (m_Data[i] + m_Data[j] + m_Data[k] == 0)
                    std::cout << "[" << m_Data[i] << ", " << m_Data[j] << ", " << m_Data[k] << "]" << std::endl;
            }
}


// Task # 04: Move Zeros To End
void ArrayList::MoveZeros()
{
    unsigned int nonZeroSize = m_Size;
    for (unsigned int i = 0; i < nonZeroSize; i++)
    {
        if (m_Data[i] == 0)
        {
            for (unsigned int j = i; j < nonZeroSize - 1; j++)
                m_Data[j] = m_Data[j + 1];
            
            m_Data[nonZeroSize - 1] = 0;
            nonZeroSize--;
            i--;
        }
    }
}


// Task # 05: Majority Element (Boyer-Moore Voting Algorithm)
int ArrayList::FindMajorityElem()
{
    int candidate;
    unsigned int votes = 0;

    for (unsigned int i = 0; i < m_Size; i++)
    {
        if (votes == 0)
        {
            candidate = m_Data[i];
            votes = 1;
        }
        else if (candidate == m_Data[i]) votes++;
        else votes--;
    }

    // Even though it's guaranteed by the problem that majority element would always 
    // exists like Leetcode problem 169, but I'm initializing array randomly,
    // therefore I need to verify if it is there.

    votes = 0;

    for (unsigned int i = 0; i < m_Size; i++)
        if (m_Data[i] == candidate)
            votes++;

    return (votes > m_Size / 2 ? candidate : -1);
}


// Task # 06: Number Of Subarrays That Sums to K
int ArrayList::CountSubArrSum(int k)
{
    int subArrayCount = 0;
    int sum = 0;

    for (int i = 0; i < m_Size; i++)
    {
        sum = m_Data[i];

        if (sum == k) // Subarray of length 1
            subArrayCount++;

        for (int j = i + 1; j < m_Size; j++)
        {
            sum += m_Data[j];
            
            if (sum == k)
                subArrayCount++;
        }
    }

    return subArrayCount;
}


// Task # 07: Longest Subarray with Sum ≤ K
int ArrayList::GetLongestSubArrayLen(int k)
{
    int sum = 0;
    int prevLen = 0;
    int currLen = 0;

    for (int i = 0; i < m_Size && prevLen < (m_Size - i); i++)
    {
        sum = m_Data[i];

        for (int j = i + 1; j < m_Size; j++)
        {
            sum += m_Data[j];

            if (sum <= k)
                currLen = j - i + 1;
        }

        if (prevLen < currLen)
            prevLen = currLen;

        currLen = 0;
    }

    return prevLen;
}