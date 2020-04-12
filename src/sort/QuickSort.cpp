#include "SortAlgorithms.h"
#include <vector>

namespace
{

int partition(int * arr, int low, int high)
{
  //Select median pivot
  int mid = (low + high) / 2;
  if (arr[mid] < arr[low])
    swap(arr[mid], arr[low]);
  if (arr[high] < arr[low])
    swap(arr[low], arr[high]);
  if (arr[mid] < arr[high])
    swap(arr[high], arr[mid]);

  int pivot = arr[high];
  int i = low - 1;

  for (int j = low; j <= high - 1; ++j)
  {
    if (arr[j] <= pivot)
    {
      ++i;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]);
  return i + 1;
}

void quickSortRecursiveImpl(int * arr, int low, int high)
{
  if (low < high)
  {
    int part = partition(arr, low, high);
    quickSortRecursiveImpl(arr, low, part - 1);
    quickSortRecursiveImpl(arr, part + 1, high);
  }
}

void quickSortIterativeImpl(int * arr, int low, int high)
{
  static int stack[8 * 1024 * 1024];

  int top = -1;
  stack[++top] = low;
  stack[++top] = high;

  while (top >= 0)
  {
    high = stack[top--];
    low = stack[top--];

    int part = partition(arr, low, high);
    if (part - 1 > low)
    {
      stack[++top] = low;
      stack[++top] = part - 1;
    }

    if (part + 1 < high)
    {
      stack[++top] = part + 1;
      stack[++top] = high;
    }
  }
}

} //namespace

void quickSort(int * arr, int n)
{
  quickSortIterativeImpl(arr, 0, n - 1);
}
