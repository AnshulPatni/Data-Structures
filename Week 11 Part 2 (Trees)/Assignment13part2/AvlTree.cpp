/*
 * AvlTree.cpp
 *
 *  Created on: Nov 25, 2017
 *      Author: vasubansal
 */


#include <iostream>
#include "AvlTree.h"
#include"BinarySearchTree.h"

using namespace std;

AvlTree::AvlTree()
    : BinarySearchTree()
{
}

AvlTree::~AvlTree()
{
}

int AvlTree:: height(const BinaryNode *ptr) const
{
    return ptr == nullptr ? -1 : ptr->height;
}

void AvlTree::insert(const long data, BinaryNode* &ptr)
{
    BinarySearchTree::insert(data, ptr);
    rebalance(ptr);
}

void AvlTree::remove(const long data, BinaryNode* &ptr)
{
    BinarySearchTree::remove(data, ptr);
    rebalance(ptr);
}

BinaryNode *AvlTree::rebalance(BinaryNode* &ptr)
{
//    cout << "=== Rebalance called on "
//         << (ptr != nullptr ? to_string(ptr->data) : "null")
//         << endl;

    /***** Complete this function. *****/
     if (ptr == nullptr) return ptr;
    if ((height(ptr->get_left())) - (height(ptr->get_right())) > 1)
    {
        if (height(ptr->get_left()->get_left()) >= height(ptr->get_left()->get_right()))
        {
            ptr = singleRightRotation(ptr);
        }
        else
        {
            ptr = doubleLeftRightRotation(ptr);
        }
    }

   else if ((height(ptr->get_right())) - (height(ptr->get_left())) > 1)
    {
        if (height(ptr->get_right()->get_right()) >= height(ptr->get_right()->get_left()))
        {
            ptr = singleLeftRotation(ptr);
        }
        else
        {
            ptr = doubleRightLeftRotation(ptr);
        }
    }

    // Recompute the node's height.
    ptr->height = (max(height(ptr->get_left()),height(ptr->get_right()))+1);

    if (checkBalance(ptr) < 0)
    {
        cout << endl << "***** Tree unbalanced!" << endl;
    }
    return ptr;
}

BinaryNode *AvlTree::singleRightRotation(BinaryNode *k2)
{
    /***** Complete this function. *****/
    BinaryNode *temp; //pointer to the root of the left subtree of k2

	temp = k2->get_left();
	k2->get_left() = temp->get_right(); //the right subtree of p becomes the left subtree of k2
	temp->get_right() = k2;

	//updates height
	k2->height = max(height(k2->get_left()), height(k2->get_right()))+1;
	temp->height = max(height(temp->get_left()), height(temp->get_right()))+1;

	return temp;
}

BinaryNode *AvlTree::doubleLeftRightRotation(BinaryNode *k3)
{
    /***** Complete this function. *****/
  //
   k3->get_left() = singleLeftRotation(k3->get_left());
	return (singleRightRotation(k3));

}

BinaryNode *AvlTree::doubleRightLeftRotation(BinaryNode *k1)
{
    /***** Complete this function. *****/
   //
    k1->get_right() =singleRightRotation(k1->get_right());
	return (singleLeftRotation(k1));


}

BinaryNode *AvlTree::singleLeftRotation(BinaryNode *k1)
{
    /***** Complete this function. *****/
    BinaryNode *temp=k1->get_right();
	 k1->get_right() = temp->get_left();
	 temp->get_left() = k1;

	 k1->height = max(height(k1->get_left()), height(k1->get_right()))+1;
    temp->height = max(height(temp->get_left()), height(temp->get_right()))+1;

	return temp;


}

int AvlTree::checkBalance(BinaryNode *ptr)
{
    if (ptr == nullptr) return -1;

    int leftHeight  = checkBalance(ptr->get_left());
    int rightHeight = checkBalance(ptr->get_right());

    if ((abs(height(ptr->get_left()) - height(ptr->get_right())) > 1)
        || (height(ptr->get_left())  != leftHeight)
        || (height(ptr->get_right()) != rightHeight))
    {
        return -2;       // unbalanced
    }

    return height(ptr);  // balanced
}
