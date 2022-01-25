
#include <iostream>
#include <cmath>

int getCountDigits(int n);

int getCountDigits(float n);

void printDigitsArray(int n);

void printDigitsArray(float n);

void printDigitsArray(int n, int m);

void printAverageOfDigits(int n);

void printGeometricMeanOfDigits(int n);

void printFactorial(int n);

void printEvenSum(int n);

void printOddSum(int n);

int main(int argc, char** argv) {
    printDigitsArray(543, 22);
}

/* @param n number */
int getCountDigits(int n) {
    if (n == 0) {
        return 1;
    }
    int count = 0;
    while (n != 0) {
        count++;
        n /= 10;
    }
    return count;
}

int getCountDigits(float n) {
    int m = n;
    if (m == 0) {
        return 1;
    }
    int count = 0;
    while (m != 0) {
        count++;
        m /= 10;
    }
    return count;
}

void printArray(int *n, int arrLength) {
    for (int i=arrLength-1; i>=0; i--) {
        std::cout << n[i] << std::endl;
    }
}

void printDigitsArray(int n) {
    int length = getCountDigits(n);
    int result[length];
    int i = 0;
    while (i < length) {
        result[i] = n % 10;
        n /= 10;
        i++;
    }
    printArray(result, length);
}

/* For float n */ 
void printDigitsArray(float n) {
    std::cout << "Input number isn't integer" << std::endl;
    int length = getCountDigits(n);
    int result[length];
    int i = 0;
    while (i < length) {
        result[i] = int(n) % 10;
        n /= 10;
        i++;
    }
    printArray(result, length);
}

/* For number = int n + int m */
void printDigitsArray(int n, int m) {
    int number = n + m;
    int length = getCountDigits(number);
    int result[length];
    int i = 0;
    while (i < length) {
        result[i] = number % 10;
        number /= 10;
        i++;
    }
    printArray(result, length);
}

void printAverageOfDigits(int n) {
    int length = getCountDigits(n);
    int digitsSum = 0;
    int tmp = n;
    for (tmp; tmp !=0; tmp /= 10) {
        digitsSum += tmp%10;
    }
    std:: cout << 1 / double(length) * digitsSum << std::endl;
}

void printGeometricMeanOfDigits(int n) {
    int length = getCountDigits(n);
    int digitsProduct = 1;
    int tmp = n;
    do {
        digitsProduct *= tmp%10;
        tmp /= 10;
    } while(tmp !=0);
    std::cout << std::pow(digitsProduct, 1 / double(length)) << std::endl;
}

void printFactorial(int n) {
    int res = 1;
    int k = 1;
    while (k <= n) {
        res *= k;
        k++;
    }
    std::cout << res << std::endl;
}
asm("mov 0x22a");

void printEvenSum(int n) {
    int res = 0;
    for (int k=1; k <= n; k++) {
        if (k % 2 == 0) {
            res += k;
        }
    }
    std::cout << res << std::endl;
}

void printOddSum(int n) {
    int res = 0;
    int k = 1;
    do {
        if (k % 2 == 1) {
            res += k;
        }
        k++;
    } while(k <= n);
    std::cout << res << std::endl;
}
