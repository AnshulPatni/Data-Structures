/**
 * Defining the includes
 */
#include "Book.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

/***** Complete this file. *****/

using namespace std;

// Status codes.
enum class StatusCode {OK, DUPLICATE, NOT_FOUND, INVALID_COMMAND};

/**
 * Find the book in the catalog with the given ISBN.
 * Use a binary search.
 * @param isbn the ISBN.
 * @param catalog the vector of book records.
 * @return the vector index of the book if found, else return -1.
 */
int find(const string isbn, const vector<Book>& catalog);
/**
 * Defining the functions
 */
 
/**
 * Read the input file to create a book catalog.
 * @param command to perform a task on the input in the file.
 * @param catalog the vector of book records.
 * @param input the input stream of data in the file.
 */
void file_input(char command, vector<Book>& catalog, ifstream& input);

/**
 * Compare the string with isbn to find if the book is already added in the catalog.
 * @param temp_string the isbn to search in the catalog.
 * @param catalog the vector of book records.
 * @return true if the book with given isbn is already there.
 */
bool check_book_or_not(string temp_string, vector<Book>& catalog);

/**
 * Add the new book with its details in the book catalog.
 * @param temp_book the details of the book to be added in the catalog.
 * @param catalog the vector of book records.
 * @param command to perform a task on the input in the file.
 */
void add_book(Book temp_book, vector<Book>& catalog, char command);

/**
 * Delete the book from the book catalog.
 * @param temp_string the details of the book to be added in the catalog.
 * @param catalog the vector of book records.
 * @param command to perform a task on the input in the file.
 */
void delete_book(string temp_string, vector<Book>& catalog, char command);

/**
 * Print all the books in the book catalog.
 * @param catalog the vector of book records.
 */
void print_all(vector<Book>& catalog);

/**
 * Print the books for a certain author from the book catalog.
 * @param catalog the vector of book records.
 * @param temp the details of author of the book to be printed.
 */
void print_author(vector<Book>& catalog, string temp);

/**
 * Print the books for a certain category from the book catalog.
 * @param catalog the vector of book records.
 * @param temp the details of category of the book to be printed.
 */
void print_category(vector<Book>& catalog, string temp);

/**
 * Print the book with the given isbn from the book catalog.
 * @param catalog the vector of book records.
 * @param temp the details of the isbn of the book to be printed.
 */
void print_isbn(vector<Book>& catalog, string temp);

const string INPUT_FILE_NAME = "commands.in";

/**
 * The main. Open the command input file and loop to process commands.
 */
int main()
{
    // Open the input file.
    ifstream input;
    input.open(INPUT_FILE_NAME);
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }

    vector<Book> catalog;  // book catalog

    char command;
    input >> command;  // read the first command

    /**
     * Loop to read commands until the end of file.
     */
    while (!input.fail())
    {
        //cout << endl << command << " ";

        /*** Complete this main. *****/
        file_input(command, catalog, input);
        input >> command;
    }
    input.close();
    return 0;
}

/**
 * Function to overload the input operator.
 */
istream& operator >>(istream& ins, Book& b)
{
   string isbn, last, first, title, category, str;
   
   getline (ins, isbn, ',');
   getline (ins, last, ',');
   getline (ins, first, ',');
   getline (ins, title, ',');
   getline (ins, category);
   
   b.set_isbn(isbn);
   b.set_last(last);
   b.set_first(first);
   b.set_title(title);
   b.set_category(category);
   
   return ins;
}

/**
 * Function to overload the output operator.
 */
ostream& operator <<(ostream& outs, Book& b)
{
   outs << "Book{ISBN=" << b.get_isbn() << ", last=" << b.get_last() << ", first=" << b.get_first() << ", title=" << b.get_title() << ", category=" << b.get_category() << "}";
   return outs;
}

/**
 * Read the input file to create a book catalog.
 */
void file_input(char command, vector<Book>& catalog, ifstream& input)
{
   Book temp_book;
   string temp_string;
   bool check = true;

   switch(command)
   {
      case '+':
         {
            input >> ws;
            input >> temp_book;
            check = check_book_or_not(temp_book.get_isbn(), catalog);
            if(check == true)
            {
               int i, position = 0;
               cout << endl;
               for(i = 1; i < catalog.size(); i++)
               {
                  if (temp_book.get_isbn() > catalog[i].get_isbn())
                  {
                     position = i;
                  }
                  else
                     break;
               }
               
               cout << endl << command << " " << "Inserted at index " << position+1 << ": "  << temp_book;
               
               cout << endl << "*** Duplicate ISDN ***";
            }
            else
               add_book(temp_book, catalog, command);
            break;
         }
      case '-':
         {
            input >> ws >> temp_string;
            if (temp_string.substr(0,3) == "978")
            {
               check = check_book_or_not(temp_string, catalog);
               if(check == false)
               {
                  cout << endl << endl << "- Removed Book{ISBN=" << temp_string << ", last=, first=, title=, category=none}";
                  cout << endl << "*** Book not found ***" << endl;
               }
               else
                  delete_book(temp_string, catalog, command);
            }
            break;
         }
      case '?':
         {
            string temp;
            getline(input, temp);
            if(temp.size()==0)
            {
               print_all(catalog);
            }
            else
            {
               string temp2;
               istringstream in(temp);
               getline(in, temp2, '=');
               if (temp2.substr(1) == "author")
               {
                  print_author(catalog, temp);
               }
               else if (temp2.substr(1) == "category")
               {
                  print_category(catalog, temp);
               }
               else if (temp2.substr(1) == "isbn")
               {
                  print_isbn(catalog, temp);
               }
            }
               
            break;
         }
      case '$':
         {
            cout<< endl << endl << "$ *** Invalid command ***";
            break;
         }
      default:
      {
         //do nothing
      }
   }
}

