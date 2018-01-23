#include "BookList.h"
#include "Book.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

const string CATEGORIES_FILE_NAME = "categories.txt";

/**
 * The main. Create and print the book lists.
 */
int main()
{
   /***** Complete this main. *****/
   // Open the input file.
   ifstream input;
   input.open(CATEGORIES_FILE_NAME);
   if (input.fail())
   {
      cout << "Failed to open " << CATEGORIES_FILE_NAME << endl;
      return -1;
   }
    
   string category;
   input >> category;
   vector<string> booklist_categories;
   
   while (!input.fail())
   {
      BookList* list = new BookList(category);
      booklist_categories.push_back(category);
      input >> category;
   }
   
   BookList *merged_list = new BookList();
   merged_list->merge(booklist_categories);
   
   return 0;
}

/***** Complete this file. *****/
