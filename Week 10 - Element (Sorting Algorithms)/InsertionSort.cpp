#include "InsertionSort.h"

/**
 * Constructor.
 * @param name the name of the algorithm.
 */
InsertionSort::InsertionSort(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
InsertionSort::~InsertionSort() {}

/**
 * Run the insertion sort algorithm.
 * @throws an exception if an error occurred.
 */
void InsertionSort::run_sort_algorithm() throw (string)
{
   /***** Complete this member function. *****/
   int i, j;
   for (i = 1; i < size; i++)
   {
      Element key = data[i];
      j = i - 1;
      
      while (j >= 0)
      {
         compare_count++;
         if(data[j] > key)
         {
            data[j+1] = data[j];
            move_count++;
            j = j-1;
         }
         else
            break;
      }
      data[j+1] = key;
   }
}
