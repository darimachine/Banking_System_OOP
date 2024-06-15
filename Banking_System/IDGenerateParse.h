#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>

constexpr int MAX_NUM = 10000;

bool isGenerated[MAX_NUM] = { false }; // Array to keep track of generated numbers

int generateUniqueNumber() {
    static int generatedCount = 0;

    if (generatedCount >= MAX_NUM) {
        throw std::runtime_error("All unique numbers between 1 and 10000 have been generated.");
    }

    int number = (std::rand() % MAX_NUM) + 1;
    while (isGenerated[number - 1]) {
        number = (std::rand() % MAX_NUM) + 1;
    }

    isGenerated[number - 1] = true;
    generatedCount++;

    return number;
}
char* intToStr(int num, char* buffer) {
    int i = 0;
    bool isNegative = false;

    // Handle 0 explicitly, otherwise empty string is printed for 0
    if (num == 0) {
        buffer[i++] = '0';
        buffer[i] = '\0';
        return buffer;
    }

    // Handle negative numbers
    if (num < 0) {
        isNegative = true;
        num = -num;
    }

    // Process individual digits
    while (num != 0) {
        int rem = num % 10;
        buffer[i++] = rem + '0';
        num = num / 10;
    }

    // If number is negative, append '-'
    if (isNegative) {
        buffer[i++] = '-';
    }

    buffer[i] = '\0'; // Append null character

    // Reverse the string
    int start = 0;
    int end = i - 1;
    while (start < end) {
        char temp = buffer[start];
        buffer[start] = buffer[end];
        buffer[end] = temp;
        start++;
        end--;
    }

    return buffer;
}