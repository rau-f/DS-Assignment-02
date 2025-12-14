#include "AVL.hpp"


Node::Node(int data, int height, Node* left, Node* right)
    : data(data), height(height), left(left), right(right)
{
}


AVL::AVL()
    : m_Root(nullptr)
{
}


Node* AVL::m_Insert(Node* root, int data)
{
    if (!root)
        return new Node(data);

    if (data < root->data)
        root->left = m_Insert(root->left, data);
    else if (data > root->data)
        root->right = m_Insert(root->right, data);
    else
        return root;

    root->height = 1 + std::max(GetHeight(root->left), GetHeight(root->right));

    int balance = GetBalance(root);

    if (balance > 1 && data < root->left->data)
        return m_RotateRight(root);
    
    if (balance > 1 && data > root->left->data)
    {
        root->left = m_RotateLeft(root->left);
        return m_RotateRight(root);
    }

    if (balance < -1 && data > root->right->data)
        return m_RotateLeft(root);

    if (balance < -1 && data < root->right->data)
    {
        root->right = m_RotateRight(root->right);
        return m_RotateLeft(root);
    }
    
    return root;
}


Node* AVL::m_RotateLeft(Node* p)
{
    Node* pr = p->right;

    p->right = pr->left;
    pr->left = p;

    p->height = 1 + std::max(GetHeight(p->left), GetHeight(p->right));
    pr->height = 1 + std::max(GetHeight(pr->left), GetHeight(pr->right));

    return pr;  // new parent
}


Node* AVL::m_RotateRight(Node* p)
{
    Node* pl = p->left;

    p->left = pl->right;
    pl->right = p;

    p->height = 1 + std::max(GetHeight(p->left), GetHeight(p->right));
    pl->height = 1 + std::max(GetHeight(pl->left), GetHeight(pl->right));

    return pl;  // new parent
}


Node* AVL::m_Delete(Node* root, int data)
{
    
}


/* ------------ Public ------------- */

int AVL::GetHeight(Node* node)
{
    if (!node) return 0;
    return node->height;
}


int AVL::GetBalance(Node* node)
{
    if (!node) return 0;
    return GetHeight(node->left) - GetHeight(node->right);
}


/* ---------- Public Wrapers ----------- */

void AVL::Insert(int data)
{
    m_Root = m_Insert(m_Root, data);
}


void AVL::Delete(int data)
{
    m_Root = m_Delete(m_Root, data);
}