#include "SortAlgorithms.h"

void selectionSort(int * arr, int n)
{
  int min;
  for (int i = 0; i < n - 1; ++i)
  {
    min = i;
    for (int j = i + 1; j < n; ++j)
    {
      if (arr[min] > arr[j])
        min = j;
    }
    swap(arr[min], arr[i]);
  }
}