/**
 * Add the new book with its details in the book catalog.
 */
void add_book(Book temp_book, vector<Book>& catalog, char command)
{
   int position = 0;
   int i;
   if (catalog.empty())
   {
      catalog.push_back(temp_book);
      cout << endl << command << " " << "Inserted at index 0: "  << temp_book << endl;
      
      return;
   }
   
   for(i = 1; i < catalog.size(); i++)
   {
      if (temp_book.get_isbn() > catalog[i].get_isbn())
      {
         position = i;
      }
      else
         break;
   }
   
   
   if(position == catalog.size()-1)
   {
      catalog.push_back(temp_book);
   }
   else
   {
      catalog.insert(catalog.begin() + position+1, temp_book);
   }
   
   cout << endl << command << " " << "Inserted at index " << position+1 << ": "  << temp_book << endl;
}

/**
 * Delete the book in the book catalog.
 */
void delete_book(string temp_string, vector<Book>& catalog, char command)
{
   int position;
   int i;
   for(i = 0; i < catalog.size(); i++)
   {
      if(catalog[i].get_isbn() == temp_string)
      {
         position = i;
         break;
      }
   }
   
   cout << endl << endl << command << " Removed " << catalog[i];
   
   if(i == catalog.size())
   {
   }
   else
   {
      catalog.erase(catalog.begin() + position);   
   }
}

/**
 * Compare the string with isbn to find if the book is already added in the catalog.
 */
bool check_book_or_not(string temp_string, vector<Book>& catalog)
{
   int i;
   bool temp = true;
   for(i = 0; i < catalog.size(); i++)
   {
      if(catalog[i].get_isbn() == temp_string)
      {
         temp = true;
         return temp;
      }
   }
   return false;
}

/**
 * Print all the books from the book catalog.
 */
void print_all(vector<Book>& catalog)
{
   cout << endl << "? All books in the catalog:";
   for (int i = 0; i < catalog.size(); i++)
   {
      cout << endl << catalog[i];
   }
}

/**
 * Print the book with the given author from the book catalog.
 * Using linear search.
 */
void print_author(vector<Book>& catalog, string temp)
{
   int i;
   cout << endl << endl << "? Books by author " << temp.substr(8) << ":";
   
   // Implemeting linear search to find the books with given author
   for(i = 0; i < catalog.size(); i++)
   {
      if(temp.substr(8) == catalog[i].get_last())
      {
         cout << endl << catalog[i];
      }
   }
}

/**
 * Print the book with the given category from the book catalog.
 * Using linear search.
 */
void print_category(vector<Book>& catalog, string temp)
{
   int i;
   cout << endl << endl << "? Books in category " << temp.substr(10) << ":";
   
   // Implemeting linear search to find the books with given category
   for(i = 0; i < catalog.size(); i++)
   {
      if(temp.substr(10) == catalog[i].get_category())
      {
         cout << endl << catalog[i];
      }
   }
}

/**
 * Print the book with the given isbn from the book catalog.
 */
void print_isbn(vector<Book>& catalog, string temp)
{
   int i = 0;
   cout << endl << endl << "? Book with ISBN " << temp.substr(6) << ":";
   
   i = find(temp.substr(6), catalog);
   
   if(i > 0)
   {
      cout << endl << catalog[i];
   }
}

/**
 * Find the book in the catalog with the given ISBN.
 * Using a binary search.
 */
int find(const string isbn, const vector<Book>& catalog)
{
   int low = 1, high = catalog.size(), mid;

   mid = (catalog.size() + 1) / 2;
   
   // Implemeting binary search to find the book with given isbn
   while(low <= high)
   {
      if(isbn > catalog[mid].get_isbn1())
      {
         low = mid + 1;
      }
      else if (isbn < catalog[mid].get_isbn1())
      {
         high = mid - 1;
      }
      
      mid = (low + high) / 2;
      if (isbn == catalog[mid].get_isbn1())
      {
         return mid;
      }
   }
   
   return -1;
}
