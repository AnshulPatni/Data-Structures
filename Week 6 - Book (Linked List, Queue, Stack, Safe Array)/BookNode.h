#ifndef BOOKNODE_H_
#define BOOKNODE_H_

#include "Book.h"

/**
 * A book node in a linked list.
 */
class BookNode
{
public:
    /**
     * Constructor.
     * @param book this node's book.
     */
    BookNode(Book book);

    /***** Complete this class. *****/
    
    /**
      * Getter function to get the book in the book node
      */
    Book get_book();
    /**
      * Setter function to set the pointer to the next value in the book nodes
      * @param next this node's link to next value.
      */
    void set_next(BookNode* next);
    /**
      * Getter function to get the pointer to the next value in the book nodes
      * @param next this node's link to next value.
      */
    BookNode* get_next();

private:
    Book book;       // this node's book
    BookNode *next;  // link to the next node in the list
};

#endif /* BOOKNODE_H_ */
