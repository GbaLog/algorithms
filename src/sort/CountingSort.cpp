#include "SortAlgorithms.h"
#include <memory>

namespace
{

void findMinMax(int * arr, int n, int & min, int & max)
{
  int minIdx = 0;
  int maxIdx = 0;
  for (int i = 1; i < n; ++i)
  {
    if (arr[i] < arr[minIdx])
      minIdx = i;
    if (arr[i] > arr[maxIdx])
      maxIdx = i;
  }
  min = arr[minIdx];
  max = arr[maxIdx];
}

} //namespace

void countingSort(int * arr, int n)
{
  int min = 0;
  int max = 0;
  findMinMax(arr, n, min, max);
  int range = max - min + 1;

  auto table = std::make_unique<int[]>(range);
  for (int i = 0; i < n; ++i)
    ++table[arr[i] - min];

  for (int i = 1; i < range; ++i)
    table[i] += table[i - 1];

  auto output = std::make_unique<int[]>(n);
  for (int i = n - 1; i >= 0; --i)
  {
    output[table[arr[i] - min] - 1] = arr[i];
    --table[arr[i] - min];
  }

  for (int i = 0; i < n; ++i)
    arr[i] = output[i];
}
