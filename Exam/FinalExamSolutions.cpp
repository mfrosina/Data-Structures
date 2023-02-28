// FinalExamSolutions_1MI8000006.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define DOCTEST_CONFIG_IMPLEMENT
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cstring>
#include <queue>
#include "doctest.h"

//task1
template <typename T>
struct Node
{
    T data;
    Node* next;
};
template <typename T>
int countElementOccurence(Node<T>* first, T elem)
{
    if (first == nullptr)
    {
        return 0;
    }
    int counter = 0;
    while (first != nullptr)
    {
        if (first->data == elem)
        {
            counter++;
        }
        first = first->next;
    }
    return counter;
}
template <typename T>
T most_common(Node<T>* first)
{
    if (first == nullptr)
        return NULL;

    int counter = 0;
    T mostCommon;
    while (first != nullptr)
    {
        int tempCounter = countElementOccurence(first, first->data);
        if (tempCounter > counter)
        {
            counter = tempCounter;
            mostCommon = first->data;
        }
        first = first->next;
    }
    return mostCommon;
}

//task2
template <typename T>
struct TNode
{
    T data;
    std::vector<TNode*> children;

};
template <typename T>
void getElementsOnLevel(TNode<T>* root, int level, std::vector<T>& v)
{
    if (root == nullptr)
        return;

    if (level == 0)
    {
        v.push_back(root->data);
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        getElementsOnLevel(root->children[i], level - 1, v);
    }
}
template <typename T>
int height(TNode<T>* root)
{
    if (root == nullptr)
        return 0;

    int maxHeight = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        int currHeight = height(root->children[i]);
        if (currHeight > maxHeight)
        {
            maxHeight = currHeight;
        }
    }
    return 1 + maxHeight;
}
template <typename T>
bool isVectorSorted(std::vector<T> v)
{
    for (int i = 0; i < v.size()-1; i++)
    {
        if (v[i] > v[i + 1])
        {
            return false;
        }
    }
    return true;
}
template <typename T>
bool ordered_levels(TNode<T>* root)
{
    if (root == nullptr)
    {
        return true;
    }
    int h = height(root);
    for (int i = 0; i < h; i++)
    {
        std::vector<T> elementsOnLevel;
        getElementsOnLevel(root, i, elementsOnLevel);
        if (!isVectorSorted(elementsOnLevel))
        {
            return false;
        }
    }
    return true;
}

//task3
struct BTNode
{
    std::pair<std::string, int> data;
    BTNode* left, *right;

    BTNode(const std::pair<std::string, int>& _data)
    {
        data = _data;
        left = nullptr;
        right = nullptr;
    }
};
std::vector<std::string> saveWordsInVector(std::string t)
{
    std::vector<std::string> words;
    char* token = strtok(const_cast<char*>(t.c_str()), " ");
    while (token != nullptr)
    {
        words.push_back(token);
        token = strtok(nullptr, " ");
    }
    std::sort(words.begin(), words.end());
    return words;
}
std::pair<std::string, int> makePair(std::vector<std::string> words, std::string word)
{
    std::pair<std::string, int> paired;
    int counter = 0;
    for (int i = 0; i < words.size(); i++)
    {
        if (words[i] == word)
        {
            counter++;
        }
    }
    paired = std::make_pair(word, counter);
    return paired;
}
BTNode* createTreeUtil(std::vector<std::pair<std::string, int>> elements, int start, int end)
{
    if (start > end)
    {
        return nullptr;
    }
    int midInd = (start + end) / 2;
    BTNode* root = new BTNode(elements[midInd]);
    root->left = createTreeUtil(elements, start, midInd - 1);
    root->right = createTreeUtil(elements, midInd + 1, end);
    return root;
}
BTNode* create_tree(const std::string& text)
{
    std::vector<std::string> words = saveWordsInVector(text);
    std::vector<std::pair<std::string, int>> pairedWords;
    std::vector<std::string> visited;
    for (int i = 0; i < words.size(); i++)
    {
        bool flag = false;
        for (int j = 0; j < visited.size(); j++)
        {
            if (words[i] == visited[j])
            {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            std::pair<std::string, int> paired = makePair(words, words[i]);
            pairedWords.push_back(paired);
            visited.push_back(words[i]);
        }
    }
    BTNode* root = createTreeUtil(pairedWords, 0, pairedWords.size() - 1);
    return root;
    
}

//task4
const unsigned long MAX_ROWS = 26;
const char MAX_COLS = 26;
template <typename T>
class Spreadsheet
{
private:
    struct CellOfMatrix
    {
        std::pair<T, bool> cell;

        CellOfMatrix()
        {
            cell.second = false;
        }
    };
    CellOfMatrix matrix[MAX_ROWS][MAX_COLS];
    int rows;
    int cols;

    bool existsValue(unsigned long row, char col)
    {
        return (matrix[row][col].cell.second == true);
    }
public:
    Spreadsheet(){}
    Spreadsheet(const int& _rows, const int& _cols)
    {
        rows = _rows;
        cols = _cols;
    }
    void set(unsigned long row, char col, const T& value)
    {
        matrix[row][col].cell.first = value;
        matrix[row][col].cell.second = true;
    }
    T get(unsigned long row, char col)
    {
        if (!existsValue(row, col))
        {
            return -1;
        }
        return matrix[row][col].cell.first;
    }
    T max()
    {
        T maxElem = matrix[0]['A'].cell.first;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j].cell.first > maxElem)
                {
                    maxElem = matrix[i][j].cell.first;
                }
            }
        }
        return maxElem;
    }
};



