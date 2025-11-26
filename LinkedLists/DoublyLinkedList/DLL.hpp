#pragma once

#include <iostream>


struct Node
{
    int data;
    Node* next;
    Node* prev;

    Node (int data, Node* prev = nullptr, Node* next = nullptr);
};


class DLL
{
private:
    Node* m_Head;
    Node* m_Tail;
    int m_Size;

public:
    DLL();
    ~DLL();

    void Clear();
    void Append(int value);
    void Prepend(int value);
    void Insert(int value, int target);
    void Delete(int value);
    void Sort();
    void MakeCircular();
    void BreakCircle();
    void Print();
    Node* Search(int target);

    bool IsCircular();
    Node* GetHead();
    Node* GetTail();
    int GetSize();

    void SetHead(Node* head);
    void SetTail(Node* tail);

    // Tasks
    void InsertInSortedList(int value);
    void DelOuccKey(int key);
    void PrintPairs(int sum);
    void RotateByN(int n);
    DLL* Merge(DLL &list2);
    // Task 06 pending till trees
    void FindTripletsSumToK(int k);
};
