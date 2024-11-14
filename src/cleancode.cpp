//============================================================================
// Name        : cleancode.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

class FindLetter
{
public:
	virtual bool findStringsContainingLetter(const string st, char letter)
	{
        if (st.find(letter) != string::npos) {
            return true;
        }

        return false;
	}
};


int main() {

	std::string arry[] = {"Bosch", "BGSW", "Test", "Deepak", "Shetty"};
	FindLetter find_s;

	int arraySize = sizeof(arry) / sizeof(arry[0]);
	for (int i = 0; i < arraySize; ++i)
	{
		auto status = find_s.findStringsContainingLetter(arry[i], 'S');
		if(status) {
			cout << "The letter 'S' found in the string: " << arry[i] << endl;
		}
	}

	return 0;
}
