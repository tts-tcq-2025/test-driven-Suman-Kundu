#include <iostream>
#include <cassert>
#include <string>
#include "StringCalculator.h"

// Helper function to test operations
void testOperation(StringCalculator& calculator, const std::string& testName,
                   const std::string& input, int expected) {
    std::cout << "Testing " << testName << "..." << std::endl;
    int result = calculator.Add(input);
    std::cout << "Result: " << result << std::endl;
    assert(result == expected);
    std::cout << "✓ " << testName << " test passed!" << std::endl;
}

// Helper function to test exception cases
void testException(StringCalculator& calculator, const std::string& testName,
                   const std::string& input, const std::string& expectedMessage) {
    std::cout << "Testing " << testName << "..." << std::endl;
    try {
        calculator.Add(input);
        assert(false);  // Should not reach here
    } catch (const std::invalid_argument& e) {
        std::cout << "Result: " << e.what() << std::endl;
        assert(std::string(e.what()) == expectedMessage);
    }
    std::cout << "✓ " << testName << " test passed!" << std::endl;
}

int main() {
    StringCalculator calculator;

    /* Basic Functionality Testing */
    testOperation(calculator, "empty string", "", 0);
    testOperation(calculator, "Single number", "1", 1);
    testOperation(calculator, "two numbers", "1,2", 3);

    /* Extended input testing */
    testOperation(calculator, "three numbers", "1,2,3", 6);
    testOperation(calculator, "five numbers", "1,2,3,4,5", 15);
    testOperation(calculator, "New Line as Delimiter", "1\n2,3", 6);
    testOperation(calculator, "Invalid format Clarification", "1,\n", 1);

    /* Custom Delimiters Testing */
    testOperation(calculator, "Single-character custom delimiter", "//;\n1;2", 3);
    testOperation(calculator, "Multi-character custom delimiter", "//[***]\n1***2***3", 6);

    /* Negative Testing */
    testException(calculator, "negative numbers", "1,-2,-3",
                  "Negative numbers are not allowed: -2 -3");

    /* Large Numbers Testing */
    testOperation(calculator, "large numbers", "2,1001", 2);

    return 0;
}
