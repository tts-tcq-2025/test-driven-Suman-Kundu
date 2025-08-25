#ifndef DELIMITERPARSER_H
#define DELIMITERPARSER_H

#include <string>

class DelimiterParser {
 public:
    static bool hasCustomDelimiter(const std::string& numbers);
    static std::string extractCustomDelimiter(const std::string& numbers);
    static std::string extractNumbers(const std::string& numbers);

 private:
    static std::string parseMultiCharDelimiter(const std::string& delimiterPart);
};

#endif  // DELIMITERPARSER_H

