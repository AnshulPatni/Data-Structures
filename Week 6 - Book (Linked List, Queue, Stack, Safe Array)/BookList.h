#ifndef BOOKLIST_H_
#define BOOKLIST_H_

#include "BookNode.h"
#include <string>
#include <iostream>
#include <vector>
/**
 * A list of book nodes.
 */
class BookList
{
public:
    /**
     * Constructor.
     */
    BookList();
    /**
     * Constructor.
     * @param name the name of this list.
     */
    BookList(const string name);

    /**
     * Print the list.
     */
    void print();
    /**
     * Creating the list.
     */
    void create();
    /**
     * Inserting nodes in the list.
     */
    void insertion(Book book);
    /**
     * Merging the lists to form a comprehensive list.
     */
    void merge(vector<string> booklist_categories);
    /**
     * Splitting the merged list to set of two lists.
     */
    void split();
    /***** Complete this class. *****/

private:
    string name;      // name of this book list
    BookNode *head;   // head of the list of book nodes
    BookNode *tail;   // tail of the list of book nodes
};

#endif /* BOOKLIST_H_ */
