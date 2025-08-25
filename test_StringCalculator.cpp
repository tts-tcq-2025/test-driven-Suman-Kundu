#include <iostream>
#include <cassert>
#include<string>
#include "StringCalculator.h"

int main() {
    StringCalculator Calculator;
    int result = -1;
    
   /* Basic Functionality Testing*/
    std::cout << "Testing empty string..." << std::endl;
    result = Calculator.Add("");
    std::cout << "Result: " << result << std::endl;
    assert(result == 0);
    std::cout << "✓ Empty string test passed!" << std::endl;
    
    std::cout << "Testing Single number..." << std::endl;
    result = Calculator.Add("1");
    std::cout << "Result: " << result << std::endl;
    assert(result == 1);
    std::cout << "✓ Single number test passed!" << std::endl;
    
    std::cout << "Testing two numbers..." << std::endl;
    result = Calculator.Add("1,2");
    std::cout << "Result: " << result << std::endl;
    assert(result == 3);
    std::cout << "✓ Single number test passed!" << std::endl;
    
   
   /* Extended input testing */
    std::cout << "Testing three numbers..." << std::endl;
    result = Calculator.Add("1,2,3");
    std::cout << "Result: " << result << std::endl;
    assert(result == 6);
    std::cout << "✓ Three numbers test passed!" << std::endl;

    std::cout << "Testing five numbers..." << std::endl;
    result = Calculator.Add("1,2,3,4,5");
    std::cout << "Result: " << result << std::endl;
    assert(result == 15);
    std::cout << "✓ Five numbers test passed!" << std::endl;

    std::cout << "Testing New Line as Delimiter..." << std::endl;
    result = Calculator.Add("1\n2,3");
    std::cout << "Result: " << result << std::endl;
    assert(result == 6);
    std::cout << "✓ New Line as Delimiter test passed!" << std::endl;

    std::cout << "Testing Invalid format Clarification..." << std::endl;
    result = Calculator.Add("1,\n");
    std::cout << "Result: " << result << std::endl;
    assert(result == 1);
    std::cout << "✓ Invalid format Clarification test passed!" << std::endl;

    /* Custom Delimiters Testing */
    std::cout << "Testing Single-character custom delimiter..." << std::endl;
    result = Calculator.Add("//;\n1;2");
    std::cout << "Result: " << result << std::endl;
    assert(result == 3);
    std::cout << "✓ Single-character Custom delimiter test passed!" << std::endl;

    std::cout << "Testing Multi-character custom delimiter..." << std::endl;
    result = Calculator.Add("//[***]\n1***2***3");
    std::cout << "Result: " << result << std::endl;
    assert(result == 6);
    std::cout << "✓ Multi-character Custom delimiter test passed!" << std::endl;


    /*Negative Testing */
    std::cout << "Testing negative numbers..." << std::endl;
    try {
        result = Calculator.Add("1,-2,-3");
    } catch (const std::invalid_argument& e) {
        std::cout << "Result: " << e.what() << std::endl;
        assert(std::string(e.what()) == "Negative numbers are not allowed: -2 -3");
    }
    std::cout << "✓ Negative numbers test passed!" << std::endl;


    /*Large Numbers Testing */
    std::cout << "Testing large numbers..." << std::endl;
    result = Calculator.Add("2,1001");
    std::cout << "Result: " << result << std::endl;
    assert(result == 2);
    std::cout << "✓ Large numbers test passed!" << std::endl;

    return 0;
}