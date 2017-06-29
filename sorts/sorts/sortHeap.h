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
   T * sorted = new T[num + 1];
   
   for (int i = 1; i <= num; i++)
      sorted[i] = array[i - 1];

   heapify(sorted, num + 1);

   for (int i = num; i > 1; --i)
   {
      T temp = sorted[i];
      sorted[i] = sorted[1];
      sorted[1] = temp;

      percolate_down(sorted, 1, i - 1);
   }
   for (int i = 0; i < num; i++)
      array[i] = sorted[i + 1];
   
   delete[] sorted;
}

template <class T>
void heapify(T array[], int n)
{
   for (int r = n / 2; r >= 1; --r)
   {
      percolate_down(array, r, n);
   }
}

template <class T>
void percolate_down(T array[], int r, int n)
{
   int c = 2 * r;
   while (r <= n)
   {
      if (c < n && array[c + 1] > array[c])
         c++;
      else if (c >= n)
         break;

      if (array[c] > array[r])
      {
         T temp = array[c];
         array[c] = array[r];
         array[r] = temp;
         r = c;
         c *= 2;
      }
      else
         break;
   }
}


#endif // SORT_HEAP_H
