cmake_minimum_required(VERSION 3.10)

project(algorithms)

add_library(sort_algo
  sort/SortAlgorithms.h
  sort/BubbleSort.cpp
  sort/InsertSort.cpp
  sort/ShellSort.cpp
  sort/SelectionSort.cpp
  sort/QuickSort.cpp
  sort/MergeSort.cpp
  sort/HeapSort.cpp
  sort/CountingSort.cpp
  sort/RadixSort.cpp
)

set(ENABLE_NQ_SIGNALS OFF)
add_subdirectory(ratel)

add_executable(${PROJECT_NAME}
  main.cpp
  Tests/SortAlgorithmsTest.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC . sort)
target_link_libraries(${PROJECT_NAME} sort_algo ratel-lib gmock)

