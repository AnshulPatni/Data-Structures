/*
 * BinarySearchTree.cpp
 *
 *  Created on: Nov 25, 2017
 *      Author: vasubansal
 */

#include <iostream>
#include <string>
#include "BinarySearchTree.h"

using namespace std;

BinarySearchTree::BinarySearchTree() : root(nullptr)
{
}

BinarySearchTree::~BinarySearchTree()
{
    clear();
}

BinaryNode *BinarySearchTree::getRoot() const { return root; }

int BinarySearchTree::height() const { return height(root); }

int BinarySearchTree::height(const BinaryNode *ptr) const
{
    /***** Complete this function. *****/
      if(ptr==nullptr)
      {
         return -1;
      }
      else
      {
         return (1 + max(height(ptr->right),height(ptr->left)));
      }
}

long BinarySearchTree::findMin() const throw(string)
{
    if (isEmpty()) throw(string("Empty tree"));
    return findMin(root)->data;
}

BinaryNode *BinarySearchTree::findMin(BinaryNode *ptr) const
{
    /***** Complete this function. *****/

     if (ptr != nullptr)
    {
        while(ptr->get_left() != nullptr) ptr = ptr->get_left();
    }

    return ptr;

}

long BinarySearchTree::findMax() const throw(string)
{
    if (isEmpty()) throw(string("Empty tree"));
    return findMax(root)->data;
}

BinaryNode *BinarySearchTree::findMax(BinaryNode *ptr) const
{
    /***** Complete this function. *****/
    if (ptr != nullptr)
    {
        while(ptr->get_right() != nullptr) ptr = ptr->get_right();
    }

    return ptr;
}

void BinarySearchTree::clear()
{
    clear(root);
}

void BinarySearchTree::clear(BinaryNode* &ptr)
{
    /***** Complete this function. *****/
    if(ptr!= nullptr)
    {
       clear(ptr->left);
       clear(ptr->right);
       delete ptr;
       ptr=nullptr;
    }

}


void BinarySearchTree::setRoot()
{
	root=nullptr;
}
bool BinarySearchTree::isEmpty() const
{
    return root == nullptr;
}

bool BinarySearchTree::contains(const long data) const
{
    return contains(data, root);
}

bool BinarySearchTree::contains(const long data, BinaryNode *ptr) const
{
    /***** Complete this function. *****/
        while (ptr != nullptr)
    {
        if (data < ptr->get_data())
        {
            ptr = ptr->get_left();
        }
        else if (data > ptr->get_data())
        {
            ptr = ptr->get_right();
        }
        else
        {
            return true;
        }
    }

    return false;
}

void BinarySearchTree::insert(const long data)
{
    insert(data, root);
}

void BinarySearchTree::insert(const long data, BinaryNode* &ptr)
{
//    cout << "=== Insert called on "
//         << (ptr != nullptr ? to_string(ptr->data) : "null")
//         << endl;

    /***** Complete this function. *****/
    if (ptr == nullptr)
    {
        ptr = new BinaryNode(data);
    }
    else if (data < ptr->get_data())
    {
        insert(data, ptr->get_left());
    }
    else if (data > ptr->get_data())
    {
        insert(data, ptr->get_right());
    }
}

void BinarySearchTree::remove(const long data)
{
    remove(data, root);
}

void BinarySearchTree::remove(const long data, BinaryNode* &ptr)
{
//    cout << "=== Remove called on "
//         << (ptr != nullptr ? to_string(ptr->data) : "null")
//         << endl;

    /***** Complete this function. *****/

    if (ptr == nullptr) return;

    if (data < ptr->get_data())
    {
        remove(data, ptr->get_left());
    }
    else if (data > ptr->get_data())
    {
        remove(data, ptr->get_right());
    }
    else if (   (ptr->get_left()  != nullptr)  && (ptr->get_right() != nullptr))
    {
        ptr->data = findMin(ptr->get_right())->data;
        remove(ptr->data, ptr->get_right());
    }
    else
    {
        BinaryNode *oldNode = ptr;
        ptr = (ptr->get_left() != nullptr) ? ptr->get_left()
                                     : ptr->get_right();
        delete oldNode;
    }
}

