#include "lab2functions.h"

int createArray(int* array, int size)
{
    // reads in lab3_data.txt file
    std::ifstream inFile;
    inFile.open("lab3_data.txt");

    // checks if file is read correctly
    if (inFile.fail())
    {
        std::cout<< "\nError reading file" <<std::endl;
        return 0;
    }
    else
    {
        std::cout<< "\nFile read correctly" << std::endl;
    }

    // inputs values from file into array
    int value;
    for (int i = 0; i < size; i++)
    {
        inFile >> value;
        array[i] = value;
    }

    // closes file then returns finished array
    inFile.close();
    return *array;
}


void radixSort(int* array, int size)
{
    // finds the max number to know the number of digits
    int m = getMax(array, size);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(array, size, exp);
}

int getMax(int* array, int size)
{
    // gets the max value in the array with iteration
    int max = array[0];
    for (int i = 1; i < size; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

void countSort(int* array, int size, int exp)
{
    int *output = new int[size]; // output array
    int i, count[10] = {0};

    // stores count of occurences in count[]
    for (i = 0; i < size; i++)
        count[ (array[i] / exp) %10 ]++;

    // changes count[i] so that count[i] now contains actual
    // position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // builds the output array
    for (i = size - 1; i >= 0; i--)
    {
        output[count[ (array[i] / exp) % 10 ] - 1] = array[i];
        count[ (array[i]/exp) % 10 ]--;
    }

    // copies the output array to array, so that array now
    // contains sorted numbers according to current digit
    for (i = 0; i < size; i++)
        array[i] = output[i];
}

// sorts given array using bucket sort
void bucketSort(int* data, int count)
{
    int minValue = data[0];
    int maxValue = data[0];

    for (int i = 1; i < count; i++)
    {
        if (data[i] > maxValue)
            maxValue = data[i];
        if (data[i] < minValue)
            minValue = data[i];
    }

    int bucketLength = maxValue - minValue + 1;
    // create empty buckets
    std::vector<int>* bucket = new std::vector<int>[bucketLength];

    for (int i = 0; i < bucketLength; i++)
    {
        bucket[i] = std::vector<int>();
    }

    // put array elements in different buckets
    for (int i = 0; i < count; i++)
    {
        bucket[data[i] - minValue].push_back(data[i]);
    }

    int k = 0;
    for (int i = 0; i < bucketLength; i++)
    {
        int bucketSize = bucket[i].size();

        // concatenate all buckets
        if (bucketSize > 0)
        {
            for (int j = 0; j < bucketSize; j++)
            {
                data[k] = bucket[i][j];
                k++;
            }
        }
    }
}

// sorts given array using quick sort
void auxQuickSort(int* array, int low, int high)
{
    // gets pivot using helper function
    int pivot = partition(array, low, high);
    // sorts first half of array using recursion
    if (low < pivot - 1)
        auxQuickSort(array, low, pivot - 1);
    // sorts second half of array using recursion
    if (pivot < high)
        auxQuickSort(array, pivot, high);
}

int partition(int* array, int low, int high)
{
    int i = low, j = high;
    int tmp;
    // sets pivot position
    int pivot = array[(low + high) / 2];
    // checking values against pivot until they "cross"
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

// prints the first and last 10 elements of an array
// this is used to show the difference between an unsorted and sorted array
void printArray(int* array, std::string label,  int size, int sizeToPrint)
{
    std::cout << "\n" << label << " first 10: ";
    for (int i = 0; i < sizeToPrint; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << "\n" << label << " last 10: ";
    for (int i = (size - sizeToPrint); i < size; i++)
    {
        std::cout << array[i] << " ";
    }
}

// checks if array is sorted with iteration
bool flgIsSorted(int* array, int size)
{
    // if there is nothing or one value in array, it is sorted
    if (size == 1 || size == 0)
        return 1;

    // walks through array checking if any value
    // is bigger than the value that precedes it
    for (int i = 0; i < size - 1; i++)
    {
        if (array[i + 1] < array[i])
            return 0;
    }
    // if it passed last for test then it must be sorted
    return 1;
}

// gets max ten of given array using helper function
// passing size for convenience on helper functions
int maxTen(int* array, int* tenArray, int size)
{
    return maxTenHelper(array, tenArray, 0, size);
}

// make an array of highest ten values
int maxTenHelper(int* array, int* tenArray, int i, int size)
{
    // when 10 numbers have been added we're done
    if ( i == 10)
        return *tenArray;

    // gets the highest value in array
    int m = max(array, size);
    // adds highest value to array
    tenArray[i] = m;
    // repeats previous steps using recursion
    return maxTenHelper(array, tenArray, i + 1, size);
}

// works like getMax but replaces highest element
// with 0 so it's not called again
int max(int* array,  int size)
{
    int max = array[0];
    int temp = 0;

    for (int i = 0; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
            temp = i;
        }
    }
    array[temp] = 0;

    return max;
}
