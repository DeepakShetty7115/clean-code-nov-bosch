//============================================================================
// Name        : cleancode.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <functional>

using namespace std;

bool ContainsLetter(const std::string& str, char letter)
{
    for (char ch : str) {
        if (ch == letter) {
            return true;
        }
    }
    return false;
}

bool ContainsString(const std::string& str, std::string strtofind)
{
	if (str == strtofind) {
            return true;
    }
    return false;
}

bool ContainsEndLetter(const std::string& str, char letter)
{
	if (!str.empty() && str.back() == letter) {
		return true;
	}
    return false;
}

std::vector<std::string> findStrings(const std::vector<std::string>& strings,
		const std::function<bool(const std::string&)>& condition)
{
    std::vector<std::string> result;
    for (const std::string& str : strings) {
        if (condition(str)) {
            result.push_back(str);
        }
    }
    return result;
}

int main()
{
    std::vector<std::string> strings = {"apple", "banana", "cherry", "date", "elderberry"};
    char letter = 'a';

    // Create a std::function that checks for the specific letter
    std::function<bool(const std::string&)> letterCondition = [letter](const std::string& str) {
        return ContainsLetter(str, letter);
    };

    // Find strings that contain the specified letter
    std::vector<std::string> foundStrings = findStrings(strings, letterCondition);

    std::cout << "Strings containing the letter '" << letter << "':" << std::endl;
    for (const std::string& str : foundStrings) {
        std::cout << str << std::endl;
    }

    std::string st = "banana";
    // Create a std::function that checks for the specific letter at the end
    std::function<bool(const std::string&)> EndletterCondition = [st](const std::string& str) {
        return ContainsString(str, st);
    };

    // Find strings that contain the specified letter at the end
    std::vector<std::string> EndfoundStrings = findStrings(strings, EndletterCondition);

    std::cout << "Strings containing the end letter '" << letter << "':" << std::endl;
    for (const std::string& str : EndfoundStrings) {
        std::cout << str << std::endl;
    }

    return 0;
}


