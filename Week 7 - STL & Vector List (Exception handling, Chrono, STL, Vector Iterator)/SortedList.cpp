#include <iostream>
#include <iterator>
#include <list>
#include <vector>
#include "SortedList.h"

using namespace std;

SortedList::SortedList()
{
    Node::reset();
}

SortedList::~SortedList()
{
    Node::reset();
}

int SortedList::size() const { return data.size(); }

bool SortedList::check()
{
    if (data.size() == 0) return true;

    list<Node>::iterator it = data.begin();
    list<Node>::iterator prev = it;

    it++;

    // Ensure that each node is greater than the previous node.
    while ((it != data.end()) && (*it > *prev))
    {
        prev = it;
        it++;
    }

    return it == data.end();  // Good if reached the end.
}

void SortedList::prepend(const long value)
{
   /***** Complete this function. *****/
   list<Node>::iterator it = data.begin();
   //Node new_node(value);
   
   data.insert(it, Node(value));
}

void SortedList::append(const long value)
{
   /***** Complete this function. *****/
   //list<Node>::iterator it = data.begin();
   data.push_back(Node(value));
}

void SortedList::remove(const int index)
{
    /***** Complete this function. *****/
    list<Node>::iterator it = data.begin();
    advance(it, index);
    data.erase(it);
}

void SortedList::insert(const long value)
{
    /***** Complete this function. *****/
   list<Node>::const_iterator it = data.begin();

   while((it != data.end()) && (it->get_value() < value))
   {
       it++;
   }
   
   data.insert(it, Node(value));
    
}

Node SortedList::at(const int index)
{
    /***** Complete this function. *****/
    list<Node>::const_iterator it = data.begin();
    advance(it, index);
    return *it;
}
