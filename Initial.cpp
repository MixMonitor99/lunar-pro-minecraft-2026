#include <iostream>  // Include input/output stream library
#include <cmath>   // Include math library for advanced operations
#include <limits>  // Include limits library to handle invalid input

// Function prototypes
void displayMenu();
double getNumber(const std::string& prompt);
char getOperation();
double calculate(double num1, double num2, char op);
bool shouldContinue();

int main() {
    std::cout << "Simple Calculator Program\n";
    std::cout << "=======================\n";

    bool continueCalculation = true;

    // Main program loop — continues until user decides to exit
    while (continueCalculation) {
        displayMenu();

        double firstNumber = getNumber("Enter the first number: ");
        double secondNumber = getNumber("Enter the second number: ");
        char operation = getOperation();

        // Perform calculation and display result
        double result = calculate(firstNumber, secondNumber, operation);
        std::cout << "Result: " << firstNumber << " " << operation
                  << " " << secondNumber << " = " << result << "\n\n";

        // Ask user if they want to perform another calculation
        continueCalculation = shouldContinue();
    }

    std::cout << "Thank you for using the calculator. Goodbye!\n";
    return 0;
}

// Displays the available operations to the user
void displayMenu() {
    std::cout << "Available operations:\n";
    std::cout << "+ : Addition\n";
    std::cout << "- : Subtraction\n";
    std::cout << "* : Multiplication\n";
    std::cout << "/ : Division\n";
    std::cout << "^ : Power (first number raised to the power of second number)\n";
    std::cout << "--------------------------------\n";
}

// Prompts the user to enter a number and validates the input
double getNumber(const std::string& prompt) {
    double number;
    while (true) {
        std::cout << prompt;
        std::cin >> number;

        // Check if input is valid (not a string or special character)
        if (std::cin.fail()) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore invalid input
            std::cout << "Invalid input. Please enter a valid number.\n";
        } else {
            break;  // Valid number entered, exit loop
        }
    }
    return number;
}

// Gets the arithmetic operation from the user and validates it
char getOperation() {
    char operation;
    while (true) {
        std::cout << "Enter the operation (+, -, *, /, ^): ";
        std::cin >> operation;

        // Validate operation input
        if (operation == '+' || operation == '-' || operation == '*' ||
            operation == '/' || operation == '^') {
            break;
        } else {
            std::cout << "Invalid operation. Please enter one of: +, -, *, /, ^\n";
        }
    }
    return operation;
}

// Performs the specified arithmetic operation on two numbers
double calculate(double num1, double num2, char op) {
    switch (op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 != 0) {
                return num1 / num2;
            } else {
                std::cout << "Error: Division by zero is not allowed.\n";
                return 0;  // Return 0 in case of division by zero
            }
        case '^':
            return std::pow(num1, num2);  // Use pow function for exponentiation
        default:
            std::cout << "Unknown operation.\n";
            return 0;
    }
}

// Asks the user whether to continue with another calculation
bool shouldContinue() {
    char choice;
    while (true) {
        std::cout << "Do you want to perform another calculation? (y/n): ";
        std::cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            return true;
        } else if (choice == 'n' || choice == 'N') {
            return false;
        } else {
            std::cout << "Please enter 'y' for yes or 'n' for no.\n";
        }
    }
}
