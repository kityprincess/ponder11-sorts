/***********************************************************************
 * Module:
 *    Week 11, Sort Insertion
 *    Brother Helfrich, CS 235
 * Author:
 *    <your name>
 * Summary:
 *    This program will implement the Insertion Sort
 ************************************************************************/

#ifndef SORT_INSERTION_H
#define SORT_INSERTION_H

#include <cassert>

/*****************************************************
 * BINARY SEARCH
 * Returns the location of iInsert using the algorithm
 * in the CS 235 PDF
 ****************************************************/
template <class T>
int binarySearch(T array[], T search, int iBegin, int iEnd)
{
   int iMiddle = (iBegin + iEnd)/2;
   if (iBegin > iEnd)
      return iBegin;
   if (array[iMiddle] == search)
      return iMiddle;
   if (search > array[iMiddle])
      return binarySearch(array, search, iMiddle + 1, iEnd); // recursive search
   else
      return binarySearch(array, search, iBegin, iMiddle - 1);
}

/*****************************************************
 * SORT INSERTION
 * Perform the insertion sort using algorithm from
 * CS 235 PDF
 ****************************************************/
template <class T>
void sortInsertion(T array[], int num)
{
   for (int iPivot = num - 2; iPivot > -1; iPivot--)  // start at end of array
   {
      T valuePivot = array[iPivot];
      // find where to insert
      int iInsert = binarySearch(array, valuePivot, iPivot + 1, num - 1);
      iInsert--;
      for (int iShift = iPivot; iShift < iInsert; iShift++)
         array[iShift] = array[iShift + 1];            // shift to the left
      array[iInsert] = valuePivot;                     // insert value
   }
}

#endif // SORT_INSERTION_H
