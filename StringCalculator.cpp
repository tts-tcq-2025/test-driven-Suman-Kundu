#include "StringCalculator.h"
#include "DelimiterParser.h"
#include "NumberProcessor.h"

// Main Add function
int StringCalculator::Add(const std::string& numbers) {
    // Handle empty string
    if (numbers.empty()) {
        return 0;
    }
    
    // Set default delimiters
    std::string delimiter = ",\n";
    std::string numbersToProcess = numbers;
    
    // Handle custom delimiters
    if (DelimiterParser::hasCustomDelimiter(numbers)) {
        delimiter = DelimiterParser::extractCustomDelimiter(numbers);
        numbersToProcess = DelimiterParser::extractNumbers(numbers);
    }
    
    // Process numbers
    auto parsedNumbers = NumberProcessor::parseNumbers(numbersToProcess, delimiter);
    NumberProcessor::validateNumbers(parsedNumbers);
    return NumberProcessor::sumValidNumbers(parsedNumbers);
}
