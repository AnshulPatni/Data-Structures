#include <string>
#include "MergeSort.h"

/**
 * Constructor.
 * @param name the name of the algorithm.
 */
MergeSort::MergeSort(string name) : ListSorter(name) {}

/**
 * Destructor.
 */
MergeSort::~MergeSort() {}

/**
 * Run the mergesort algorithm.
 * @throws an exception if an error occurred.
 */
void MergeSort::run_sort_algorithm()
    throw (string)
{
    // Defensive programming: Make sure we end up
    // with the same size list after sorting.
    int size_before = data.get_size();

    mergesort(data);

    // Check sizes.
    int size_after = data.get_size();
    if (size_before != size_after)
    {
        string message = "*** Size mismatch: before " +
                         to_string(size_before) + ", size after " +
                         to_string(size_after);
        throw message;
    }
}

/**
 * The mergesort algorithm recursively splits and merges data lists.
 * Refrence Geeks for Geek
 * @param list the list of data to sort.
 */
void MergeSort::mergesort(LinkedList& list)
{
    /** Complete this member function. **/
   Node* head=list.get_head();
   if(list.get_size()>1)
   {
   LinkedList a;
	LinkedList b;
	if ((head == NULL) || (head->next == NULL))
	{
	   return;
	}
	list.split(a, b);
	mergesort(a);
	mergesort(b);
	merge(list, a, b);
   }
}

/**
 * Merge two sublists back into a single list.
 * @param list the merged list.
 * @param sublist1 the first sublist.
 * @param sublist2 the second sublist.
 */
void MergeSort::merge(LinkedList& list,
                      LinkedList& sublist1, LinkedList& sublist2)
{
    /** Complete this member function. **/
   Node* l1 = sublist1.get_head();
   Node* l2 = sublist2.get_head();
   
   Node *temp;

   list.reset();
   
   while ((l1 != nullptr) && (l2 != nullptr))
   {
    	compare_count++;
    	move_count++;
      if (l2->element >= l1->element)
      {
        	list.add(sublist1.remove_head());
        	temp = sublist1.get_head();
        	l1 = temp;
      }
      else
      {
        	list.add(sublist2.remove_head());
        	temp = sublist2.get_head();
        	l2 = temp;
      }
   }
   
   Node* p = sublist2.get_head();
   
   if (l1 == nullptr)
   {
    	while(p != nullptr)
    	{
    	   move_count++;
    		p = p->next;
    	}
      list.concatenate(sublist2);
      move_count++;
   }

   if (l2 == nullptr)
   {
		while(p != nullptr)
		{
		   move_count++;
			p = p->next;
		}
		list.concatenate(sublist1);
      move_count++;
   }
}

/**
 * Clear the data.
 */
void MergeSort::clear() { data.clear(); }