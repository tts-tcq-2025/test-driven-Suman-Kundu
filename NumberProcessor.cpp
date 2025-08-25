#include "NumberProcessor.h"
#include <stdexcept>

// Parse numbers using given delimiters
std::vector<int> NumberProcessor::parseNumbers(const std::string& numbers, const std::string& delimiter) {
    std::vector<int> result;
    auto tokens = split(numbers, delimiter);
    
    for (const auto& token : tokens) {
        if (!token.empty()) {
            result.push_back(std::stoi(token));
        }
    }
    
    return result;
}

// Split string by multiple delimiters 
std::vector<std::string> NumberProcessor::split(const std::string& text, const std::string& delimiters) {
    std::vector<std::string> tokens;
    size_t start = 0;
    
    while (start < text.length()) {
        size_t end = text.find_first_of(delimiters, start);
        if (end == std::string::npos) {
            tokens.push_back(text.substr(start));
            break;
        }
        addToken(tokens, text, start, end);
        start = end + 1;
    }
    
    return tokens;
}

// Add token if valid 
void NumberProcessor::addToken(std::vector<std::string>& tokens, const std::string& text, size_t start, size_t end) {
    if (end > start) {
        tokens.push_back(text.substr(start, end - start));
    }
}

// Validate numbers for negative values 
void NumberProcessor::validateNumbers(const std::vector<int>& numbers) {
    auto negatives = findNegatives(numbers);
    if (!negatives.empty()) {
        throwNegativeException(negatives);
    }
}

// Find negative numbers 
std::vector<int> NumberProcessor::findNegatives(const std::vector<int>& numbers) {
    std::vector<int> negatives;
    for (int num : numbers) {
        if (num < 0) {
            negatives.push_back(num);
        }
    }
    return negatives;
}

// Throw exception with negative numbers 
void NumberProcessor::throwNegativeException(const std::vector<int>& negatives) {
    std::string message = "Negative numbers are not allowed:";
    for (int neg : negatives) {
        message += " " + std::to_string(neg);
    }
    throw std::invalid_argument(message);
}

// Sum valid numbers (ignore > 1000) 
int NumberProcessor::sumValidNumbers(const std::vector<int>& numbers) {
    int sum = 0;
    
    for (int num : numbers) {
        if (num <= 1000) {
            sum += num;
        }
    }
    
    return sum;
}
