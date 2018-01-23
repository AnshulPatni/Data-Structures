#include <iostream>
#include <map>
#include <chrono>
#include "WordMap.h"

using namespace std::chrono;
/***** Complete this file. *****/

using namespace std;

WordMap::WordMap()
{
    /***** Complete this member function. *****/
}

WordMap::~WordMap()
{
    /***** Complete this member function. *****/
}

Word *WordMap::insert(const string text)
{
    /***** Complete this member function. *****/
    //steady_clock::time_point start_time = steady_clock::now();

    map<string, Word>::iterator it;
    
    it= data.find(text);

    if (it == data.end())
    {
        data.insert(std::pair<string, Word>(text, Word(text)));
    }
    else
    {
        (it->second).increment_count();
    }
    
    /*steady_clock::time_point end_time = steady_clock::now();
    long elapsed = duration_cast<microseconds>(end_time - start_time).count();
    increment_elapsed_time(elapsed);*/
    
    return &(it->second);
}

Word *WordMap::search(const string text)
{
    /***** Complete this member function. *****/
    steady_clock::time_point start_time = steady_clock::now();

    map<string, Word> temp;
    map<string, Word>::iterator it;
    
    it = data.find(text);
    
    steady_clock::time_point end_time = steady_clock::now();
    long elapsed = duration_cast<microseconds>(end_time - start_time).count();
    increment_elapsed_time(elapsed);
    return &(it->second);
}

map<string, Word>& WordMap::get_data()
{
   return data;
}

long WordMap::get_size()
{
   return data.size();
}