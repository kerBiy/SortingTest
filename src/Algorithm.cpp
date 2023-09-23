#include "../include/headers/Algorithm.hpp"

Algorithm *Algorithm::sInstance = NULL;

Algorithm *Algorithm::Instance()
{
    if (sInstance == NULL)
        sInstance = new Algorithm();

    return sInstance;
}

void Algorithm::Release()
{
    delete sInstance;
    sInstance = NULL;
}

Algorithm::Algorithm()
{
    graphics = Graphics::Instance();
}

Algorithm::~Algorithm()
{
    graphics = NULL;
}

void Algorithm::SelectionSort(int *arr, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            if (arr[i] > arr[j])
                std::swap(arr[i], arr[j]);

            graphics->Draw(arr, i, j);
            SDL_Delay(1);
        }
    }
}

void Algorithm::InsertionSort(int *arr, int n)
{
    for (int i = 1; i < n; ++i)
    {
        int j = i - 1;
        int temp = arr[i];

        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;

            graphics->Draw(arr, i, j + 1);
            SDL_Delay(1);
        }
        arr[j + 1] = temp;
    }
}

void Algorithm::BubbleSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - 1 - i; ++j)
        {
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);

            graphics->Draw(arr, n - i, j);
            SDL_Delay(1);
        }
    }
}

int Algorithm::Partition(int *arr, int left, int right)
{
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; ++j)
    {
        if (arr[j] <= pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
            graphics->Draw(arr, i, j);
            SDL_Delay(1);
        }
    }
    std::swap(arr[i + 1], arr[right]);
    graphics->Draw(arr, i + 1, right);
    SDL_Delay(1);
    return i + 1;
}

void Algorithm::QuickSort(int *arr, int left, int right)
{
    if (left < right)
    {
        int partition = Partition(arr, left, right);

        QuickSort(arr, left, partition - 1);
        QuickSort(arr, partition + 1, right);
    }
}

void Algorithm::HeapSort(int *arr, int n)
{
    for (int i = 1; i < n; ++i)
    {
        int childIndex = i;
        int parentIndex = (childIndex - 1) / 2;

        while (childIndex > 0)
        {
            if (arr[childIndex] > arr[parentIndex])
                std::swap(arr[parentIndex], arr[childIndex]);
            else
                break;

            graphics->Draw(arr, parentIndex, childIndex);
            SDL_Delay(1);

            childIndex = parentIndex;
            parentIndex = (childIndex - 1) / 2;
        }
    }

    for (int heapLast = n - 1; heapLast >= 0; --heapLast)
    {
        std::swap(arr[0], arr[heapLast]);

        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;

        while (leftChildIndex < heapLast)
        {
            int maxIndex = parentIndex;

            if (arr[leftChildIndex] > arr[maxIndex])
                maxIndex = leftChildIndex;

            if (rightChildIndex < heapLast && arr[rightChildIndex] > arr[maxIndex])
                maxIndex = rightChildIndex;
            if (maxIndex == parentIndex)
                break;

            std::swap(arr[parentIndex], arr[maxIndex]);

            graphics->Draw(arr, maxIndex, parentIndex, heapLast);
            SDL_Delay(1);

            parentIndex = maxIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }
    }
}

void Algorithm::Merge2SortedArrays(int *arr, int left, int right)
{
    int size_output = (right - left) + 1;
    int *output = new int[size_output];

    int mid = (left + right) / 2;
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            output[k] = arr[i];
            graphics->Draw(arr, i, j);
            i++;
            k++;
        }
        else
        {
            output[k] = arr[j];
            graphics->Draw(arr, i, j);
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        output[k] = arr[i];
        graphics->Draw(arr, -1, i);
        i++;
        k++;
    }
    while (j <= right)
    {
        output[k] = arr[j];
        graphics->Draw(arr, -1, j);
        j++;
        k++;
    }
    int x = 0;
    for (int l = left; l <= right; l++)
    {
        arr[l] = output[x];
        graphics->Draw(arr, l);
        SDL_Delay(1);
        x++;
    }
    delete[] output;
}

void Algorithm::MergeSort(int *arr, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int mid = (left + right) / 2;

    MergeSort(arr, left, mid);
    MergeSort(arr, mid + 1, right);

    Merge2SortedArrays(arr, left, right);
}

void Algorithm::CountingSort(int *arr, int n)
{
    int fr[1000]{};
    int max = 0;

    for (int i = 0; i < n; ++i)
    {
        fr[arr[i]]++;
        if (arr[i] > max)
            max = arr[i];
        SDL_Delay(1);
    }

    int exp = -1;
    for (int i = 0; i <= max; ++i)
    {
        for (int j = 1; j <= fr[i]; ++j)
        {
            arr[++exp] = i;
            SDL_Delay(1);
        }
    }
}