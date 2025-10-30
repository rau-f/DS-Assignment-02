#pragma once

#include <iostream>
// #include <fstream>


class ArrayList
{
private:
    int* m_Data;
    unsigned int m_Size;
    unsigned int m_Capacity;
    
public:
    ArrayList(unsigned int capacity);
    ~ArrayList();

    void Insert(unsigned int index, int value);
    void DeleteValue(int value);
    void DeleteValueAt(unsigned int index);
    void UpdateCapacity(unsigned int capacity);
    void Swap(int& a, int& b);
    void Print();
    unsigned int Search(int value);

    void Sort();
    void SortHalf(unsigned int left, unsigned int right);
    void Merge(unsigned int left, unsigned int right, unsigned int length);

    bool IsFull();
    bool IsEmpty();
    bool IsValidIndex(unsigned int index);

    unsigned int GetSize();
    unsigned int GetCapacity();

    int& operator[](unsigned int index);
    friend std::ostream& operator << (std::ostream& stream, const ArrayList& list);


    // Tasks
    void RemoveDuplicates();
    void PrintLongestSeq();
    void PrintTriplets();
    void MoveZeros();
};