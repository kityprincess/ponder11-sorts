/***********************************************************************
 * Module:
 *    Week 11, Sort Select
 *    Brother Helfrich, CS 235
 * Author:
 *    <your name>
 * Summary:
 *    This program will implement the Selection Sort
 ************************************************************************/

#ifndef SORT_SELECTION_H
#define SORT_SELECTION_H

/*****************************************************
 * SORT SELECTION
 * Perform the selection sort using the algorithm
 * outlined in section 13.1 of the textbook
 ****************************************************/
template <class T>
void sortSelection(T array[], int num)
{
   // for each spot in the array, compare it to the smallest item
   for (int iSpot = 0; iSpot < num; iSpot++)
   {
      // Find the smallest element in the array
      int smallPosition = iSpot;
      T smallest = array[smallPosition];
      for (int j = iSpot + 1; j < num; j++)
      {
         if (!(array[j] > smallest) && !(array[j] == smallest)) // smaller element found
         {
            smallPosition = j;
            smallest = array[smallPosition];  // replace smallest with new smallest
         }
      }
      // Now interchange smallest with first element of array
      array[smallPosition] = array[iSpot];
      array[iSpot] = smallest;
   }
}

#endif // SORT_SELECTION_H
