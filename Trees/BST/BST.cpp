#include "BST.hpp"


Node::Node(int key, Node* left, Node* right)
    : key(key), left(left), right(right)
{
}


BST::BST()
    : m_Root(nullptr)
{
}


// Destructor Pending...
BST::~BST()
{
}


Node* BST::m_Insert(Node* root, int &key)
{
    if (!root)
        return new Node(key);

    if (key < root->key)
        root->left = m_Insert(root->left, key);
    else
        root->right = m_Insert(root->right, key);

    return root;
}


Node* BST::m_Delete(Node* root, int &target)
{
    if (!root) return nullptr;

    if (target < root->key)
        root->left = m_Delete(root->left, target);
    else if (target > root->key)
        root->right = m_Delete(root->right, target);
    else
    {
        if (!root->right)
        {
            Node* node = root->left;
            delete root;
            return node;
        }
        else if (!root->left)
        {
            Node* node = root->right;
            delete root;
            return node;
        }
        else
        {
            Node* node = m_FindMin(root->right);
            root->key = node->key;
            node->right = m_Delete(root->right, node->key);
        }
    }
}


Node* BST::m_Search(Node* root, int &key)
{
    if (!root || key == root->key)
        return root;
    
    if (key < root->key)
        return m_Search(root->left, key);
    else
        return m_Search(root->right, key);
}


Node* BST::m_FindMin(Node* root)
{
    while (root->left)
        root = root->left;
    
    return root;
}


void BST::m_PreOrderPrint(Node* root)
{
    if (!root) return;

    std::cout << root->key << " ";
    m_PreOrderPrint(root->left);
    m_PreOrderPrint(root->right);
}


void BST::m_InOrderPrint(Node* root)
{
    if (!root) return;

    m_InOrderPrint(root->left);
    std::cout << root->key << " ";
    m_InOrderPrint(root->right);
}


void BST::m_PostOrderPrint(Node* root)
{
    if (!root) return;

    m_PostOrderPrint(root->left);
    m_PostOrderPrint(root->right);
    std::cout << root->key << " ";
}



// <--------- PUBLIC WRAPERS ----------->

void BST::Insert(int key)
{
    m_Root = m_Insert(m_Root, key);
}


void BST::Delete(int target)
{
    if (IsEmpty())
    {
        std::cout << "Tree Underflow!" << std::endl;
        return;
    }

    m_Root = m_Delete(m_Root, target);
}


void BST::Update(int target, int key)
{
    Node* node = m_Search(m_Root, target);
    
    if (!node)
    {
        std::cout << "Target not found!" << std::endl;
        return;
    }

    node->key = key;
}


Node* BST::Search(int key)
{
    if (IsEmpty())
    {
        std::cout << "Tree is empty!" << std::endl;
        return nullptr;
    }

    return m_Search(m_Root, key);
}


void BST::PreOrderPrint()
{
    std::cout << std::endl;
    m_PreOrderPrint(m_Root);
    std::cout << std::endl;
}


void BST::InorderPrint()
{
    std::cout << std::endl;
    m_InOrderPrint(m_Root);
    std::cout << std::endl;
}


void BST::PostOrderPrint()
{
    std::cout << std::endl;
    m_PostOrderPrint(m_Root);
    std::cout << std::endl;
}


bool BST::IsEmpty()
{
    return m_Root == nullptr;
}