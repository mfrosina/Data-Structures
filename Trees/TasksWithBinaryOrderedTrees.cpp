// TasksWithBinaryOrderedTrees.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <fstream>
#include <cstring>
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
//task 19.10
template <typename T>
void haskellFormatHelper(box<T>* root, std::string& s)
{
    if (root->left == nullptr && root->right == nullptr)
    { 
        s += "\n";
        s += "           ";
        s += "Node ";
        s += std::to_string(root->data) += " ";
        s += "Empty Empty";
        return;
    }
   
    s += "\n";
    s += "      ";
    s += "Node ";
    s += std::to_string(root->data) += " ";
    if (root->right != nullptr)
        haskellFormatHelper(root->right, s);
    if (root->left != nullptr)
        haskellFormatHelper(root->left, s);

}
template <typename T>
std::string haskellFormat(box<T>*& root)
{
    std::string s;
    if (root != nullptr)
    {
        s += "Node ";
        s += std::to_string(root->data);
    }
    s += "     ";
    haskellFormatHelper(root->right, s);
    std::string s1;
    haskellFormatHelper(root->left, s1);
    s += s1;
    return s;
}
//task 19.11
template <typename T>
void listLeaves(box<T>* root, std::vector<T>& leaves)
{
    if (root == nullptr)
    {
        return; 
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        leaves.push_back(root->data);
        return;
    }

    listLeaves(root->left, leaves);
    listLeaves(root->right, leaves);
}
//task 19.12
template <typename T>
bool findTraceHelper(box<T>* root, const T& x,bool& flag, std::string& s)
{
    if (root == nullptr && !flag)
    {
        return false;
    }
    if (root->data == x)
    {
        flag = true;
        s += "";
        return true;
    }
    if (root->left != nullptr)
    {
        s += "L";
        findTraceHelper(root->left, x,flag,s);
    }
    if (root->right != nullptr)
    {
        s += "R";
        findTraceHelper(root->right, x,flag,s);
    }
    
}
template <typename T>
std::string findTrace(box<T>* root, const T& x)
{
    std::string s;
    bool flag = false;
    if (root != nullptr && root->data == x)
    {
        s += "";
        return s;
    }
    if (root->left != nullptr)
    {
        findTraceHelper(root->left, x, flag, s);
        if(flag)
        {
            std::string temp;
            temp += "L";
            temp += s;
            return temp;
        }
    }
    s = "";
    if (root->right != nullptr)
    {
        findTraceHelper(root->right, x, flag, s);
        if(flag)
        {
            std::string temp;
            temp += "R";
            temp += s;
            return temp;
        }
        else
        {
            s = "_";
            return s;
        }
    }
}
//task 19.13
template <typename T>
T getAtHelper(box<T>* root, size_t i, bool& flag, T& data)
{
    if (root == nullptr)
    {
        return NULL;
    }
    if (i == 0)
    {
        flag = true;
        data = root->data;
        return root->data;
    }
    getAtHelper(root->left, --i,flag,data);
    getAtHelper(root->right, --i,flag,data);
}
template <typename T>
T getAt(box<T>* root, size_t i)
{
    if (root == nullptr)
    {
        return NULL;
    }
    if (i == 0)
    {
        return root->data;
    }
    bool flag = false;
    size_t temp = i;
    T el;
    getAtHelper(root->left, temp - 1, flag,el);
    if (flag)
    {
        return el;
    }
    else {
        temp--;
        getAtHelper(root->right, temp-1,flag,el);
        return el;
    }
}
//task 19.14
/*bool isDigit(char ch)
{
    return ch >= '0' && ch <= '9';
}
bool isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*'
        || ch == '/';
}
class Stack
{
public:
    box<char>* treeNode;
    Stack* next;

    Stack(box<char>* _treeNode)
    {
        treeNode = _treeNode;
        next = nullptr;
    }
};
class ExpressionTree
{
private:
    Stack* top;
public:
    ExpressionTree()
    {
        top = nullptr;
    }
    void push(box<char>* treeNode)
    {
        if (top == nullptr)
        {
            top = new Stack(treeNode);
        }
        else
        {
            Stack* newNode = new Stack(treeNode);
            newNode->next = top;
            top = newNode;
        }
    }
    box<char>* pop()
    {
        box<char>* curr = top->treeNode;
        top = top->next;
        return curr;
    }
    box<char>* peek()
    {
        return top->treeNode;
    }
    void insert(char val)
    {
        if (isDigit(val))
        {
            box<char>* newNode = new box<char>{ val,nullptr,nullptr };
            push(newNode);
        }
        else if (isOperator(val))
        {
            box<char>* op = new box<char>{ val,pop(),pop() };
            push(op);
        }
    }
    void parseExpression(std::string expr)
    {
        for (int i = 0; i < expr.length(); i++)
        {
            insert(expr[i]);
        }
    }
};
ExpressionTree parseExpression(std::string expr)
{
    ExpressionTree parsed;
    for (int i = 0; i < expr.length(); i++)
    {
        parsed.insert(expr[i]);
    }
    return parsed;
}*/

