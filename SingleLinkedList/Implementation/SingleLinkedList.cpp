// linkedlist_15.10.22.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
void addOne(int& x)
{
    x++;
    //return x++;
}

#include <iostream>
#include "llist.h"
#include "MapWIterator.h"
int main()
{
    /*LList<int>* l = new LList<int>();
    l->push(1);
    l->push(2);
    l->print();

    std::cout << std::endl;
    LList<int>* l1 = l;
    l1->print();

    std::cout << std::endl;
    LList<int>* l2 = new LList<int>();
    l2->push(1);
    l2->push(5);
    l2->push(5);
    l2->push(4);
    l2->push(5);
    l->append(l2);
    l->print();

    std::cout << std::endl;
    LList<int> l5;
    l5.push(1);
    l5.push(2);
    l5.push(6);
    l5 += 7;
    l5.print();

    l = l2;
    l->print();
    std::cout << std::endl;

    l2->insertAt(3, 7);
    l2->print();
    l2->deleteAt(1);
    std::cout << std::endl;
    l2->print();
    std::cout << std::endl;
    std::cout << l2->size();
    
    //task 12.2 test
    LList<int>* l3 = new LList<int>(3, 8);
    l3->print();

    std::cout << std::endl;
    //task 12.3 test
    l3->push_back(99);
    l3->print();

   std::cout << std::endl;
   std::cout << l3->operator[](7);
    std::cout << std::endl;
    //task 12.4 test
    //????????

    //task 12.5 test 
    std::cout << l3->get_nth(7);

    l3->deleteAt(7);
    std::cout << std::endl;
    l3->print();

    l3->insertAt(6, 66);
    std::cout << std::endl;
    l3->print();

    l3->pop();
    std::cout << std::endl;
    l3->print();*/

    LList<int> l;
    l.push(0);
    l.push(4);
    l.push(6);
    map(l, addOne);
    
    l.print();
    
    return 0;
}
/*


#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

#include <cstdlib>
#include "llist.h"
#include "SumIterator.h"
#include "DuplicatesWithIterator.h"
#include "IsSortedWIterator.h"
#include "PalindromeWIterator.h"

TEST_CASE("Push test")
{

    LList<int> l;
    l.push(0);
    l.push(1);
    l.push(2);
    l.push(3);

    CHECK(l.size() == 4);
    CHECK(l[1] == 3);
    CHECK(l[2] == 2);
    CHECK(l[3] == 1);
    CHECK(l[4] == 0);
}

TEST_CASE("Count test")
{
    LList<int>* l2 = new LList<int>();
    l2->push(1);
    l2->push(5);
    l2->push(5);
    l2->push(4);
    l2->push(5);

    CHECK(l2->count(5) == 3);
    CHECK(l2->count(3) == 0);
}

TEST_CASE("Constructor with arguments test")
{
    LList<int> l3(3, 8);

    CHECK(l3[1] == 3);
    CHECK(l3[2] == 4);
    CHECK(l3[3] == 5);
    CHECK(l3[4] == 6);
}

TEST_CASE("Push back test")
{
    LList<int> l3(3, 8);
    l3.push_back(99);

    CHECK(l3.size() == 7);
    CHECK(l3[7] == 99);
}

TEST_CASE("Get nth test")
{
    LList<int> l3(3, 8);

    CHECK(l3.get_nth(5) == 7);
    CHECK(l3.get_nth(1) == 3);
    CHECK(l3.get_nth(6) == 8);
}

TEST_CASE("InsertAt test")
{
    LList<int> l3(3, 8);
    l3.insertAt(5, 99);
   
    CHECK(l3[5] == 99);
    CHECK(l3.size() == 7);
}


TEST_CASE("DeleteAt test")
{
    LList<int> l3(3, 8);
    l3.deleteAt(1);

    CHECK(l3[1] == 4);
    CHECK(l3.size() == 5);
}

TEST_CASE("Append test")
{
    LList<int>* l3 = new LList<int>(5, 8);
    LList<int>* l4 = new LList<int>(10, 15);
    l3->append(l4);

    CHECK(l3->size() == 10);
    CHECK(l3->operator[](9) == 14);
    CHECK(l3->operator[](7) == 12);
    CHECK(l3->operator[](5) == 10);

}

TEST_CASE("Operator+= test")
{
    LList<int> l3(3, 8);
    l3 += 17;
    l3 += 23;

    CHECK(l3[7] == 17);
    CHECK(l3[8] == 23);
    CHECK(l3.size() == 8);
}

TEST_CASE("Test Sum")
{

    LList<int> l;

    CHECK(sum(l) == 0);

    l.push(0);
    l.push(1);
    l.push(2);

    CHECK(sum(l) == 3);

}

TEST_CASE("Test Duplicates")
{
    LList<int> l;
    l.push(0);
    l.push(1);
    l.push(2);

    CHECK(duplicates(l) == false);

    l.push(3);
    l.push(2);
    l.push(5);

    CHECK(duplicates(l) == true);
}

TEST_CASE("Test isSorted")
{
    LList<int> lst;
    lst.push(5);
    lst.push(4);
    lst.push(6);
    lst.push(2);
    lst.push(0);

    CHECK(isSorted(lst) == false);

    lst.deleteAt(3);
    CHECK(lst[2] == 2);

    CHECK(isSorted(lst) == true);
}

TEST_CASE("Test isPalindrome")
{
    LList<int> l;
    l.push(4);
    l.push(5);
    l.push(5);
    l.push(5);
    l.push(4);

    CHECK(isPalindrome(l) == true);
}

int main()
{
    doctest::Context().run();

    return 0;
}*/

