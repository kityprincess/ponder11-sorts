/***********************************************************************
 * Module:
 *    Week 11, Sort Bubble
 *    Brother Helfrich, CS 235
 * Author:
 *    Shayla Nelson
 * Summary:
 *    This program will implement the Bubble Sort
 ************************************************************************/

#ifndef SORT_BUBBLE_H
#define SORT_BUBBLE_H

/*****************************************************
 * SORT BUBBLE
 * Perform the bubble sort using the algorithm
 * found in Chapter 4.4 of the CS 124 textbook
 ****************************************************/
template <class T>
void sortBubble(T array[], int num)
{
   // did we switch two values on the last time through the outer loop?
   bool switched = true;

   // for each spot in the array, find the item that goes there with iCheck
   for (int iSpot = num - 1; iSpot >= 1 && switched; iSpot--)
   {
      for (int iCheck = 0, switched = false; iCheck <= iSpot - 1; iCheck++)
      {
         if (array[iCheck] > array[iCheck + 1])
         {
            T temp = array[iCheck];    // swap 2 items if out of order
            array[iCheck] = array[iCheck + 1];
            array[iCheck + 1] = temp;
            switched = true;             // a swap happened, do outer loop again
         }
      }
   }
}

#endif // SORT_BUBBLE_H
