#include<iostream>

int Palindrome(int a) {
    int n = a;
    int number = a;
    int remainder, sum = 0;

    while (number > 0) {
        remainder = number % 10;
        sum = (sum * 10) + remainder;
        number = number / 10;
    }

    if (n == sum) {
        std::cout << "The number is palindrome.";
    } else {
        std::cout << "Number is not a palindrome.";
    }

    return sum; // It's better to return the calculated palindrome (sum) instead of the original number
}

int main() {
    int number;
    std::cout << "Enter the number: ";
    std::cin >> number;

    if (number > 0) {
        Palindrome(number);
    } else {
        std::cout << "You entered a negative number!";
    }

    return 0;
}

