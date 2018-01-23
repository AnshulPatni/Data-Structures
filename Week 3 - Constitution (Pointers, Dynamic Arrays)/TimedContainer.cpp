#include "TimedContainer.h"
#include "Word.h"
#include <chrono>

using namespace std::chrono;

/***** Modify this file as needed. *****/

Word *TimedContainer::timed_insert(const string text)
{
    steady_clock::time_point start_time = steady_clock::now();

    Word *word = insert(text);

    steady_clock::time_point end_time = steady_clock::now();
    
    long elapsed = duration_cast<microseconds>(end_time - start_time).count();
    increment_elapsed_time(elapsed);

    return word;
}

Word *TimedContainer::timed_search(const string text)
{
    steady_clock::time_point start_time = steady_clock::now();

    Word *word = search(text);

    steady_clock::time_point end_time = steady_clock::now();
    
    long elapsed = duration_cast<microseconds>(end_time - start_time).count();
    increment_elapsed_time(elapsed);

    return word;
}

TimedContainer::TimedContainer():elapsed_time(0)
{
}

TimedContainer::~TimedContainer()
{
}

long TimedContainer::get_elapsed_time() const
{
   return elapsed_time;
}

void TimedContainer::reset_elapsed_time()
{
   elapsed_time = 0;
}

void TimedContainer::increment_elapsed_time(long time)
{
   elapsed_time = elapsed_time + time;
}