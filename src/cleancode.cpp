#include <iostream>
#include <memory>

using namespace std;


class BoschTPMS {
public:
    static BoschTPMS& getInstance() {
        static BoschTPMS instance;
        return instance;
    }
};


class Engine {
public:
	~Engine() {
		cout << "Engine Destructed" << endl;
	}
	Engine() {
		cout << "Engine Constructed" << endl;
	}
};
class Car {
	Engine engine;
	BoschTPMS& tpms;
public:
	Car() : tpms(BoschTPMS::getInstance()) {
		cout << "Car Constructed" << endl;
	}
	~Car() {
		cout << "Car Destructed" << endl;
	}
};
void buildCar() {
	Car alto;
}

int main() {
	// Write C++ code here
	buildCar();
	return 0;
}
