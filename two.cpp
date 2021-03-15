#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "two.h"

int main() {
    srand(SRAND_SEED);
    int *arr = getRandomArray(30);
    return 0;
}

int getRandomNumber(int min, int max) {
    int range = max - min + ONE;
    return rand() % range + min;
}

int *getRandomArray(int unsigned size) {
    // Initiallize array
    int *array = new (std::nothrow) int[size];

    // Check did OS give us memory
    if (array == nullptr) {
        exit(EXIT_FAILURE);
    }

    for (int i=0; i < size; i++) {
        int r = getRandomNumber(MIN_RAND, MAX_RAND);
        array[i] = r;
        std::cout << array[i] << std::endl;
    }

    return array;
}

int getMinElement(int *array, unsigned int size) {
    int min = array[0];
    for (int i=0; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

int getMaxElement(int *array, unsigned int size) {
    int max = array[0];
    for (int i=0; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

/** Returning -1 if noone of array elements is repeating more than 1 time */
int getMostProbableElement(int *array, unsigned int size) {
    int maxCount = 1;
    /* default res */
    int result = -1;

    
      for (int i=0; i < size; i++) {
        int count = 0;
        for (int j=i; j < size; j++) {
            if (array[i] == array[j]) {
                count++;
            }
        }
        if (maxCount < count) {
            maxCount = count;
            result = i;
        }
    }

    return result;
}

void printArrayHistogram(int *array, unsigned int size) {
    using namespace std;
    for (int i=0; i < size; i++) {
        string str(array[i], '*');
        cout << "Array[" << i << "]" << " " << array[i] << " " << str << endl;
    }
}

/**
 * @param x value to search in the array
 * @return index of element, -1 if doesn't exists
 */
int linearSearch(int *array, int x, unsigned int size) {
    for (int i=0; i < size; i++) {
        if (array[i] == x) {
            return i;
        }
    }
    return -1;
}

/**
 * @param x value to search in the array
 * @return index of element, -1 if doesn't exists
 */
int binarySearch(int *array, int x, unsigned int size, bool isSorted=false) {
    using namespace std;

    int *tempArray;

    if (!isSorted) {
    tempArray = new int[size];
    copy(tempArray, array, size * sizeof(int));
    sort(tempArray, tempArray + sizeof(tempArray) / sizeof(tempArray[0]));
    }

    else { 
        tempArray = array;
    }

    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (tempArray[middle] == x) {
            return middle;
        }

        if (tempArray[middle] < x) {
            left = middle + 1;
        }

        else {
            right = middle + 1;
        }
    }

    // If element doesn't exists
    return -1;
}

int *insertSort(int *array, unsigned int size) {
    using namespace std;

    int *result = new int[size];
    copy(result, array, size * sizeof(int));

    for (int i=1; i < size; i++) {
        int key = result[i];
        int j = i - 1;

        while (j >= 0 && result[j] > key) {
            result[j+1] = result[j];
            j--;
        }

        result[j+1] = key;
    }

    return result;
}

int *selectionSort(int *array, unsigned int size) {
    using namespace std;

    int *result = new int[size];
    copy(result, array, size * sizeof(int));

    for (int i=0; i < size; i++) {
        int min = i;

        for (int j=i+1; j < size; j++) {

            if (result[j] < result[min]) {
                min = j;
            }

        }
        int temp = result[i];
        result[i] = result[min];
        result[min] = temp;
    }

    return result;
}
