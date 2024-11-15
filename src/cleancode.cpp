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
#include <sstream>
#include <cassert>

using namespace std;

function<bool(const string&)> ContainsLetter(char letter)
{
	function<bool(const string&)> contains = [letter](const string& item)->bool
			{
		for (char ch : item) {
			if (ch == letter) {
				return true;
			}
		}
		return false;
    };
	return contains;
}


function<bool(const string&)> ContainsString(std::string strtofind)
{
	function<bool(const string&)> contains = [strtofind](const string& item)->bool
			{
	if (item == strtofind) {
            return true;
    }
    return false;
	};
	return contains;
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

std::string FormattedString(const std::vector<std::string>& vec) {
    std::ostringstream oss;
    for (const std::string& str : vec) {
        oss << str << "\n";
    }
    return oss.str();
}

int main()
{
    std::vector<std::string> strings = {"apple", "banana", "cherry", "date", "elderberry"};

    char letter = 'a';
    std::function<bool(const std::string&)> letterCondition = ContainsLetter(letter);
    std::vector<std::string> foundStrings = findStrings(strings, letterCondition);
    std::cout << "Strings containing the letter '" << letter << "':" << std::endl;
    std::cout << FormattedString(foundStrings);

    std::string str = "banana";
    std::function<bool(const std::string&)> EndletterCondition = ContainsString(str);

    // Find strings that contain the specified letter at the end
    std::vector<std::string> EndfoundStrings = findStrings(strings, EndletterCondition);
    std::cout << "Matching string for : '" << str << "':" << std::endl;
    std::cout << FormattedString(EndfoundStrings);

    return 0;
}


