/***** Complete this file. *****/
#include "BookNode.h"
#include "Book.h"

 /**
   * Constructor.
   */
BookNode::BookNode(Book book)
{
   this->book = book;
}

 /**
   * Getter function to get the book in the book node
   */
Book BookNode::get_book()
{
   return book;
}

 /**
   * Getter function to get the next link in the book node
   */
BookNode* BookNode::get_next()
{
   return next;
}

 /**
   * Setter function to set the next link in the book node
   */
void BookNode::set_next(BookNode* next)
{
   this->next = next;
}