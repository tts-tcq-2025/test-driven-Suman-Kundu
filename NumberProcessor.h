#pragma once
#include <string>
#include <vector>

class NumberProcessor {
public:
    static std::vector<int> parseNumbers(const std::string& numbers, const std::string& delimiter);
    static void validateNumbers(const std::vector<int>& numbers);
    static int sumValidNumbers(const std::vector<int>& numbers);

private:
    static std::vector<std::string> split(const std::string& text, const std::string& delimiters);
    static void addToken(std::vector<std::string>& tokens, const std::string& text, size_t start, size_t end);
    static std::vector<int> findNegatives(const std::vector<int>& numbers);
    static void throwNegativeException(const std::vector<int>& negatives);
};
