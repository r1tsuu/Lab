#ifndef TWO_H
#define TWO_H

#define ONE 1
#define SRAND_SEED 25
#define MIN_RAND 0
#define MAX_RAND 50

typedef struct minMax {
    int min;
    int max;
} minMax;

int firstQuestion();

int secondQuestion();

int thirdQuestion();

minMax getMinMax();

void reverseArray(int *array, int count);

void arraySlice (int *array, minMax minmax);

int getRandomNumber(int min, int max);

int *getRandomArray(int unsigned size);

int getMinElement(int *array, int unsigned size);

int getMaxElement(int *array, int unsigned size);

int getMostProbablyElement(int *array, int unsigned size);

void printArrayHistogram(int *array, unsigned int size);

int linearSearch(int *array, int x, unsigned int size);

int compare(const void * x1, const void * x2);

int binarySearch(int *array, int x, unsigned int size, bool isSorted);

void insertSort(int *array, unsigned int size);

void selectionSort(int *array, unsigned int size);

void bubbleSort(int *array, int size);

#endif