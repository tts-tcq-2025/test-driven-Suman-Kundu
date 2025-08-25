#include "DelimiterParser.h"

// Check if string has custom delimiter format
bool DelimiterParser::hasCustomDelimiter(const std::string& numbers) {
    return numbers.length() >= 4 && numbers.substr(0, 2) == "//";
}

// Extract custom delimiter from string 
std::string DelimiterParser::extractCustomDelimiter(const std::string& numbers) {
    size_t newlinePos = numbers.find('\n');
    if (newlinePos == std::string::npos) return ",";
    
    std::string delimiterPart = numbers.substr(2, newlinePos - 2);
    
    // Handle multi-character delimiters: [***]
    if (delimiterPart.front() == '[' && delimiterPart.back() == ']') {
        return delimiterPart.substr(1, delimiterPart.length() - 2);
    }
    
    return delimiterPart;
}

// Extract numbers part from custom delimiter format 
std::string DelimiterParser::extractNumbers(const std::string& numbers) {
    size_t newlinePos = numbers.find('\n');
    return (newlinePos != std::string::npos) ? numbers.substr(newlinePos + 1) : "";
}
