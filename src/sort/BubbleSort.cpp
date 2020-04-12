#include "SortAlgorithms.h"

void bubbleSort(int * arr, int n)
{
  for (int i = 0; i < n; ++i)
  {
    for (int j = i; j < n; ++j)
    {
      if (arr[i] > arr[j])
        swap(arr[i], arr[j]);
    }
  }
}
