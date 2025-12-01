#include "BST.hpp"
#include <queue>
#include <climits>


int BST::m_MaxHeight(Node* root)
{
    if (!root)
        return 0;

    return (1 + std::max(m_MaxHeight(root->left), m_MaxHeight(root->right)));
}


void BST::m_CountLeaves(Node* root, int &leaves, int &nonLeaves)
{
    if (!root) return;

    if (!root->left && !root->right)
        leaves++;
    else
        nonLeaves++;
    
    m_CountLeaves(root->left, leaves, nonLeaves);
    m_CountLeaves(root->right, leaves, nonLeaves);
}


void BST::m_LevelOrder(Node* root)
{
    if (!root)
        return;

    std::queue<Node*> queue;
    queue.push(root);
    
    std::cout << std::endl;
    while (!queue.empty())
    {
        Node* curr = queue.front();
        std::cout << curr->key << " ";

        if (curr->left) queue.push(curr->left);
        if (curr->right) queue.push(curr->right);

        queue.pop();
    }
    std::cout << std::endl;
}


int BST::m_Diameter(Node* root, int &result)
{
    if (!root)
        return 0;
    
    int left = m_Diameter(root->left, result);
    int right = m_Diameter(root->right, result);

    result = std::max(left + right, result);

    return 1 + std::max(left, right);
}


bool BST::m_VerifyBST(Node* root, int minValue, int maxValue)
{
    if (!root)
        return true;

    if (root->key <= minValue || root->key >= maxValue)
        return false;

    return m_VerifyBST(root->left, maxValue, root->key) &&
           m_VerifyBST(root->right, root->key, minValue);
}


bool BST::m_FindPathToNode(Node *root, Node *node)
{
    if (!root || !node)
        return false;

    if (root->key == node->key)
    {
        std::cout << root->key << " ➔";
        return true;
    }

    if (m_FindPathToNode(root->left, node) || m_FindPathToNode(root->right, node))
    {
        std::cout << root->key << " ➔";
        return true;
    }

    return false;
}


void BST::m_SumOfLeftLeaves(Node *root, int& sum)
{
    if (!root)
        return;

    if (root->left && !root->left->left && !root->left->right)
        sum += root->left->key;

    m_SumOfLeftLeaves(root->left, sum);
    m_SumOfLeftLeaves(root->right, sum);
}


bool BST::m_PrintAncestors(Node *root, Node *node)
{
    if (!root || !node)
        return false;

    if (root->key == node->key)
        return true;

    if (m_PrintAncestors(root->left, node) || m_PrintAncestors(root->right, node))
    {
        std::cout << root->key << " ";
        return true;
    }

    return false;
}


int BST::m_KthSmallest(Node *root, int &k, int &order)
{
    if (!root)
        return -1;
    
    int left = m_KthSmallest(root->left, k, order);
    if (left != -1)
        return left;

    if (k == ++order)
        return root->key;

    return m_KthSmallest(root->right, k, order);
}



/* ------------ Public Wrapers ------------- */

int BST::MaxHeight()
{
    if (!m_Root)
        return 0;

    return std::max(m_MaxHeight(m_Root->left), m_MaxHeight(m_Root->right));
}


void BST::CountLeaves(int &leaves, int &nonLeaves)
{
    m_CountLeaves(m_Root, leaves, nonLeaves);
}


void BST::LevelOrder()
{
    m_LevelOrder(m_Root);
}


int BST::Diameter()
{
    int result = 0;
    return m_Diameter(m_Root, result);
}


bool BST::VerifyBST()
{
    return m_VerifyBST(m_Root, INT_MIN, INT_MAX);
}


void BST::FindPath(Node* node)
{
    if (m_FindPathToNode(m_Root, node))
        std::cout << " Root" << std::endl;
    else
        std::cout << "Target not found!" << std::endl;
}


int BST::SumOfLeftLeaves()
{
    int sum = 0;
    m_SumOfLeftLeaves(m_Root, sum);

    return sum;
}


void BST::PrintAncestors(Node* node)
{
    m_PrintAncestors(m_Root, node);
}


int BST::KthSmallest(int k)
{
    int order = 0;
    return m_KthSmallest(m_Root, k, order);
}