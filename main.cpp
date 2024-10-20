#include "Calculator.h"
#include <iostream>
#include <exception>

int main() {
    Calculator calc;
    char choice;
    do {
        std::cout << "\n=== Simple Calculator ===\n";
        std::cout << "Select an operation:\n";
        std::cout << "1. Addition (+)\n";
        std::cout << "2. Subtraction (-)\n";
        std::cout << "3. Multiplication (*)\n";
        std::cout << "4. Division (/)\n";
        std::cout << "5. View History\n";
        std::cout << "6. Save History to File\n";
        std::cout << "7. Load History from File\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        double num1, num2, result;
        try {
            switch (choice) {
                case '1':
                    std::cout << "Enter two numbers: ";
                    std::cin >> num1 >> num2;
                    result = calc.add(num1, num2);
                    std::cout << "Result: " << result << std::endl;
                    break;
                case '2':
                    std::cout << "Enter two numbers: ";
                    std::cin >> num1 >> num2;
                    result = calc.subtract(num1, num2);
                    std::cout << "Result: " << result << std::endl;
                    break;
                case '3':
                    std::cout << "Enter two numbers: ";
                    std::cin >> num1 >> num2;
                    result = calc.multiply(num1, num2);
                    std::cout << "Result: " << result << std::endl;
                    break;
                case '4':
                    std::cout << "Enter two numbers: ";
                    std::cin >> num1 >> num2;
                    result = calc.divide(num1, num2);
                    std::cout << "Result: " << result << std::endl;
                    break;
                case '5':
                    calc.printHistory();
                    break;
                case '6': {
                    std::string filename;
                    std::cout << "Enter filename to save history: ";
                    std::cin >> filename;
                    calc.saveHistoryToFile(filename);
                    break;
                }
                case '7': {
                    std::string filename;
                    std::cout << "Enter filename to load history from: ";
                    std::cin >> filename;
                    calc.loadHistoryFromFile(filename);
                    break;
                }
                case '0':
                    std::cout << "Exiting...\n";
                    break;
                default:
                    std::cout << "Invalid choice.\n";
            }
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    } while (choice != '0');

    return 0;
}
