#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include "Graphics.hpp"

class Algorithm
{
private:
    static Algorithm *sInstance;
    Graphics *graphics;

public:
    static Algorithm *Instance();
    static void Release();

    void SelectionSort(int *arr, int n);
    void BubbleSort(int *arr, int n);

    void InsertionSort(int *arr, int n);
    void HeapSort(int *arr, int n);

    int Partition(int *arr, int left, int right);
    void QuickSort(int *arr, int left, int right);

    void Merge2SortedArrays(int *arr, int left, int right);
    void MergeSort(int *arr, int left, int right);

    void CountingSort(int *arr, int n);

private:
    Algorithm();
    ~Algorithm();
};

#endif
