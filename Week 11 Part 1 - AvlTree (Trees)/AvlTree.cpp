#include <iostream>
#include "AvlTree.h"

using namespace std;

AvlTree::AvlTree()
    : BinarySearchTree()
{
}

AvlTree::~AvlTree()
{
}

int AvlTree::height(const BinaryNode *ptr) const
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
   /*** Reference Citation: Data Structures Using C++ by D.S. Malik ***/
   if (ptr == nullptr) return ptr;

   if (height(ptr->left) - height(ptr->right) > 1)
   {
      if (height(ptr->left->left) >= height(ptr->left->right))
      {
         ptr = singleRightRotation(ptr);
      }
      else
      {
         ptr = doubleLeftRightRotation(ptr);
      }
   }
   else if (height(ptr->right) - height(ptr->left) > 1)
   {
      if (height(ptr->right->right) >= height(ptr->right->left))
      {
         ptr = singleLeftRotation(ptr);
      }
      else
      {
         ptr = doubleRightLeftRotation(ptr);
      }
   }
    // Recompute the node's height.
   ptr->height = ( max( height(ptr->left), height(ptr->right) ) + 1);

    if (checkBalance(ptr) < 0)
    {
        cout << endl << "***** Tree unbalanced!" << endl;
    }

    return ptr;
}

BinaryNode *AvlTree::singleRightRotation(BinaryNode *k2)
{
   /***** Complete this function. *****/
   /*** Reference Citation: Data Structures Using C++ by D.S. Malik ***/
   BinaryNode *temp = k2->left;
	k2->left = temp->right;
	temp->right = k2;

	k2->height = max(height(k2->left), height(k2->right))+1;
	temp->height = max(height(temp->left), height(temp->right))+1;

	return temp;
}

BinaryNode *AvlTree::doubleLeftRightRotation(BinaryNode *k3)
{
   /***** Complete this function. *****/
   k3->left = singleLeftRotation(k3->left);
	return (singleRightRotation(k3));
}

BinaryNode *AvlTree::doubleRightLeftRotation(BinaryNode *k1)
{
   /***** Complete this function. *****/
   k1->right =singleRightRotation(k1->right);
	return (singleLeftRotation(k1));
}

BinaryNode *AvlTree::singleLeftRotation(BinaryNode *k1)
{
   /***** Complete this function. *****/
   /*** Reference Citation: Data Structures Using C++ by D.S. Malik ***/
   BinaryNode *temp = k1->right;
	k1->right = temp->left; 
	temp->left = k1;

	k1->height = max(height(k1->left), height(k1->right))+1;
   temp->height = max(height(temp->left), height(temp->right))+1;
	
	return temp;
}

int AvlTree::checkBalance(BinaryNode *ptr)
{
    if (ptr == nullptr) return -1;

    int leftHeight  = checkBalance(ptr->left);
    int rightHeight = checkBalance(ptr->right);

    if ((abs(height(ptr->left) - height(ptr->right)) > 1)
        || (height(ptr->left)  != leftHeight)
        || (height(ptr->right) != rightHeight))
    {
        return -2;       // unbalanced
    }

    return height(ptr);  // balanced
}