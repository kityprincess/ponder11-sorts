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
#define GET_CHILD(x) (x * 2)
#define GET_SIBLING(x) (x + 1)
#define GET_PARENT(x) (x / 2)

template <class T>
void heapify(T array[], int lastIndex);

template <class T>
void percolate_down(T array[], int root, int lastIndex);

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

   heapify(sorted, num);

   for (int i = num; i > 2; --i)
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


/*****************************************************
* HEAPIFY
* Rearrange array into max heap order
****************************************************/
template <class T>
void heapify(T array[], int lastIndex)
{
   for (int root = GET_PARENT(lastIndex); root >= 1; --root)
   {
      percolate_down(array, root, lastIndex);
   }
}


/*****************************************************
* PERCOLATE_DOWN
* Move an item down to its proper order in the heap
****************************************************/
template <class T>
void percolate_down(T array[], int root, int lastIndex)
{
   // Get the left child of the item
   int child = GET_CHILD(root);
   while (root <= lastIndex)
   {
      // If the right child is larger, use that instead
      if (child < lastIndex && array[GET_SIBLING(child)] > array[child])
         child = GET_SIBLING(child);
      // If we happen to be looking at a child index that's
      // too large, we're done; the root's moved down as far
      // as it can go
      else if (child >= lastIndex)
         break;

      // If the child is larger than the root
      if (array[child] > array[root])
      {
         // Swap them
         T temp = array[child];
         array[child] = array[root];
         array[root] = temp;
         // Get the root's new location
         root = child;
         // Grab it's new left child (it's prior grandchild)
         child = GET_CHILD(root);
      }
      else // Otherwise, we're done
         break;
   }
}


#endif // SORT_HEAP_H
