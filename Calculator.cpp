#include "Calculator.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdexcept>

double Calculator::add(double a, double b) {
    double result = a + b;
    recordHistory(a, '+', b, result);
    return result;
}

double Calculator::subtract(double a, double b) {
    double result = a - b;
    recordHistory(a, '-', b, result);
    return result;
}

double Calculator::multiply(double a, double b) {
    double result = a * b;
    recordHistory(a, '*', b, result);
    return result;
}

double Calculator::divide(double a, double b) {
    if (b == 0) {
        throw std::runtime_error("Error: Division by zero.");
    }
    double result = a / b;
    recordHistory(a, '/', b, result);
    return result;
}

void Calculator::recordHistory(double a, char op, double b, double result) {
    std::ostringstream oss;
    oss << a << " " << op << " " << b << " = " << result;
    history.push_back(oss.str());
}

void Calculator::printHistory() const {
    if (history.empty()) {
        std::cout << "No calculations yet.\n";
        return;
    }
    std::cout << "Calculation History:\n";
    for (const auto& entry : history) {
        std::cout << entry << std::endl;
    }
}

void Calculator::saveHistoryToFile(const std::string& filename) const {
    std::ofstream outfile(filename);
    if (outfile.is_open()) {
        for (const auto& entry : history) {
            outfile << entry << std::endl;
        }
        outfile.close();
        std::cout << "History saved to " << filename << std::endl;
    } else {
        std::cout << "Error: Could not open file " << filename << " for writing." << std::endl;
    }
}

void Calculator::loadHistoryFromFile(const std::string& filename) {
    std::ifstream infile(filename);
    if (infile.is_open()) {
        history.clear();
        std::string line;
        while (std::getline(infile, line)) {
            history.push_back(line);
        }
        infile.close();
        std::cout << "History loaded from " << filename << std::endl;
    } else {
        std::cout << "Error: Could not open file " << filename << " for reading." << std::endl;
    }
}
