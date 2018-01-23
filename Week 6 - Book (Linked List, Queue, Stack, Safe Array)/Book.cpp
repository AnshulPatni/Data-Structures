/***** Complete this file. *****/
#include "Book.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

/***** Complete this file. *****/

/**
 * Default Constructor to initialize all the elements in the book class
 */
 Book::Book():isbn(""), last(""), first(""), title("")
 {
 }

/**
 * Constructor to initialize the elements in the book class with given values
 */
Book::Book(string isbn, string last, string first, string title):isbn(isbn), last(last), first(first), title(title)
{
}

/**
 * Default Destructor
 */
Book::~Book()
{
   
}

/**
 * Setter functions to set the values of the elements in the book class
 */
void Book::set_isbn(string isbn)
{
   this->isbn = isbn;
}
void Book::set_last(string last)
{
   this->last = last;
   
}
void Book::set_first(string first)
{
   this->first = first;
}
void Book::set_title(string title)
{
   this->title = title;
}

/**
 * Getter functions to get the values of the elements in the book class
 */ 
string Book::get_isbn()
{
   return isbn;
}

string Book::get_last()
{
   return last;
}
string Book::get_first()
{
   return first;
}
string Book::get_title()
{
   return title;
}


istream& operator >>(istream& ins, Book& b)
{
   getline (ins, b.isbn, ',');
   getline (ins, b.last, ',');
   getline (ins, b.first, ',');
   getline (ins, b.title);
   
   return ins;
}

ostream& operator <<(ostream& outs, Book b)
{
   outs << "Book{ISBN=" << b.get_isbn() << ", last=" << b.get_last() << ", first=" << b.get_first() << ", title=" << b.get_title() << "}";
   return outs;
}
