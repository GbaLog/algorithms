#include "SortAlgorithms.h"
#include <vector>

namespace
{

void mergeTwoSubarrays(int * arr, int left, int mid, int right)
{
  int n1 = mid - left + 1;
  int n2 = right - mid;

  std::vector<int> leftTmp(n1);
  std::vector<int> rightTmp(n2);

  for (int i = 0; i < n1; ++i)
    leftTmp[i] = arr[left + i];
  for (int i = 0; i < n2; ++i)
    rightTmp[i] = arr[mid + 1 + i];

  int i = 0;
  int j = 0;
  int k = left;
  while (i < n1 && j < n2)
  {
    if (leftTmp[i] <= rightTmp[j])
    {
      arr[k] = leftTmp[i];
      ++i;
    }
    else
    {
      arr[k] = rightTmp[j];
      ++j;
    }
    ++k;
  }

  while (i < n1)
  {
    arr[k] = leftTmp[i];
    ++i;
    ++k;
  }

  while (j < n2)
  {
    arr[k] = rightTmp[j];
    ++j;
    ++k;
  }
}

void mergeSortRecursiveImpl(int * arr, int left, int right)
{
  if (left < right)
  {
    int mid = left + (right - left) / 2;
    mergeSortRecursiveImpl(arr, left, mid);
    mergeSortRecursiveImpl(arr, mid + 1, right);
    mergeTwoSubarrays(arr, left, mid, right);
  }
}

void mergeSortIterativeImpl(int * arr, int n)
{
  for (int currSize = 1; currSize <= n - 1; currSize <<= 1)
  {
    for (int leftStart = 0; leftStart < n - 1; leftStart += (currSize << 1))
    {
      int mid = min(leftStart + currSize - 1, n - 1);
      int rightEnd = min(leftStart + (currSize << 1) - 1, n - 1);
      mergeTwoSubarrays(arr, leftStart, mid, rightEnd);
    }
  }
}

} //namespace

void mergeSort(int * arr, int n)
{
  mergeSortIterativeImpl(arr, n);
}