//TEST CASES
//task1 test
TEST_CASE("Test Edges")
{
    CHECK_NOTHROW(most_common<int>(nullptr));
}

#include <vector>
Node<int>* to_list(std::vector<int> v)
{
    Node<int>* l = nullptr;
    for (int e : v)
    {
        l = new Node<int>{ e,l };
    }
    return l;
}

TEST_CASE("Test")
{
    CHECK(most_common(to_list({ 0,0,0 })) == 0);
    CHECK(most_common(to_list({ 0,1,0,0,1 })) == 0);
    CHECK(most_common(to_list({ 1,2,3,3,2,1,3 })) == 3);
    CHECK(most_common(to_list({ 9,2,3,2,3,2,3,5,6,7,8 })) <= 3);

}

//task2 test
TEST_CASE("Test Edges")
{
    CHECK_NOTHROW(ordered_levels<int>(nullptr));
}

TEST_CASE("Test")
{
    TNode<int>* t1 = new TNode<int>{ 0,{
                                     new TNode<int> {1,{
                                                     new TNode<int>{-1,{}},
                                                     new TNode<int>{1,{}}
                                     }},
                                     new TNode<int> {2,{
                                                     new TNode<int>{5,{
                                                                    new TNode<int>{7,{}},
                                                                    new TNode<int>{8,{}}
                                                     }}
                                     }},
                                     new TNode<int> {3,{}}
                     } };

    CHECK(ordered_levels(t1) == true);

    TNode<int>* t2 = new TNode<int>{ 0,{
                                     new TNode<int> {1,{
                                                     new TNode<int>{-1,{}},
                                                     new TNode<int>{1,{}}
                                     }},
                                     new TNode<int> {4,{
                                                     new TNode<int>{5,{
                                                                    new TNode<int>{7,{}},
                                                                    new TNode<int>{8,{}}
                                                     }}
                                     }},
                                     new TNode<int> {3,{}}
                     } };

    CHECK(ordered_levels(t2) == false);

    TNode<int>* t3 = new TNode<int>{ 0,{
                                     new TNode<int> {1,{
                                                     new TNode<int>{-1,{}},
                                                     new TNode<int>{1,{}}
                                     }},
                                     new TNode<int> {2,{
                                                     new TNode<int>{0,{
                                                                    new TNode<int>{7,{}},
                                                                    new TNode<int>{8,{}}
                                                     }}
                                     }},
                                     new TNode<int> {3,{}}
                     } };

    CHECK(ordered_levels(t3) == false);

    TNode<int>* t4 = new TNode<int>{ 0,{
                                     new TNode<int> {1,{
                                                     new TNode<int>{-1,{}},
                                                     new TNode<int>{1,{}}
                                     }},
                                     new TNode<int> {2,{
                                                     new TNode<int>{5,{
                                                                    new TNode<int>{8,{}},
                                                                    new TNode<int>{7,{}}
                                                     }}
                                     }},
                                     new TNode<int> {3,{}}
                     } };

    CHECK(ordered_levels(t4) == false);

}

//task3 test
bool check_tree_order(BTNode* root,
    std::queue<std::pair<std::string, int>>& pairs)
{
    if (root == nullptr)
    {
        return true;
    }
    if (pairs.size() == 0)
    {
        return false;
    }
    if (!check_tree_order(root->left, pairs))
    {
        return false;
    }
    if (pairs.front() != root->data)
    {
        return false;
    }
    pairs.pop();

    return check_tree_order(root->right, pairs);
}

TEST_CASE("Test Edges")
{
    CHECK_NOTHROW(create_tree(""));
    CHECK(create_tree("") == nullptr);
}

TEST_CASE("Test")
{
    std::queue<std::pair<std::string, int>> pairs_1({ {"are",1},
                                                    {"counting",1},
                                                    {"for",1},
                                                    {"in",1},
                                                    {"only",1},
                                                    {"text",2},
                                                    {"this",1},
                                                    {"words",5} });

    const char* text = "text for counting words "
        "only words are in this text words words words";



    CHECK(check_tree_order(create_tree(text), pairs_1) == true);
    CHECK(pairs_1.size() == 0);
}

int main()
{
    doctest::Context().run();  
    Spreadsheet<int> t(3, 3);
    t.set(0, 'B', 7);
    t.set(1, 'A', 1);
    t.set(2, 'C', 9);
    std::cout << t.get(0, 'B') << "\n";
    std::cout << t.get(1, 'A') << "\n";
    std::cout << t.get(2, 'C') << "\n";
}
