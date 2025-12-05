#pragma once
#include <iostream>


struct Node
{
    int key;
    int height;
    Node* left;
    Node* right;

    Node(int key, int height = 0, Node* left = nullptr, Node* right = nullptr);
};


class AVL
{
private:
    Node* m_Root;

    Node* m_Insert(Node* root, int key);
    Node* m_Delete(Node* root, int target);

public:
    AVL();

    void Insert(int key);
    void Delete(int target);
};