#ifndef BOOK_H_
#define BOOK_H_

#include <string>
using namespace std;

/***** Complete this file. *****/

/**
 * The Book class.
 */
class Book
{
public:
    /**
     * Book categories.
     */
    enum class Category { FICTION, HISTORY, TECHNICAL, NONE };

    /**
     * Default constructor.
     */
    Book();

    /**
     * Constructor.
     */
    Book(string isbn, string last, string first, string title, Category category);

    /**
     * Destructor.
     */
    ~Book();
    
    /***** Complete the public members. *****/
    /**
     * Defining the accessor functions
     */
    void set_isbn(string isbn);
    void set_last(string last);
    void set_first(string first);
    void set_title(string title);
    void set_category(string& category);
    
    string get_isbn();
    string get_isbn1() const;
    string get_last();
    string get_first();
    string get_title();
    string get_category();
    
    /**
     * Defining the friend functions for operator overloading
     */
    friend istream& operator >>(istream& ins, Book& b);
    friend ostream& operator >>(ostream& outs, Book& b);

private:
    
    /***** Complete the private members. *****/
    string isbn, last, first, title;
    Category category;
};

#endif /* EMPLOYEE_H_ */
