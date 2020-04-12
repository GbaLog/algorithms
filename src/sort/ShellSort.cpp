#include "SortAlgorithms.h"

void shellSort(int * arr, int n)
{
  for (int gap = n / 2; gap > 0; gap /= 2)
  {
    for (int i = gap; i < n; ++i)
    {
      int k = arr[i];
      int j = i;
      for (; j >= gap && arr[j - gap] > k; j -= gap)
        arr[j] = arr[j - gap];
      arr[j] = k;
    }
  }
}
