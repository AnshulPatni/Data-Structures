#include "Book.h"

using namespace std;

/***** Complete this file. *****/

/**
 * Default Constructor to initialize all the elements in the book class
 */
 Book::Book():isbn(""), last(""), first(""), title(""), category()
 {
 }

/**
 * Constructor to initialize the elements in the book class with given values
 */
Book::Book(string isbn, string last, string first, string title, Category category):isbn(isbn), last(last), first(first), title(title), category(category)
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
void Book::set_category(string& category1)
{
   if(category1 == "technical")
   {
      this->category = Category::TECHNICAL;
   }
   else if(category1 == "fiction")
   {
      this->category = Category::FICTION;
   }
   else if(category1 == "history")
   {
      this->category = Category::HISTORY;
   }
   else
      this->category = Category::NONE;
}

/**
 * Getter functions to get the values of the elements in the book class
 */ 
string Book::get_isbn()
{
   return isbn;
}
string Book::get_isbn1() const
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
string Book::get_category()
{
   if(category == Category::TECHNICAL)
   {
      return "technical";
   }
   else if(category == Category::FICTION)
   {
      return "fiction";
   }
   else if(category == Category::HISTORY)
   {
      return "history";
   }
   else if (category == Category::NONE)
   {
      return "none";
   }
}
