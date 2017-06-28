/***********************************************************************
 * Module:
 *    Week 11, Sort Heap
 *    Brother Helfrich, CS 235
 * Author:
 *    <your name>
 * Summary:
 *    This program will implement the Heap Sort
 ************************************************************************/

#ifndef SORT_HEAP_H
#define SORT_HEAP_H

/*****************************************************
 * SORT HEAP
 * Perform the heap sort
 ****************************************************/
template <class T>
void sortHeap(T array[], int num)
{
   
}

template <class T>
void percolate_down(T array[], int r, int n)
{
   int child = 2 * r;
   while (r <= n)
   {
      if (child < n && array[child] < array[child + 1])
         child++;

      if (array[r] < array[c])

   }
}


#endif // SORT_HEAP_H
