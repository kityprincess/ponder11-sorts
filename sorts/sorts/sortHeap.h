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

// The following macros perform common operations to help navigate around
// the tree
#define GET_CHILD(x) (x * 2) // Gets the ID for a child of a given element
#define GET_SIBLING(x) (x + 1) // Gets the ID for the sibling of a given element
#define GET_PARENT(x) (x / 2) // Gets the ID for the parent of a given element
#define IDX(x) (x - 1) // Translates an ID into the appropriate index into an array
#define ITEM_AT(a, x) (a[IDX(x)]) // Looks up an item by ID from an array

template <class T>
void heapify(T array[], int lastIndex);

template <class T>
void percolate_down(T array[], int root, int lastIndex);

template <class T>
void swap(T array[], int a, int b);

/*****************************************************
 * SORT HEAP
 * Perform the heap sort
 ****************************************************/
template <class T>
void sortHeap(T array[], int num)
{
   heapify(array, num);

   for (int i = num; i > 2; --i)
   {
      swap(array, 1, i);

      percolate_down(array, 1, i - 1);
   }
}

/*****************************************************
* SWAP
* Switches the values of two items in the heap
* specified by their IDs
****************************************************/
template <class T>
void swap(T array[], int a, int b)
{
   T temp = ITEM_AT(array, a);
   ITEM_AT(array, a) = ITEM_AT(array, b);
   ITEM_AT(array, b) = temp;
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
      //if (child < lastIndex && array[GET_SIBLING(child)] > array[child])
      if (child < lastIndex && ITEM_AT(array, GET_SIBLING(child)) > ITEM_AT(array, child))
         child = GET_SIBLING(child);
      
      // If we happen to be looking at a child index that's
      // too large, we're done; the root's moved down as far
      // as it can go
      else if (child >= lastIndex)
         break;

      // If the child is larger than the root
      //if (array[child] > array[root])
      if (ITEM_AT(array, child) > ITEM_AT(array, root))
      {
         // Swap them
         swap(array, root, child);

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
