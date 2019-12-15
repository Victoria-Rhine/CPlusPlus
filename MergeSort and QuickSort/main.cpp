#include "functions.h"
int main()
{
    int arraySize = 1000;

    while (arraySize <= 10000000)
    {
        std::cout << "For size: " << arraySize << "\n";
        /* initialize variables and arrays */
        clock_t start, finish;
        double time;
        int low = 0; int high = arraySize - 1;
        int *myArray = new int[arraySize + 1];
        int *myArray2 = new int[arraySize + 1];

        std::cout << "Part 1: Reading...\n";

        /* Create and time first array */
        start = clock();
        *myArray = createArray(myArray, arraySize);
        finish = clock();
        time = (double(finish) - double(start)) /CLOCKS_PER_SEC;
        std::cout << "Time to build 1st array: " << time * 1000 << " milliseconds.\n";

        /* Create and time second array */
        start = clock();
        *myArray2 = createArray(myArray2, arraySize);
        finish = clock();
        time = (double(finish) - double(start)) /CLOCKS_PER_SEC;
        std::cout << "Time to build 2nd array: " << time * 1000 << " milliseconds.\n";

        /* Total values */
        addValues(myArray, arraySize);

        /* sort array using Merge Sort and time procedure */
        std::cout << "\nPart 2: Calling Merge Sort\n";
        start = clock();
        auxMergeSort(myArray, low, high);
        finish = clock();
        time = (double(finish) - double(start)) /CLOCKS_PER_SEC;
        std::cout << "Time: " << time * 1000 << " milliseconds.\n";

        /* sort array using Quick Sort and time procedure */
        std::cout << "\nPart 3: Calling Quick Sort\n";
        start = clock();
        auxQuickSort(myArray2, low, high);
        finish = clock();
        time = (double(finish) - double(start)) /CLOCKS_PER_SEC;
        std::cout << "Time: " << time * 1000 << " milliseconds.\n";

        /* checks if arrays are sorted */
        std::cout << "\nPart 4: Checking if arrays are sorted\n";
        start = clock();
        if (flgIsSorted(myArray) == true)
        {
            std::cout << "\nArray is sorted with Merge Sort.\n";
            for (int i = 0; i < 15; i++)
            {
                std::cout << myArray2[i] << " ";
            }
        }
        else
            std::cout << "\nArray is not sorted.\n";

        if (flgIsSorted(myArray2) == true)
        {
            std::cout << "\nArray is sorted with Quick Sort.\n";
            for (int i = 0; i < 15; i++)
            {
                std::cout << myArray2[i] << " ";
            }
        }
        else
            std::cout << "\nArray is not sorted.\n";
        finish = clock();
        time = (double(finish) - double(start)) /CLOCKS_PER_SEC;
        std::cout << "\nTime: " << time * 1000
                  << " milliseconds.\n"
                  << "================================================\n" << std::endl;
        arraySize = arraySize * 10;
    }
}
