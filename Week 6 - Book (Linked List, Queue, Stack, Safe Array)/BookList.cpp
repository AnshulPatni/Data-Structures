#include "BookList.h"
#include "BookNode.h"
#include "Book.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

const string MERGED = "MERGED";
const string AUTHORS_AM = "Authors A-M";
const string AUTHORS_NZ = "Authors N_Z";

/**
 * Constructor
 */
BookList::BookList()
    : name(""), head(nullptr), tail(nullptr)
{
}

/**
 * Constructor
 */
BookList::BookList(const string name)
    : name(name), head(nullptr), tail(nullptr)
{
    if(name != MERGED && name != AUTHORS_AM && name != AUTHORS_NZ)
    {
      create();
      print();
    }
}

/**
 * Function to create the book list with the category given in the file.
 */
void BookList::create()
{
   ifstream input_cat;
   string file_name = name + ".txt";
   input_cat.open(file_name);
   if (input_cat.fail())
   {
      cout << "Failed to open " << file_name << endl;
   }
    
   Book book;
   input_cat >> book;
   while (!input_cat.fail())
   {
      insertion(book);
      input_cat >> book;
   }
   
   input_cat.close();
}

/**
 * Function to insert the book node in the book list.
 */
void BookList::insertion(Book book)
{
   BookNode *temp_node = new BookNode(book);
   string temp_isbn = book.get_isbn();
   
   // Inserting the node at the head of the list.
   if((head == nullptr) || (temp_isbn < head->get_book().get_isbn()))
   {
      temp_node = new BookNode(book);
      temp_node->set_next(head);
      head = temp_node;
      
      if(head->get_next() == nullptr)
      {
         tail = head;
      }
   }
   
   // Inserting the node in middle of the list.   
   else
   {
      BookNode *p = head;
      BookNode *prev;
      
      while ((p != nullptr) && (temp_isbn > p->get_book().get_isbn()))
      {
         prev = p;
         p = p->get_next();
      }
      
      if ((p == nullptr) || (temp_isbn < p->get_book().get_isbn()))
      {
         prev->set_next(temp_node);
         temp_node->set_next(p);
         
         if (p == nullptr)
         {
            tail = prev;
         }
      }
   }
}

/**
 * Function to print the book list.
 */
void BookList::print()
{
   int number_of_books = 0;
   /***** Complete this function. *****/
   cout << endl << "Book list: " << name << endl << endl;
    
   for (BookNode *p = head; p != nullptr; p = p->get_next())
   {
      cout << " " << p->get_book() << endl;
      number_of_books++;
   }
   cout << "  (" << number_of_books << "  books)" << endl;
}

/**
 * Function to merge the book lists to for a single list.
 */
void BookList::merge(vector<string> booklist_categories)
{
   ifstream input_cat;
   BookList* list = new BookList(MERGED);
   int j;
   for(j = 0; j < booklist_categories.size(); j++)
   {
      string file_name = booklist_categories[j] + ".txt";
      input_cat.open(file_name);
      if (input_cat.fail())
      {
         cout << "Failed to open " << file_name << endl;
      }
       
      Book book;
      input_cat >> book;
      while (!input_cat.fail())
      {
         list->insertion(book);
         input_cat >> book;
      }
      
      input_cat.close();
   }
   list->print();
   
   list->split();
}

/**
 * Function to split the book list to form two new lists.
 */
void BookList::split()
{
   BookList *list1 = new BookList(AUTHORS_AM);
   BookList *list2 = new BookList(AUTHORS_NZ);
   
   for(BookNode *p = head; p != nullptr; p = p->get_next())
   {
      // Creating a list with last name of the authors starting from A to M
      if(p->get_book().get_last().at(0) >= 'A' && p->get_book().get_last().at(0) <= 'M')
      {
         list1->insertion(p->get_book());
      }
      // Creating a list with last name of the authors starting from N to Z
      else
      {
         list2->insertion(p->get_book());
      }
   }
   list1->print();
   list2->print();
}
