#pragma once
#include <iostream>


struct Node
{
    int data;
    int height;
    Node* left;
    Node* right;

    Node(int data, int height = 0, Node* left = nullptr, Node* right = nullptr);
};


class AVL
{
private:
    Node* m_Root;

    Node* m_Insert(Node* root, int& data);
    Node* m_Delete(Node* root, int& target);

    Node* m_RotateLeft(Node* node);
    Node* m_RotateRight(Node* node);

    Node* m_GetMin(Node* node);

public:
    AVL();

    void Insert(int data);
    void Delete(int target);

    int GetHeight(Node* node);
    int GetBalance(Node* node);
};