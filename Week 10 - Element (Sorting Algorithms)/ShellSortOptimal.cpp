#include "ShellSortOptimal.h"

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
ShellSortOptimal::ShellSortOptimal(string name) :VectorSorter(name) {}

/**
 * Destructor.
 */
ShellSortOptimal::~ShellSortOptimal() {}

/**
 * Run the optimal shellsort algorithm.
 * According to Don Knuth:
 * h = 3*i + 1 for i = 0, 1, 2, ... used in reverse.
 * @throws an exception if an error occurred.
 */
void ShellSortOptimal::run_sort_algorithm() throw (string)
{
   /***** Complete this member function. *****/
   int a[100];
   a[0] = 1;
   for(int k = 1 ; k < 10 ; k++)
      a[k] = 3 * a[k-1] + 1;
   
   int l, h;  
   
   for(int m = 1; m < 10 ; m++)
   {
      if(a[m] > size)
      {
         l = m - 1;
         break;
      }
   }
   
   while (l >= 0)
   {
      h = a[l];
      for (int i = h; i < size; i++)
      {
         Element temp = data[i];
         int j;
         for (j = i; j >= h ; j -= h)
         {
         	compare_count++;
         	if(data[j - h] > temp)
         	{
         		data[j] = data[j - h];
         		move_count++;
         	}
         	else
         		break;
         }
         data[j] = temp;
      }
      l--;
   }
}
