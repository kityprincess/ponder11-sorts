/***********************************************************************
 * Module:
 *    Week 11, Sort Merge
 *    Brother Helfrich, CS 235
 * Author:
 *    <author>
 * Summary:
 *    This program will implement the Merge Sort
 ************************************************************************/

#ifndef SORT_MERGE_H
#define SORT_MERGE_H

/*****************************************************
 * SORT MERGE
 * Perform the merge sort
 ****************************************************/
template <class T>
void merge(T dest[], int iBegin1, int iBegin2, int iEnd2, T source[])
{
   int iEnd1 = iBegin2 - 1;
   int i1 = iBegin1;
   int i2 = iBegin2;

   for (int iD = iBegin1; iD <= iEnd2; iD++) // may need to add 1 to iBegin1
   {
      if (i1 <= iEnd1 && (i2 == iEnd2 || source[i2] > source[i1]))
         dest[iD] = source[i1++];
      else
         dest[iD] = source[i2++];
   }
}

template <class T>
void sortMerge(T array[], int num)
{
//   T dest[] = new T[num];
   int iBegin1 = 0;
   int iBegin2 = 0;
   int iEnd1 = 0;
   int iEnd2 = 0;
   T * source = new T[num];
   int numIterations = 0;

   for (int i = 0; i < num; i++)
   {
      source[i] = array[i];
   }

   /*do
   {*/
   int count = 1;
      while (count < 4)
      {
         numIterations++;
         count++;
         for (iEnd1 = iBegin1 + 1; iEnd1 < num && (source[iEnd1] > source[iEnd1 - 1]); iEnd1++)
         {
         }

         iBegin2 = iEnd1;

         for (iEnd2 = iBegin2 + 1; iEnd2 < num && !(source[iEnd2 - 1] > source[iEnd2]); iEnd2++)
         {
         }
         //cout << "iBegin2 =" << iBegin2 << endl;
         if (iBegin2 < num)
         {
            cout << "iBegin1 =" << iBegin1 << endl;
            cout << "iBegin2 =" << iBegin2 << endl;
            cout << "iEnd2 =" << iEnd2 << endl;
            merge(array, iBegin1, iBegin2, iEnd2, source);
         }
         iBegin1 = iEnd2;

         /*T * temp = new T[num];
         for (int i = 0; i < num; i++)
            temp[i] = source[i];*/
         for (int i = 0; i < num; i++)
            source[i] = array[i];
         /*for (int i = 0; i < num; i++)
            array[i] = temp[i];*/
         }
   /*} 
   while (numIterations > 1);*/

   if (array != source)
   {
      for (int i = 0; i < num; i++)
         array[i] = source[i];
   }
}



/*
void Merge(std::vector<int> & data, int lowl, int highl, int lowr, int highr);
void MergeSort(std::vector<int> & data, int low, int high)
{
if (low >= high)
{
return;
}

int mid = low + (high-low)/2;

MergeSort(data, low, mid);

MergeSort(data, mid+1, high);

Merge(data, low, mid, mid+1, high);
}

void Merge(std::vector<int> & data, int lowl, int highl, int lowr, int highr)
{
int tmp_low = lowl;
std::vector<int> tmp;

while (lowl <= highl && lowr <= highr)
{
if (data[lowl] < data[lowr])
{
tmp.push_back(data[lowl++]);
}
else if (data[lowr] < data[lowl])
{
tmp.push_back(data[lowr++]);
}
else
{
tmp.push_back(data[lowl++]);
tmp.push_back(data[lowr++]);
}
}

while (lowl <= highl)
{
tmp.push_back(data[lowl++]);
}

while (lowr <= highr)
{
tmp.push_back(data[lowr++]);
}

std::vector<int>::const_iterator iter = tmp.begin();

for(; iter != tmp.end(); ++iter)
{
data[tmp_low++] = *iter;
}
}
*/

#endif // SORT_MERGE_H
