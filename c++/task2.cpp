#include <iostream>

int main() {
    double num1, num2, result;
    char operation;

    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter second number: ";
    std::cin >> num2;
    std::cout << "Choose an operation (+, -, *, /): ";
    std::cin >> operation;

    if (operation == '+') {
        result = num1 + num2;
    } else if (operation == '-') {
        result = num1 - num2;
    } else if (operation == '*') {
        result = num1 * num2;
    } else if (operation == '/') {
        result = num2 != 0 ? num1 / num2 : 0;
        if (num2 == 0) std::cout << "Error: Division by zero.\n";
    } else {
        std::cout << "Invalid operation.\n";
        return 1;
    }

    std::cout << "Result: " << result << "\n";
    return 0;
}

