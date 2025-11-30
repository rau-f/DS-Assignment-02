#pragma once

#include <iostream>


// Task # 01: Implement Queue using arrays
class QueueArray
{
private:
    int* m_Data;
    int m_Front;
    int m_Rear;
    int m_Size;
    int m_Cap;

public:
    QueueArray(int size);
    ~QueueArray();

    void Enqueue(int value);
    int Dequeue();
    int Front();
    bool IsEmpty();
    bool IsFull();

    // Task 04 & 05
    void ReverseKElem(int k);
    bool IsPalindorme();
};


// Task # 02: Implement Queue using linked list
class QueueList
{
private:
    struct Node;
    Node* m_Front;
    Node* m_Rear;
    int m_Size;

public:
    QueueList();
    
    void Enqueue(int value);
    int Dequeue();
    int Front();
    bool IsEmpty();
};


// Task # 03: Implement Priority Queue using arrays
class PriorityQueue
{
private:
    struct Item;
    Item* m_Data;

    int m_Cap;
    int m_Size;

public:
    PriorityQueue(int cap);
    ~PriorityQueue();

    void Enqueue(int value, int pr);
    int Dequeue();
    int Front();
    bool IsEmpty();
    bool IsFull();

    void Swap(Item &a, Item &b);
};