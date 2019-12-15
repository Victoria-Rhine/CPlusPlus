#include "functions.h"

int createArray(int* array, int size)
{
    std::ifstream inFile;
    inFile.open("lab1_data.txt");
    int value;
    for (int i = 0; i < size; i++)
    {
        inFile >> value;
        array[i] = value;
    }
    array[size] = -1;
    inFile.close();
    return *array;
}

void addValues(int *array, int size)
{
    signed long long total = 0;
    for (signed int i = 0; i < size; i++)
    {
        total += array[i];
    }
    std::cout << "Sum: "<< total << std::endl;
}

void auxMergeSort(int* array, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        auxMergeSort(array, low, mid);
        auxMergeSort(array, mid + 1, high);
        merge(array, low, mid, high);
    }
}

void merge(int* array, int low, int m, int high)
{
    int n1 = m - low + 1, i ,j , k;
    int n2 = high - m;
    int *L = new int[n1];
    int *R = new int[n2];
    for(i = 0; i < n1; i++)
    {
        L[i] = array[low+i];
    }
    for(j=0; j< n2; j++)
    {
        R[j] = array[m + j + 1];
    }
    i=0; j=0;
    for(k=low; i < n1 && j < n2; k++)
    {
        if (L[i] < R[j])
        {
            array[k] = L[i++];
        }
        else {
            array[k] = R[j++];
        }
    }
    while (i < n1)
    {
        array[k++] = L[i++];
    }
    while (j < n2)
    {
        array[k++] = R[j++];
    }
}

void auxQuickSort(int* array, int low, int high)
{
    int pivot = partition(array, low, high);
    if (low < pivot - 1)
        auxQuickSort(array, low, pivot - 1);
    if (pivot < high)
        auxQuickSort(array, pivot, high);
}

int partition(int* array, int low, int high)
{
    int i = low, j = high;
    int tmp;
    int pivot = array[(low + high) / 2];
    while (i <= j)
    {
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i <= j)
        {
            tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
            i++;
            j--;
        }
    };
    return i;
}

int getSize(int *array)
{
    int total = 0;
    int i = 0;
    while (array[i] >= 0)
    {
        total++;
        i++;
    }
    return total;
}

bool flgIsSortedRecursion(int* array, int size)
{
    if (size == 1 || size == 0)
    {
        return true;
    }
    if (array[size - 1] < array[size - 2])
        return false;

    return flgIsSortedRecursion(array, size - 1);
}

bool flgIsSortedIterative(int* array, int size)
{
    if (size == 1 || size == 0)
        return 1;
    for (int i = 0; i < size - 1; i++)
    {
        if (array[i + 1] < array[i])
            return 0;
    }
    return 1;
}

bool flgIsSorted(int* array)
{
    int size = getSize(array);
    if (size <= 5000)
        return flgIsSortedRecursion(array, size);
    else
        return flgIsSortedIterative(array, size);
}
