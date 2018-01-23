#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include "WordVector.h"

using namespace std::chrono;
/***** Complete this file. *****/

using namespace std;

WordVector::WordVector()
{
    /***** Complete this member function. *****/
}

WordVector::~WordVector()
{
    /***** Complete this member function. *****/
}

Word *WordVector::insert(const string text)
{
   /***** Complete this member function. *****/
   bool check = false;
   Word *temp;
   Word temp_word(text);
    
    if(data.size() == 0)
    {
       data.push_back(temp_word);
    }
    else
    {
        int pos = binary_search(text, data.size()-1);

        if (pos < 0)
        {
            int position = 0;
            
            vector<Word>::iterator it = data.begin();

            while((it != data.end()) && ((*it).get_text() < text))
            {
               it++;
               position++;
            }
            
            if(it != data.end())
            {
               data.insert(it, temp_word);
               temp = &data[position];
               return temp;
            }
            else
            {
               data.push_back(temp_word);
               temp = &data[data.size()];
               return temp;
            }
        }
        else
        {
            data[pos].increment_count();
            temp = &data[pos];
            return temp;
        }
    }
    
}

Word *WordVector::search(const string text)
{
    /***** Complete this member function. *****/
    
    int pos = binary_search(text, data.size()-1);

    if(pos > 0)
    {
       return &(*(data.begin()+pos));
    }
    else
    {
       return &(*data.end());
    }
}

long WordVector::get_size()
{
   return data.size();
}

vector<Word>& WordVector::get_data()
{
   return data;
}

int WordVector::binary_search(string text, int high)
{
   int low = 0;
   int mid;

   while (low <= high)
   {
      mid = ( (low + high) / 2 );
      if(data[mid].get_text() == text)
      {
         return mid;
      }
      else if(data[mid].get_text() > text)
      {
         high = mid-1;
      }
      else
      {
         low = mid+1;
      }
   }
    return -1;
}
