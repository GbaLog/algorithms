#include "SortAlgorithms.h"
#include <memory>

namespace
{

int getMax(int * arr, int n)
{
  int maxElem = arr[0];
  for (int i = 1; i < n; ++i)
  {
    if (maxElem < arr[i])
      maxElem = arr[i];
  }
  return maxElem;
}

void countingSort(int * arr, int n, int exp)
{
  int count[10] = {};
  for (int i = 0; i < n; ++i)
    ++count[(arr[i] / exp) % 10];

  for (int i = 1; i < n; ++i)
    count[i] += count[i - 1];

  auto output = std::make_unique<int[]>(n);
  for (int i = n - 1; i >= 0; --i)
  {
    output[count[(arr[i] / exp) % 10]] = arr[i];
    --count[(arr[i] / exp) % 10];
  }

  for (int i = 0; i < n; ++i)
    arr[i] = output[i];
}

} //namespace

void radixSort(int * arr, int n)
{
  int m = getMax(arr, n);

  for (int exp = 1; m / exp > 0; exp *= 10)
  {
    countingSort(arr, n, exp);
  }
}
