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
	virtual void findStringsContainingLetter(const string arr[], int size, char target) {
	    bool found = false;
	    for (int i = 0; i < size; ++i) {
	        if (arr[i].find(target) != string::npos) {
	            cout << "The letter '" << target << "' is found in the string: " << arr[i] << endl;
	            found = true;
	        }
	    }
	    if (!found) {
	        cout << "The letter '" << target << "' is not found in any string in the array." << endl;
	    }
	}
};


int main() {

	std::string arry[] = {"Bosch", "BGSW", "Test", "Deepak", "Shetty"};
	FindLetter find_s;

	int arraySize = sizeof(arry) / sizeof(arry[0]);
	find_s.findStringsContainingLetter(arry, arraySize, 'S');
	find_s.findStringsContainingLetter(arry, arraySize, 'D');
	find_s.findStringsContainingLetter(arry, arraySize, 's');

	return 0;
}
