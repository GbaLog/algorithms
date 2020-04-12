#ifndef SORTALGORITHMS_H
#define SORTALGORITHMS_H

void bubbleSort(int * arr, int n);
void insertionSort(int * arr, int n);
void shellSort(int * arr, int n);
void selectionSort(int * arr, int n);
void quickSort(int * arr, int n);
void mergeSort(int * arr, int n);
void heapSort(int * arr, int n);
void countingSort(int * arr, int n);
void radixSort(int * arr, int n);

inline int min(int l, int r)
{
  return l < r ? l : r;
}

inline void swap(int & l, int & r)
{
  int tmp = l;
  l = r;
  r = tmp;
}

#endif // SORTALGORITHMS_H
