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

public:
    SLL(Node* head = nullptr);
    ~SLL();

    void Append(int value);
    void Prepend(int value);
    void Insert(int value, int target);
    void Print();
    void Sort();

    Node* Search(int target);
    
    bool IsEmpty();
    
    Node* GetHead();
    Node* GetHead() const;

    void SetHead(Node* head);


    // Tasks
    Node* Reverse();
    Node* Merge(Node* head);
    bool DetectCycle();
};
