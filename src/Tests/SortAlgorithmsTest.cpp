#include <gtest/gtest.h>
#include "SortAlgorithms.h"
#include <algorithm>
#include <random>

class SortAlgorithmsTest : public ::testing::Test
{
public:
  virtual void SetUp() override
  {
    for (size_t i = 0; i < _worstArrSize; ++i)
    {
      _worstArr[_worstArrSize - i - 1] = i;
    }

    size_t end = _avgArrSize / 2 + (_avgArrSize & 1);
    for (size_t i = 0; i < end; ++i)
    {
      _avgArr[i * 2] = i;
      _avgArr[i * 2 + 1] = _avgArrSize - i - 1;
    }

    for (size_t i = 0; i < _bestArrSize; ++i)
      _bestArr[i] = i;

    end = _countingArrSize / 2 + (_countingArrSize & 1);
    for (size_t i = 0; i < end; ++i)
    {
      _countingArr[i * 2] = i % 100;
      _countingArr[i * 2 + 1] = (_avgArrSize - i - 1) % 100;
    }
  }

protected:
  constexpr static size_t _multiplier = 10;
  constexpr static size_t _worstArrSize = 100 * _multiplier;
  int _worstArr[_worstArrSize] = {};
  constexpr static size_t _avgArrSize = 100 * _multiplier;
  int _avgArr[_avgArrSize] = {};
  constexpr static size_t _bestArrSize = 100 * _multiplier;
  int _bestArr[_bestArrSize] = {};
  constexpr static size_t _countingArrSize = 100 * _multiplier;
  int _countingArr[_countingArrSize] = {};

  template<size_t N>
  void processSortAlgorithm(void (*fptr)(int *, int), int (&arr)[N])
  {
    if (arr == _bestArr)
      ASSERT_TRUE(std::is_sorted(arr, arr + N));
    else
      ASSERT_FALSE(std::is_sorted(arr, arr + N));
    fptr(arr, N);
    EXPECT_TRUE(std::is_sorted(arr, arr + N));
  }
};

TEST_F(SortAlgorithmsTest, BubbleSortWorst)
{
  processSortAlgorithm(bubbleSort, _worstArr);
}

TEST_F(SortAlgorithmsTest, BubbleSortAverage)
{
  processSortAlgorithm(bubbleSort, _avgArr);
}

TEST_F(SortAlgorithmsTest, BubbleSortBest)
{
  processSortAlgorithm(bubbleSort, _bestArr);
}

TEST_F(SortAlgorithmsTest, InsertionSortWorst)
{
  processSortAlgorithm(insertionSort, _worstArr);
}

TEST_F(SortAlgorithmsTest, InsertionSortAverage)
{
  processSortAlgorithm(insertionSort, _avgArr);
}

TEST_F(SortAlgorithmsTest, InsertionSortBest)
{
  processSortAlgorithm(insertionSort, _bestArr);
}

TEST_F(SortAlgorithmsTest, ShellSortWorst)
{
  processSortAlgorithm(shellSort, _worstArr);
}

TEST_F(SortAlgorithmsTest, ShellSortAverage)
{
  processSortAlgorithm(shellSort, _avgArr);
}

TEST_F(SortAlgorithmsTest, ShellSortBest)
{
  processSortAlgorithm(shellSort, _bestArr);
}

TEST_F(SortAlgorithmsTest, SelectionSortWorst)
{
  processSortAlgorithm(selectionSort, _worstArr);
}

TEST_F(SortAlgorithmsTest, SelectionSortAverage)
{
  processSortAlgorithm(selectionSort, _avgArr);
}

TEST_F(SortAlgorithmsTest, SelectionSortBest)
{
  processSortAlgorithm(selectionSort, _bestArr);
}

TEST_F(SortAlgorithmsTest, QuickSortWorst)
{
  processSortAlgorithm(quickSort, _worstArr);
}

TEST_F(SortAlgorithmsTest, QuickSortAverage)
{
  processSortAlgorithm(quickSort, _avgArr);
}

TEST_F(SortAlgorithmsTest, QuickSortBest)
{
  processSortAlgorithm(quickSort, _bestArr);
}

TEST_F(SortAlgorithmsTest, MergeSortWorst)
{
  processSortAlgorithm(mergeSort, _worstArr);
}

TEST_F(SortAlgorithmsTest, MergeSortAverage)
{
  processSortAlgorithm(mergeSort, _avgArr);
}

TEST_F(SortAlgorithmsTest, MergeSortBest)
{
  processSortAlgorithm(mergeSort, _bestArr);
}

TEST_F(SortAlgorithmsTest, HeapSortWorst)
{
  processSortAlgorithm(heapSort, _worstArr);
}

TEST_F(SortAlgorithmsTest, HeapSortAverage)
{
  processSortAlgorithm(heapSort, _avgArr);
}

TEST_F(SortAlgorithmsTest, HeapSortBest)
{
  processSortAlgorithm(heapSort, _bestArr);
}

TEST_F(SortAlgorithmsTest, CountingSort)
{
  processSortAlgorithm(countingSort, _countingArr);
}

TEST_F(SortAlgorithmsTest, RadixSort)
{
  processSortAlgorithm(radixSort, _countingArr);
}
