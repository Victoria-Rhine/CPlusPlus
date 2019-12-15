#include "lab2functions.h"

int main()
{
    // sets initial size
    int size = 1000;
    // initializes clock variables
    clock_t start, finish;

    // loops through arrays of increasing sizes until it hits 10000000
    while (size <= 10000000)
    {
        std::cout << "**************************************************\nFOR SIZE: "
                  << size << "\n\n-Radix Sort-";
        // Start of Radix Sort
        // initializes array on the heap
        int *myArray = new int[size];
        // makes the first unsorted array
        createArray(myArray, size);
        // prints out first and last ten of array before it's sorted
        printArray(myArray, "Unsorted", size, 10);

        // runs and times radix sort
        start = clock();
        radixSort(myArray, size);
        finish = clock();
        double radixTime = (double(finish) - double(start)) /CLOCKS_PER_SEC;

        // prints out first and last ten of array after it's sorted
        printArray(myArray, "Sorted", size, 10);

        // checks if array is sorted
        std::cout << "\nConfirm sorted...";
        if (flgIsSorted(myArray, size) == true)
            std::cout << "Yes, array is sorted." << "\n";
        else
        {
            std::cout << "No, array is not sorted." << "\n";
        }

        // Start of Bucket Sort
        std::cout << "\n\n-Bucket Sort-";

        // makes the second unsorted array
        createArray(myArray, size);
        // prints out first and last ten of array before it's sorted
        printArray(myArray, "Unsorted", size, 10);

        // runs and times bucket sort
        start = clock();
        bucketSort(myArray, size);
        finish = clock();
        double bucketTime = (double(finish) - double(start)) /CLOCKS_PER_SEC;

        // prints out first and last ten of array after it's sorted
        printArray(myArray, "Sorted", size, 10);

        // checks if array is sorted
        std::cout << "\nConfirm sorted...";
        if (flgIsSorted(myArray, size) == true)
            std::cout << "Yes, array is sorted." << "\n";
        else {
            std::cout << "No, array is not sorted." << "\n";
        }

        // Start of Quick Sort
        std::cout << "\n\n-Quick Sort-";

        int low = 0; int high = size - 1;
        // makes the third unsorted array
        createArray(myArray, size);
        // prints out first and last ten of array before it's sorted
        printArray(myArray, "Unsorted", size, 10);

        // runs and times quick sort
        start = clock();
        auxQuickSort(myArray, low, high);
        finish = clock();
        double quickTime = (double(finish) - double(start)) /CLOCKS_PER_SEC;

        // prints out first and last ten of array after it's sorted
        printArray(myArray, "Sorted", size, 10);

        // checks if array is sorted
        std::cout << "\nConfirm sorted...";
        if (flgIsSorted(myArray, size) == true)
            std::cout << "Yes, array is sorted." << "\n";
        else {
            std::cout << "No, array is not sorted." << "\n";
        }

        // prints timing for each sort in milliseconds
        std::cout << "\n*Parts 1 - 5 Timing*\n"
                  << "Radix Sort: " << radixTime * 1000 << " milliseconds\n"
                  << "Bucket Sort: " << bucketTime * 1000 << " milliseconds\n"
                  << "Quick Sort: " << quickTime * 1000 << " milliseconds\n" << std::endl;

        // initializes the fourth unsorted array
        createArray(myArray, size);
        // initializes array to hold max values
        int *tenArray = new int[10];

        // runs and times maxTen function
        start = clock();
        maxTen(myArray, tenArray, size);
        finish = clock();
        double maxTenTime = (double(finish) - double(start)) /CLOCKS_PER_SEC;

        // prints out largest 10 values before Radix Sort
        std::cout << "Max 10 before Radix Sort: ";
        for (int i = 0; i < 10; i++)
            std::cout << tenArray[i] << " ";

        // initializes the fifth unsorted array
        createArray(myArray, size);
        // runs Radix Sort
        radixSort(myArray, size);

        // runs and times maxTen function
        start = clock();
        maxTen(myArray, tenArray, size);
        finish = clock();
        double maxTenTime2 = (double(finish) - double(start)) /CLOCKS_PER_SEC;

        // prints out largest 10 values after Radix Sort
        std::cout << "\nMax 10 after Radix Sort: ";
        for (int i = 0; i < 10; i++)
            std::cout << tenArray[i] << " ";

        // prints out timing of the max ten function in microseconds
        std::cout << "\n\n*Parts 6 - 8 Timing*\n"
                  << "Max Ten Before Sort:  " << maxTenTime * 1000000 << " microseconds\n"
                  << "Max Ten After Sort:  " << maxTenTime2 * 1000000 << " microseconds\n" << std::endl;

        // increases array size for while loop
        size *= 10;
    }
}
