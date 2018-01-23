/*
 * BinaryNode.h
 *
 *  Created on: Nov 25, 2017
 *      Author: vasubansal
 */


/**
 * A node of a binary tree.
 *
 * Author: Ron Mak
 *         Department of Computer Engineering
 *         San Jose State University
 *
 * Modified from Data Structures and Algorithm Analysis in C++, 4th ed.
 * by Mark Allen Weiss
 * Pearson, 2014
 */
#ifndef BINARY_NODE_H
#define BINARY_NODE_H

class BinaryNode
{
public:
    /**
     * Constructor.
     * @param data the data item.
     */
    BinaryNode(const long data);

    /**
     * Constructor.
     * @param data the data item.
     * @param left the left link.
     * @param right the right link.
     */
    BinaryNode(const long data, BinaryNode *left, BinaryNode *right);

    /**
     * Destructor.
     */
    virtual ~BinaryNode();

    BinaryNode* &get_left();
    BinaryNode* &get_right();
    int get_data();

    long data;
    int height;  // node height

    BinaryNode *left;
    BinaryNode *right;
    static long probe_count, compare_count;
    static void reset();
};

#endif // BINARY_NODE_H
