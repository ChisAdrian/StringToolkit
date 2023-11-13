#ifndef STRINGTOOLKIT_H_INCLUDED
#define STRINGTOOLKIT_H_INCLUDED

#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>

// Split a string into a vector of substrings based on a separator
std::vector<std::string> str_split(const std::string &input, const std::string &separator);

// Replace all occurrences of a substring in a string with another substring
std::string str_replace(const std::string &input, const std::string &search, const std::string &replace);

// Return the substring of a string before the last occurrence of a character
std::string str_beforeLastChar(const std::string &str, char target);

// Return the substring of a string after the last occurrence of a character
std::string str_afterLastChar(const std::string &str, char target);

// Return the substring of a string before the first occurrence of a character
std::string str_beforeFirstChar(const std::string &str, char target);

// Return the substring of a string after the first occurrence of a character
std::string str_afterFirstChar(const std::string &str, char target);

// Convert a string to a boolean
bool str_stringToBool(const std::string &str);

// Convert a string to a character
char str_stringToChar(const std::string &str);

// Convert a string to a double
double str_stringToDouble(const std::string &str);

// Convert a string to a long integer
long str_stringToLong(const std::string &str);

// Convert a string to a long long integer
long long str_stringToLongLong(const std::string &str);

// Convert a string to an unsigned long integer
unsigned long str_stringToULong(const std::string &str);

// Convert a string to an unsigned long long integer
unsigned long long str_stringToULongLong(const std::string &str);

// Convert a string representing a hexadecimal number to an integer
int str_stringToHex(const std::string &str);

// Convert a string representing a binary number to an integer
int str_stringToBinary(const std::string &str);

std::vector<std::string> str_split(const std::string &input, const std::string &separator)
{
    std::vector<std::string> tokens;
    size_t start = 0, end = 0;

    while ((end = input.find(separator, start)) != std::string::npos)
    {
        tokens.push_back(input.substr(start, end - start));
        start = end + separator.length();
    }

    tokens.push_back(input.substr(start));
    return tokens;
}

// Replace all occurrences of a substring in a string with another substring
std::string str_replace(const std::string &input, const std::string &search, const std::string &replace)
{
    std::string result = input;
    size_t pos = 0;

    while ((pos = result.find(search, pos)) != std::string::npos)
    {
        result.replace(pos, search.length(), replace);
        pos += replace.length();
    }

    return result;
}

// Return the substring of a string before the last occurrence of a character
std::string str_beforeLastChar(const std::string &str, char target)
{
    size_t lastPos = str.find_last_of(target);

    if (lastPos != std::string::npos)
    {
        return str.substr(0, lastPos);
    }

    return str; // Return the whole string if the character is not found
}

// Return the substring of a string after the last occurrence of a character
std::string str_afterLastChar(const std::string &str, char target)
{
    size_t lastPos = str.find_last_of(target);

    if (lastPos != std::string::npos && lastPos < str.length() - 1)
    {
        return str.substr(lastPos + 1);
    }

    return ""; // Return an empty string if the character is not found or is the last character
}

// Return the substring of a string before the first occurrence of a character
std::string str_beforeFirstChar(const std::string &str, char target)
{
    size_t firstPos = str.find(target);

    if (firstPos != std::string::npos)
    {
        return str.substr(0, firstPos);
    }

    return str; // Return the whole string if the character is not found
}

// Return the substring of a string after the first occurrence of a character
std::string str_afterFirstChar(const std::string &str, char target)
{
    size_t firstPos = str.find(target);

    if (firstPos != std::string::npos && firstPos < str.length() - 1)
    {
        return str.substr(firstPos + 1);
    }

    return ""; // Return an empty string if the character is not found or is the last character
}

// Convert a string to a boolean
bool str_stringToBool(const std::string &str)
{
    // Convert to lowercase for case-insensitive comparison
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);

    if (lowerStr == "true" || lowerStr == "1")
    {
        return true;
    }
    else if (lowerStr == "false" || lowerStr == "0")
    {
        return false;
    }
    else
    {
        std::cerr << "Invalid boolean representation." << std::endl;
        return false; // Default value
    }
}

// Convert a string to a character
char str_stringToChar(const std::string &str)
{
    if (str.length() == 1)
    {
        return str[0];
    }
    else
    {
        std::cerr << "Invalid character representation." << std::endl;
        return '\0'; // Default value
    }
}

// Convert a string to a double
double str_stringToDouble(const std::string &str)
{
    try
    {
        return std::stod(str);
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "Out of range: " << e.what() << std::endl;
    }

    return 0.0; // Default value if conversion fails
}

// Convert a string to a long integer
long str_stringToLong(const std::string &str)
{
    try
    {
        return std::stol(str);
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "Out of range: " << e.what() << std::endl;
    }

    return 0; // Default value if conversion fails
}

// Convert a string to a long long integer
long long str_stringToLongLong(const std::string &str)
{
    try
    {
        return std::stoll(str);
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "Out of range: " << e.what() << std::endl;
    }

    return 0; // Default value if conversion fails
}

// Convert a string to an unsigned long integer
unsigned long str_stringToULong(const std::string &str)
{
    try
    {
        return std::stoul(str);
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "Out of range: " << e.what() << std::endl;
    }

    return 0; // Default value if conversion fails
}

// Convert a string to an unsigned long long integer
unsigned long long str_stringToULongLong(const std::string &str)
{
    try
    {
        return std::stoull(str);
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "Out of range: " << e.what() << std::endl;
    }

    return 0; // Default value if conversion fails
}

// Convert a string representing a hexadecimal number to an integer
int str_stringToHex(const std::string &str)
{
    try
    {
        return std::stoi(str, nullptr, 16);
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "Out of range: " << e.what() << std::endl;
    }

    return 0; // Default value if conversion fails
}

// Convert a string representing a binary number to an integer
int str_stringToBinary(const std::string &str)
{
    try
    {
        return std::stoi(str, nullptr, 2);
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "Out of range: " << e.what() << std::endl;
    }

    return 0; // Default value if conversion fails
}

#endif // STRINGTOOLKIT_H_INCLUDED
