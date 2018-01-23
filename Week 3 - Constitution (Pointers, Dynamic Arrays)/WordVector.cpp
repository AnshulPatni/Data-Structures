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

bool WordVector::caseInsensitiveStringCompare(const string& str1, const string& str2) 
{
   if (str1.size() != str2.size())
   {
      return false;
   }
   for (string::const_iterator c1 = str1.begin(), c2 = str2.begin(); c1 != str1.end(); ++c1, ++c2) {
     if (tolower(*c1) != tolower(*c2))
     {
         return false;
     }
   }
    return true;
}

Word *WordVector::search(const string text)
{
    /***** Complete this member function. *****/
    //steady_clock::time_point start_time = steady_clock::now();
    Word temp(text);
    
    int pos = binary_search(text, data.size()-1);

    /*steady_clock::time_point end_time = steady_clock::now();
    long elapsed = duration_cast<microseconds>(end_time - start_time).count();
    increment_elapsed_time(elapsed);*/

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

    while (low <= high) {
        mid = (low + high)/2;

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
