#pragma once

#include <iostream>


struct Node
{
    int key;
    Node* left;
    Node* right;

    Node(int key, Node* left = nullptr, Node* right = nullptr);
};


class BST
{
private:
    Node* m_Root;

    Node* m_Insert(Node* root, int &key);
    Node* m_Delete(Node* root, int &target);
    Node* m_Search(Node* root, int &key);
    Node* m_FindMin(Node* root);
    
    void m_PreOrderPrint(Node* root);
    void m_InOrderPrint(Node* root);
    void m_PostOrderPrint(Node* root);

    // Tasks
    int m_MaxHeight(Node* root);
    void m_CountLeaves(Node* root, int &leaves, int & nonLeaves);
    void m_LevelOrder(Node* root);
    int m_Diameter(Node* root, int &result);
    bool m_VerifyBST(Node* root, int minValue, int maxValue);
    bool m_FindPathToNode(Node* root, Node* node);
    void m_SumOfLeftLeaves(Node* root, int &sum);
    bool m_PrintAncestors(Node* root, Node* node);
    int m_KthSmallest(Node* root, int &k, int &order);

public:
    BST();
    ~BST();

    void Insert(int key);
    void Delete(int target);
    void Update(int target, int key);
    Node* Search(int key);

    void PreOrderPrint();
    void InorderPrint();
    void PostOrderPrint();

    bool IsEmpty();


    // Tasks wrapers
    int MaxHeight();
    void CountLeaves(int &leaves, int &nonLeaves);
    void LevelOrder();
    int Diameter();
    bool VerifyBST();
    void FindPath(Node* node);
    int SumOfLeftLeaves();
    void PrintAncestors(Node* node);
    int KthSmallest(int k);
};