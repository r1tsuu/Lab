#ifndef TWO_H
#define TWO_H

#define ONE 1
#define SRAND_SEED 25
#define MIN_RAND 0
#define MAX_RAND 50

int getRandomNumber(int min, int max);

int *getRandomArray(int unsigned size);

int getMinElement(int *array, int unsigned size);

int getMaxElemenent(int *array, int unsigned size);

int getMostProbablyElement(int *array, int unsigned size);

void printArrayHistogram(int *array, unsigned int size);

int linearSearch(int *array, int x, unsigned int size);

int binarySearch(int *array, int x, unsigned int size, bool isSorted);

int *insertSort(int *array, unsigned int size);

int *selectionSort(int *array, unsigned int size);

#endif