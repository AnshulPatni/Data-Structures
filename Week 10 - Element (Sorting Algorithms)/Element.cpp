#include <iostream>
#include "Element.h"

using namespace std;

long Element::copy_count;
long Element::destructor_count;

/***** Complete this class. *****/

/**
 * Default constructor.
 */
Element::Element() : value(0){}

/**
 * Constructor.
 * @param val the element's value.
 */
Element::Element(long val) : value(val) {}

/**
 * Copy constructor.
 * @param other the other element to be copied.
 */
Element::Element(const Element& other)
{
    /***** Complete this class. *****/
    this->value = other.get_value();
    copy_count++;
}

/**
 * Destructor.
 */
Element::~Element()
{
    /***** Complete this class. *****/
    destructor_count++;
}

void Element::reset()
{
   copy_count = 0;
   destructor_count = 0;
}

/**
 * Getter.
 * @return the value.
 */
long Element::get_value() const { return value; }

bool Element::operator<(const Element& element) const
{
   if (this->value < element.get_value())
      return true;
   else
      return false;
}
bool Element::operator>(const Element& element) const
{
   if (this->value > element.get_value())
      return true;
   else
      return false;
}
bool Element::operator<=(const Element& element) const
{
   if (this->value <= element.get_value())
      return true;
   else
      return false;
}
bool Element::operator>=(const Element& element) const
{
   if (this->value >= element.get_value())
      return true;
   else
      return false;
}

long Element::get_copy_count()
{
   return copy_count;
}

long Element::get_destructor_count()
{
   return destructor_count;
}

ostream& operator <<(ostream& outs, const Element& element)
{
   outs << element.get_value();
   return outs;
}