//task 19.16
void balancedBTree(box<int>*& bTree, int h, int i)
{
    if (h == 0)
    {
        return;
    }
    
    bTree = new box<int>{ i,nullptr,nullptr };
    balancedBTree(bTree->left, h - 1,i+1);
    balancedBTree(bTree->right, h - 1,i+1);
    
}
template <typename T>
void toScheme(box<T>* root, std::ostream& out)
{
    if (root == nullptr)
    {
        out << "()";
        return;
    }
    out << "(" << root->data << " ";
    toScheme(root->left, out);
    out << " ";
    toScheme(root->right, out);
    out << ")";
}
//task 19.18
template <typename T>
int countNodes(box<T>* root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}
template <typename T>
void transformHelper(box<T>*& root)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        root->data = 1;
        return;
    }
    if (root->left != nullptr && root->right != nullptr)
    {
        root->data = 1 + countNodes(root->left) + countNodes(root->right);
        transformHelper(root->left);
        transformHelper(root->right);
    }
    if (root->left != nullptr && root->right == nullptr)
    {
        root->data = 1 + countNodes(root->left);
        transformHelper(root->left);
    }
    if (root->left == nullptr && root->right != nullptr)
    {
        root->data = 1 + countNodes(root->right);
        transformHelper(root->right);
    }
    
    
}
template <typename T>
void transform(box<T>*& root)
{
    int leftCounter = countNodes(root->left);
    int rightCounter = countNodes(root->right);
    root->data = 1 + leftCounter + rightCounter;
    transformHelper(root->left);
    transformHelper(root->right);
}

//construct a binary tree from a string consisting of parenthesis and integers.
bool isDigit(char ch)
{
    return ch >= '0' && ch <= '9';
}
void constructHelper(box<char>*& root,std::vector<char> v, int c)
{
    if (v.size() == c)
    {
        //root = new box<char>{ v[c-1],nullptr,nullptr };
        return;
    }
    root = new box<char>{ v[c],nullptr,nullptr };
    constructHelper(root->left, v, c + 1);
    //constructHelper(root->right, v, c + 1);
}
void construct(box<char>*& root, std::string s)
{
    root = new box<char>{ s[0],nullptr,nullptr };
    std::stack<char> par;
    std::vector<char> v;
    par.push(s[1]);
    int i = 2, l = s.length();
    while (!par.empty())
    {
        if (s[i] == '(')
        {
            par.push(s[i]);
        }
        if (isDigit(s[i]))
        {
            v.push_back(s[i]);
        }
        if (s[i] == ')')
        {
            par.pop();
        }
        i++;
    }
    constructHelper(root->left, v, 0);

    std::stack<char> par1;
    std::vector<char> v1;
    par1.push(s[i++]);
    while (!par1.empty())
    {
        if (s[i] == '(')
        {
            par1.push(s[i]);
        }
        if (isDigit(s[i]))
        {
            v1.push_back(s[i]);
        }
        if (s[i] == ')')
        {
            par1.pop();
            if (par1.empty())
            {
                break;
            }
        }
        i++;
    }
    constructHelper(root->right, v1, 0);
}
template <typename T>
void preorderPrint(box<T>* root)
{
    if (root == nullptr)
    {
        return;
    }
    std::cout << root->data << " ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}
void constructTreeStringHelper(box<char>*& root, int h, int i)
{
    if (i == h - 1)
    {
        return;
    }
    root = new box<char>{ ' ',nullptr,nullptr };
    constructTreeStringHelper(root->left, h, i + 1);
    constructTreeStringHelper(root->right, h, i + 1);
}
void pushInsert(box<char>*& root,char* s, int h, const int& c, int n)
{
    if (root == nullptr || c == n)
    {
        root = new box<char>{ s[c],nullptr,nullptr};
        return;
    }
    if (c <= h)
    {
        pushInsert(root->left,s+1,h,c+1,n);
    }
    if (c > h)
    {
        pushInsert(root->right,s+1,h,c+1,n);
    }
}
void construcTreeString(box<char>*& root, char* s, int n)
{
    if (n == 0)
    {
        root = nullptr;
        return;
    }
    int h = n / 2 + 1;
    root = new box<char>{ ' ',nullptr,nullptr };
    constructTreeStringHelper(root->left, h, 1);
    constructTreeStringHelper(root->right, h, 1);
    pushInsert(root->left, s, h, 0, n);
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

    box<int>* myTree3 = nullptr;

    setAt(myTree3, "", 10);
    setAt(myTree3, "L", 5);
    setAt(myTree3, "R", 20);
    setAt(myTree3, "RL", 15);
    setAt(myTree3, "RR", 25);
    setAt(myTree3, "RRL", 22);
    setAt(myTree3, "LL", 2);

    std::vector<int> v;
    listLeaves(myTree1, v);
    
    std::string s;
    s = findTrace(myTree, 90);
    //std::cout << s;

    /*std::cout << getAt(myTree1, 3);
    box<int>* myTree2 = nullptr;
    balancedBTree(myTree2, 4,0);
    std::cout << std::endl;
    printLRR(myTree);
    std::cout << std::endl;
    printLRR(myTree2);
    std::ofstream sch("btree.scm");
    toScheme(myTree2,sch);*/

    transform(myTree3);
    std::ofstream sch1("btree1.scm");
    toScheme(myTree3,sch1);
    
    //std::cout<<haskellFormat(myTree1);

    box<char>* myTree4 = nullptr;
    std::string s2 = "4(2(3)(1))(6(5))";
    construct(myTree4, s2);
    std::ofstream sch2("btree2.scm");
    toScheme(myTree4, sch2);
    preorderPrint(myTree4);

    box<char>* myTree5 = nullptr;
    char* c = new char[7];
    strcpy(c, "hello!");
    construcTreeString(myTree5, c, 7);
    std::ofstream sch3("btree3.scm");
    toScheme(myTree5, sch3);
    return 0;
}

