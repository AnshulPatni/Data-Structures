#include <string>
#include "Word.h"
using namespace std;

/***** Modify this file as needed. *****/

Word::Word() : text(""), count(0) {}
Word::Word(string text) : text(text), count(1) {}

Word::~Word() {}

int Word::get_count()
{
   return count;
}
string Word::get_text()
{
   return text;
}

void Word::increment_count()
{
   count++;   
}

bool operator!= (Word word1, Word word2)
{
   if(word1.text == word2.text && word1.count==word2.count)
   {
      return false;
   }
   else true;
}
