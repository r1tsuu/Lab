#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct minMax {
    int min;
    int max;
} minMax;

int firstQuestion() {
    cout << "Введіть 1 якщо за зростанням" << endl;
    cout << "Введіть 2 якщо за спаданням" << endl;

    int answer;
    while (true) {
        cin >> answer;
        if (answer == 1 || answer == 2) {
            return answer;
        }
        cout << "Введенне значення повинно бути 1 або 2, спробуйте ще раз" << endl;;
    }
}

int secondQuestion() {
    cout << "Введіть 1 якщо сортурувати весь масив" << endl;
    cout << "Введіть 2 якщо сортурувати масив від min до max" << endl;

    int answer;
    while (true) {
        cin >> answer;
        if (answer == 1 || answer == 2) {
            return answer;
        }
        cout << "Введенне значення повинно бути 1 або 2, спробуйте ще раз" << endl;;
    }
}

minMax getMinMax() {
    minMax answer;
    
    cout << "Input min index:" << endl;
    cin >> answer.min;
    cout << "Input max index" << endl;
    cin >> answer.max;

    return answer;
}

void arraySlice(int *array, minMax minmax) {
    for (int i=0; i < minmax.max; i++) {
        array[i] = array[minmax.min + i];
    }
}

int thirdQuestion() {
    cout << "Введіть 1 якщо insert sort" << endl;
    cout << "Введіть 2 якщо selection sort" << endl;
    cout << "Введіть 3 якщо bubble sort" << endl;

    int answer;
    while (true) {
        cin >> answer;
        if (answer == 1 || answer == 2 || answer == 3) {
            return answer;
        }
        cout << "Введенне значення повинно бути 1, 2 або 3, спробуйте ще раз" << endl;
    }
}

void reverseArray(int *array, int count) {
    int temp;
    for (int i = 0; i < count/2; ++i)
   {
      temp = array[i];
      array[i] = array[count-i-1];
      array[count-i-1] = temp;
   }
}

int getRandomNumber(int min, int max) {
    int range = max - min + 1;
    return rand() % range + min;
}

int *getRandomArray(int unsigned size) {
    int *array = new int[size];
    for (int i=0; i < size; i++) {
        int r = getRandomNumber(0, 50);
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
            result = array[i];
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

int linearSearch(int *array, int x, unsigned int size) {
    for (int i=0; i < size; i++) {
        if (array[i] == x) {
            return i;
        }
    }
    return -1;
}

int compare(const void * x1, const void * x2)
{
  return ( *(int*)x1 - *(int*)x2 );
}

void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
 
int binarySearch(int *array, int x, unsigned int size, bool isSorted=false) {
    if (!isSorted) {
        qsort(array, size, sizeof(int), compare);
    }

    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (array[middle] == x) {
            return middle;
        }

        if (array[middle] < x) {
            left = middle + 1;
        }

        else {
            right = middle + 1;
        }
    }

    return -1;
}

void insertSort(int *array, unsigned int size) {
    for (int i=1; i < size; i++) {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j+1] = array[j];
            j--;
        }

        array[j+1] = key;
    }
}

void selectionSort(int *array, unsigned int size) {
    for (int i=0; i < size; i++) {
        int min = i;

        for (int j=i+1; j < size; j++) {

            if (array[j] < array[min]) {
                min = j;
            }

        }
        swap(&array[i], &array[min]);
    }
}

void bubbleSort(int *array, int size) {
  for (int step = 0; step < size - 1; ++step) {

    for (int i = 0; i < size - step - 1; ++i) {
      if (array[i] > array[i + 1]) {
        swap(&array[i], &array[i+1]);
      }
    }

  }
}
  
int main() {
    int array[] = {23, 87, 14, 3, 48, 0, 58, 18, 80, 96};
    int size = 10;

    int firstAnswer = firstQuestion();

    int secondAnswer = secondQuestion();
    if (secondAnswer == 2) {
        minMax minmax = getMinMax();
        cout << minmax.max << endl;
        size = minmax.max - minmax.min;
        arraySlice(array, minmax);
    }

    int thirdAnswer = thirdQuestion();

    switch (thirdAnswer) {
        case 1:
            insertSort(array, size);
            break;
        case 2:
            selectionSort(array, size);
            break;
        case 3:
            bubbleSort(array, size);
    }

    if (firstAnswer == 2) {
        reverseArray(array, size);
    }

    printArrayHistogram(array, size);
}
