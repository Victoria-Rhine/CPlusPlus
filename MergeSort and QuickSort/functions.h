/**
 * Algorithms Lab 1
 * @author Victoria Rhine
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <ctime>
#include <fstream>

/** Reads file and builds array.
 * @param {int} array[] - Array to build.
 * @param {int} size - The size of the array.
 */
int createArray(int* array, int size);

/** Iterates through array and totals all values.
 * @param {int} array[] - The given array.
 * @param {int} size - The size of the array.
 */
void addValues(int *array, int size);

/** Sorts array using Merge Sort.
 * @param {int} array[] - The given array.
 * @param {int} low - Beginning of array, 0.
 * @param {int} high = End of array.
 * @cite https://bit.ly/2HAy19o
 */
void auxMergeSort(int* array, int low, int high);

/**
 * Helper function for auxMergeSort.
 * @param {int} array[] - The given array.
 * @param {int} low - Beginning of array.
 * @param {int} m - low + high / 2.
 * @param {int} high - End of array.
 * @cite https://bit.ly/2HAy19o
 */
void merge(int* array, int low, int m, int high);

/** Sorts array using Quick Sort.
 * @param {int} array[] - The given array.
 * @param {int} low - Beginning of array.
 * @param {int} high - End of array.
 * @cite http://www.algolist.net/Algorithms/Sorting/Quicksort
 */
void auxQuickSort(int* array, int low, int high);

/** Helper function for auxQuickSort.
 * @param {int} array[] - The given array.
 * @param {int} low - Beginning of array.
 * @param {int} high - End of array.
 * @cite http://www.algolist.net/Algorithms/Sorting/Quicksort
 */
int partition(int* array, int low, int high);

/** Gets size of given array.
 *  @param {int} array[] - The given array.
 */
int getSize(int *array);

/** Checks if given array is sorted.
 * @param {int} array[] - The given array.
 */
bool flgIsSorted(int* array);

/** Checks if array is sorted using recursion.
 * @param {int} array[] - The given array.
 * @param {int} size - The size of the array.
 */
bool flgIsSortedRecursion(int* array, int size);

/** Checks if array is sorted using iteration.
 * @param {int} array[] - The given array.
 * @param {int} size - The size of the array.
 */
bool flgIsSortedIterative(int* array, int size);

#endif // FUNCTIONS_H
