/**
 * @author Victoria Rhine
 * "AlgorithmsLab2"
 */

/**
 * @cite Radix Sort code modified from www.geeksforgeeks.org/radix-sort
 * @cite Bucket Sort code modified from www.programmingalgorithms.com/algorithm/bucket-sort
 */

#ifndef LAB2FUNCTIONS_H
#define LAB2FUNCTIONS_H
#include <algorithm>
#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>

/**
 * @brief createArray reads in a file and makes an array
 * @param array
 * @param size
 * @return finished array
 */
int createArray(int* array, int size);

/**
 * @brief radixsort sorts given array
 * @param array
 * @param size
 */
void radixSort(int* array, int size);

/**
 * @brief getMax gets max of array/radixsort helper
 * @param array
 * @param size
 * @return max element
 */
int getMax(int* array, int size);

/**
 * @brief countSort does internal sorting for radixSort
 * @param array
 * @param size
 * @param exp
 */
void countSort(int* array, int size, int exp);

/**
 * @brief bucketSort sorts given array
 * @param array
 * @param size
 */
void bucketSort(int* data, int count);

/**
 * @brief auxQuickSort sorts given array
 * @param array
 * @param low
 * @param high
 */
void auxQuickSort(int* array, int low, int high);

/**
 * @brief partition is helper function for auxQuickSort
 * @param array
 * @param low
 * @param high
 * @return
 */
int partition(int* array, int low, int high);

/**
 * @brief printArray prints elements of the given array
 * @param array
 * @param label
 * @param size
 * @param sizeToPrint
 */
void printArray(int* array, std::string label, int size, int sizeToPrint);

/**
 * @brief flgIsSorted checks if given array is sorted
 * @param array
 * @return
 */
bool flgIsSorted(int* array, int size);

/**
 * @brief maxTen creates an array of highest 10 values of given array
 * @param array
 * @return
 */
int maxTen(int* array, int *tenArray, int size);

/**
 * @brief maxTenHelper is helper to maxTen function
 * @param array
 * @param tenArray
 * @param i
 * @param size
 * @return
 */
int maxTenHelper(int* array, int* tenArray, int i, int size);

/**
 * @brief max gets max elements from given array and replaces that value with 0
 * @param array
 * @param size
 * @return
 */
int max(int* array, int size);

#endif // LAB2FUNCTIONS_H
