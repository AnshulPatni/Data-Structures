#ifndef BOOK_H_
#define BOOK_H_

#include <string>
using namespace std;
/**
 * The Book class.
 */
class Book
{
    /***** Complete this class. *****/

public:

    /**
     * Default constructor.
     */
    Book();

    /**
     * Constructor.
     */
    Book(string isbn, string last, string first, string title);

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
    
    string get_isbn();
    string get_last();
    string get_first();
    string get_title();
    
    /**
     * Defining the friend functions for operator overloading
     */
    friend istream& operator >>(istream& ins, Book& b);
    friend ostream& operator <<(ostream& outs, Book b);

private:
    
    /***** Complete the private members. *****/
    string isbn, last, first, title;
};

#endif /* BOOK_H_ */
