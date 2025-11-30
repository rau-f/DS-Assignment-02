#pragma once
#include <iostream>


// Task # 01: Implement a stack using arrays
class StackArray
{
private:
    int* m_Data;
    int m_Top;
    int m_Cap;
    int m_Size;

public:
    StackArray(int cap);
    ~StackArray();

    void Push(int value);
    int Pop();
    int Peek();
    bool IsEmpty();
    void Print();

    // Task # 03 and so on...
    void Reverse();
    void SortStack();
    void RemoveMiddle(int curr = 0);
    bool CheckParenthesis(int curr = 0);
    int* NextGreater(int* array, int size);
    bool CheckPalindrome();
    
    // Helper functions
    void InsertAtBottom(int value);
    void InsertSorted(int temp);
};


// Task # 02: Implement a stack using linked list
class StackList
{
private:
    struct Node;
    Node* m_Top;

public:
    StackList();

    void Push(int value);
    void Pop();
    int Peek();
    bool IsEmpty();
};