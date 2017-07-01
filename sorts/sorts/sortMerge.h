/***********************************************************************
 * Module:
 *    Week 11, Sort Merge
 *    Brother Helfrich, CS 235
 * Author:
 *    Kimberly Stowe & Matthew Burr
 * Summary:
 *    This program will implement the Merge Sort
 ************************************************************************/

#ifndef SORT_MERGE_H
#define SORT_MERGE_H

/*****************************************************
 * SORT MERGE
 * Perform the merge sort
 * p = starting index
 * q = midpoint
 * r = last index
 ****************************************************/
template <class T>
void merge(T a[], int p, int q, int r)
{
   int sizeB = q - p + 1;
   int sizeC = r - q;
   T * b = new T[sizeB];
   T * c = new T[sizeC];
   int iB = 0;
   int iC = 0;

   for (int i = 0; i < sizeB; i++)
      b[i] = a[p+i];

   for (int i = 0; i < sizeC; i++)
      c[i] = a[q+i+1];

   for (int i = p; i <= r; i++)
   {
      if (iB >= sizeB)
      {
         a[i] = c[iC++];
      }
      else if (iC >= sizeC)
      {
         a[i] = b[iB++];
      }
      else if (c[iC] > b[iB])
      {
         a[i] = b[iB];
         iB++;
      }
      else
      {
         a[i] = c[iC];
         iC++;
      }
   }

   delete[] b;
   delete[] c;
}

template <class T>
void mergeSort(T a[], int p, int r)
{
   int q;
   if (p < r)
   {
      q = (p + r) / 2;
      mergeSort(a, p, q);
      mergeSort(a, q + 1, r);
      merge(a, p, q, r);
   }
}

template <class T>
void sortMerge(T array[], int num)
{
   mergeSort(array, 0, num - 1);
}


#endif // SORT_MERGE_H
