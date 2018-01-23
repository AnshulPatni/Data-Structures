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
   /*** Reference Citation: Data Structures Using C++ by D.S. Malik ***/
   if(ptr==nullptr)
   {
      return -1;
   }
   else
   {
      return ( 1 + max( height(ptr->right), height(ptr->left) ) );
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
   /*** Reference Citation: CMPE180.92 Slides by Ron Mak ***/
   if (ptr == nullptr)
      return nullptr;
   if(ptr->left == nullptr)
      return ptr;
   return findMin(ptr->left);
}

long BinarySearchTree::findMax() const throw(string)
{
    if (isEmpty()) throw(string("Empty tree"));
    return findMax(root)->data;
}

BinaryNode *BinarySearchTree::findMax(BinaryNode *ptr) const
{
   /***** Complete this function. *****/
   /*** Reference Citation: CMPE180.92 Slides by Ron Mak ***/
   if (ptr != nullptr)
   {
      while (ptr->right != nullptr)
      {
         ptr = ptr->right;
      }
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
   /*** Reference Citation: CMPE180.92 Slides by Ron Mak ***/
   while (ptr != nullptr)
   {
      if (data < ptr->data)
      {
         ptr = ptr->left;
      }
      else if (data > ptr->data)
      {
         ptr = ptr->right;
      }
      else
         return true;
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
   /*** Reference Citation: CMPE180.92 Slides by Ron Mak ***/
   if (ptr == nullptr)
   {
      ptr = new BinaryNode(data);
   }
   else if (data < ptr->data)
   {
      insert(data, ptr->left);
   }
   else if (data > ptr->data)
   {
      insert(data, ptr->right);
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
   /*** Reference Citation: CMPE180.92 Slides by Ron Mak ***/
   if (ptr == nullptr) return;

   if (data < ptr->data)
   {
      remove(data, ptr->left);
   }
   else if (data > ptr->data)
   {
      remove(data, ptr->right);
   }
   else if ((ptr->left  != nullptr) && (ptr->right != nullptr))
   {
      ptr->data = findMin(ptr->right)->data;
      remove(ptr->data, ptr->right);
   }
   else
   {
      BinaryNode *oldNode = ptr;
      if (ptr->left != nullptr)
      {
         ptr = ptr->left;
      }
      else
      {
         ptr = ptr->right;
      }
      
      delete oldNode;
   }
}
