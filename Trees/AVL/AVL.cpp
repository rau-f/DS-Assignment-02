#include "AVL.hpp"


Node::Node(int key, int height, Node* left, Node* right)
    : key(key), height(height), left(left), right(right)
{
}


AVL::AVL()
    : m_Root(nullptr)
{
}


Node* AVL::m_Insert(Node* root, int key)
{
    if (!root)
        return new Node(key);

    if (key < root->key)
        root->left = m_Insert(root->left, key);
    else
        root->right = m_Insert(root->right, key);

    root->height = 1 + std::max(GetHeight(root->left), GetHeight(root->right));

    if (GetBalance(root) > 1)
    {
        if (GetBalance(root->left) > 0)
    }
    
    return root;
}



/* ---------- Public Wrapers ----------- */

void AVL::Insert(int key)
{
    m_Root = m_Insert(m_Root, key);
}