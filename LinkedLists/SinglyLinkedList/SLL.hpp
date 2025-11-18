#pragma once

#include <iostream>


struct Node
{
    int data;
    Node* next;

    Node(int data, Node* next = nullptr);
};


class SLL
{
private:
    Node* m_Head;
    Node* m_Tail;
    int m_Size;

public:
    SLL(Node* head = nullptr);
    ~SLL();

    void Append(int value);
    void Prepend(int value);
    void Insert(int value, int target);
    void Delete(int target);
    void Clear();
    void Print();
    void Sort();
    Node* Search(int target);
    
    Node* GetHead();
    Node* GetHead() const;
    Node* GetTail();
    Node* GetTail() const;
    int GetSize();
    int GetSize() const;

    void SetHead(Node* head);


    // Tasks
    Node* Reverse();
    Node* Merge(Node* head);
    Node* FindMiddleNode();
    void RemoveNodeFromEnd(int n);
    bool DetectCycle();
    void Reorder();
    void RemoveDupFromSortedList();
    void ReverseKElem(int k);
};
