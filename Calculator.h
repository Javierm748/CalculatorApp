#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <vector>
#include <string>

class Calculator {
private:
    std::vector<std::string> history;
    void recordHistory(double a, char op, double b, double result);

public:
    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);

    void printHistory() const;
    void saveHistoryToFile(const std::string& filename) const;
    void loadHistoryFromFile(const std::string& filename);
};

#endif // CALCULATOR_H
