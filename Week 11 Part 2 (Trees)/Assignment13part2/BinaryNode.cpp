/*
 * BinaryNode.cpp
 *
 *  Created on: Nov 25, 2017
 *      Author: vasubansal
 */


#include "BinaryNode.h"

long BinaryNode::probe_count;
long BinaryNode::compare_count;

BinaryNode::BinaryNode(const long data)
    : data(data), height(0), left(nullptr), right(nullptr)
{
}

BinaryNode::BinaryNode(const long data, BinaryNode *left, BinaryNode *right)
  : data(data), height(0), left(left), right(right)
{
}

BinaryNode::~BinaryNode()
{
}


BinaryNode* &BinaryNode::get_left(){
	probe_count++;
	return left;
}

BinaryNode* &BinaryNode::get_right()
{
	probe_count++;
	return right;
}

int BinaryNode::get_data()
{
	compare_count++;
	return data;
}

void BinaryNode::reset()
{
	probe_count=0;
	compare_count=0;
}


