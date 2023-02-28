// TasksWithBinaryTrees.cpp : This file contains the 'main' function. Program execution begins and ends there.
//https://medium.com/techie-delight/binary-tree-interview-questions-and-practice-problems-439df7e5ea1f


#include <iostream>

template <typename T>
struct box
{
    T data;
    box* left;
    box* right;
};
template <typename T>
bool setAt(box<T>*& root, const char* trace, const T& data)
{
    if (trace[0] == 0)
    {
        if (root == nullptr)
        {
            root = new box<T>{ data,nullptr,nullptr };
        }
        else
        {
            root->data = data;
        }
        return true;
    }
    else
    {
        if (root == nullptr)
        {
            return false;
        }
        else
        {
            if (trace[0] == 'L')
            {
                setAt(root->left, trace + 1, data);
            }
            else if (trace[0] == 'R')
            {
                setAt(root->right, trace + 1, data);
            }
            else
            {
                throw std::invalid_argument("Invalid trace");
            }
            return false;
        }
    }
}
template <typename T>
void printLRR(box<T>* root)
{
    if (root == nullptr)
    {
        return;
    }
    printLRR(root->left);
    std::cout << root->data << " ";
    printLRR(root->right);
}
int sum(box<int>* root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return root->data + sum(root->left) + sum(root->right);
}
//task7
int transform(box<int>* root)
{
    // base case: empty tree
    if (root == nullptr) {
        return 0;
    }

    // recursively convert the left and right subtree first before
    // processing the root node
    int left = transform(root->left);
    int right = transform(root->right);

    // stores the current value of the root node
    int old = root->data;

    // update root to the sum of left and right subtree
    root->data = left + right;

    // return the updated value + the old value (sum of the tree rooted at
    // the root node)
    return root->data + old;
}
//task8
template <typename T>
int getLevelHelper(box<T>* root, const T& data, int level)
{
    if (root == nullptr)
    {
        return 0;
    }
    if (root->data == data)
    {
        return level;
    }
    int leftLevel = getLevelHelper(root->left, data, level + 1);
    if (leftLevel != 0)
    {
        return leftLevel;
    }
    return getLevelHelper(root->right, data, level + 1);
}
template <typename T>
int getLevel(box<T>* root, const T& data)
{
    return getLevelHelper(root, data, 1);
}


// Data structure to store a binary tree node along
// with its level and parent information
template <typename T>
struct NodeInfo
{
    box<T>* node;
    int level;
    box<T>* parent;
};

// Perform inorder traversal on a given binary tree and update 'x' and 'y'
template <typename T>
void updateLevelandParent(box<T>* root, box<T>* parent, int level, NodeInfo<T>& x, NodeInfo<T>& y)
{
    // base case: tree is empty
    if (root == nullptr) {
        return;
    }

    // traverse left subtree
    updateLevelandParent(root->left, root, level + 1, x, y);

    // if the first element is found, save its level and parent node
    if (root == x.node)
    {
        x.level = level;
        x.parent = parent;
    }

    // if the second element is found, save its level and parent node
    if (root == y.node)
    {
        y.level = level;
        y.parent = parent;
    }

    // traverse right subtree
    updateLevelandParent(root->right, root, level + 1, x, y);
}

// Function to determine if two given nodes are cousins of each other
template <typename T>
bool checkCousins(box<T>* root, box<T>* node1, box<T>* node2)
{
    // return if the tree is empty
    if (root == nullptr) {
        return false;
    }

    int level = 1;              // level of the root is 1
    box<T>* parent = nullptr;     // parent of the root is null

    NodeInfo<T> x = { node1, level, parent };
    NodeInfo<T> y = { node2, level, parent };

    // perform inorder traversal on the array and update 'x' and 'y'
    updateLevelandParent(root, parent, 1, x, y);

    // return true if 'x' and 'y' are at the same level, but different parent
    return x.level == y.level && x.parent != y.parent;
}
int main()
{
    box<int>* myTree = nullptr;

    setAt(myTree, "", 7);
    setAt(myTree, "L", 3);
    setAt(myTree, "R", 5);
    setAt(myTree, "LR", 50);
    setAt(myTree, "RL", 12);
    setAt(myTree, "LRL", 90);
    setAt(myTree, "LRLR", 6);

    box<int>* myTree1 = nullptr;

    setAt(myTree1, "", 10);
    setAt(myTree1, "L", 5);
    setAt(myTree1, "R", 20);
    setAt(myTree1, "RL", 15);
    setAt(myTree1, "RR", 25);

    box<int>* myTree2 = nullptr;
    setAt(myTree2, "", 10);
    setAt(myTree2, "L", 7);
    setAt(myTree2, "R", 3);
    setAt(myTree2, "LL", 6);
    setAt(myTree2, "LR", 1);
    setAt(myTree2, "RL", 3);

    box<int>* myTree3 = nullptr;
    setAt(myTree3, "", 1);
    setAt(myTree3, "L", 2);
    setAt(myTree3, "R", 3);
    setAt(myTree3, "LR", 4);
    setAt(myTree3, "RR", 6);
    setAt(myTree3, "RL", 5);
    setAt(myTree3, "RLL", 7);
    setAt(myTree3, "RLR", 8);

    box<int>* myTree4 = nullptr;
    setAt(myTree4, "", 30);
    setAt(myTree4, "L", 10);
    setAt(myTree4, "R", 5);
    setAt(myTree4, "LL", 4);
    setAt(myTree4, "LR", 6);
    setAt(myTree4, "RR", 5);

    std::cout << checkCousins(myTree4, myTree4->left->right, myTree4->right->right);
}

