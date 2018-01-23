/*
 * SortedVector.cpp
 *
 *  Created on: Oct 24, 2017
 *      Author: anshulpatni
 */


#include <iostream>
#include <iterator>
#include "SortedVector.h"

using namespace std;

SortedVector::SortedVector()
{
    Node::reset();
}

SortedVector::~SortedVector()
{
    Node::reset();
}

int SortedVector::size() const { return data.size(); }

bool SortedVector::check() const
{
    if (data.size() == 0) return true;

    vector<Node>::const_iterator it = data.begin();
    vector<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is greater than the previous node.
    while ((it != data.end()) && (*it > *prev))
    {
        prev = it;
        it++;
    }

    return it == data.end();  // Good if reached the end.
}

void SortedVector::prepend(const long value)
{
    /***** Complete this function. *****/
    vector<Node>::iterator it = data.begin();
    data.insert(it, Node(value));
}

void SortedVector::append(const long value)
{
    /***** Complete this function. *****/
   data.push_back(Node(value));
}

void SortedVector::remove(const int index)
{
    /***** Complete this function. *****/
	vector<Node>::iterator it = data.begin();
	advance(it, index);
	data.erase(it);
}

void SortedVector::insert(const long value)
{
    /***** Complete this function. *****/
    vector<Node>::const_iterator it = data.begin();
    while((it != data.end()) && (it->get_value() < value))
      it++;

    data.insert(it, Node(value));
}

Node SortedVector::at(const int index) const
{
    /***** Complete this function. *****/
    vector<Node>::const_iterator it = data.begin();
    advance(it, index);
    return *it;
}

void SortedVector::reserve(const int size)
{
	data.reserve(size);
