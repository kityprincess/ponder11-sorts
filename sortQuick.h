/***********************************************************************
 * Module:
 *    Week 11, Sort Quick
 *    Brother Helfrich, CS 235
 * Author:
 *    <author>
 * Summary:
 *    This program will implement the Quick Sort.  Credit goes to 
 *    goes to our textbook 13.3 Quicksort.  
 ************************************************************************/

#ifndef SORT_QUICK_H
#define SORT_QUICK_H

template <class T>
int split (T array[], int first, int num);
template <class T>
void swap(int & first, int & second);
template <class T>
void sortQuick(T array[], int num);


/*****************************************************
 * SWAP
 * Swaps the arrays
 ****************************************************/
 template <class T>
 void swap(int & first, int & second)
 {
    int temp = first;
    first = second;
    second = temp;
 }
/*****************************************************
 * SPLIT
 * Splits the array
 ****************************************************/
template <class T>
int split (T array[], int first, int num)
{
   // pivot element
   T pivot = array[first];
   int left = first;
   int right = num;
   
   while (right > left)
   {
      while (array[right] > pivot)
      right--;
        
       while (right > left &&  (pivot > array[left] || array[left] == pivot))   
        left++;
         
         if (right > left)
         swap(array[left], array[right]);
    }
    int pos = right;
    array[first] = array[pos];
    array[pos] = pivot;
    return pos;     
}

template <class T>
void sortQuickHelper(T array[], int first, int num)
{
   // pivots final position
   int pos;
   if (first < num)
    {
       // splits into two sublist
       pos = split(array, first, num);
       
       // sorts the left sublist
       sortQuickHelper(array, first, pos - 1);
       
       // sorts the right sublist
       sortQuickHelper(array, pos + 1, num);
     }
}
/*****************************************************
 * SORT QUICK
 * Perform the quick sort
 ****************************************************/
template <class T>
void sortQuick(T array[], int num)
{
   int first = 0;
   sortQuickHelper(array, first, num - 1);
}


#endif // SORT_QUICK_H
