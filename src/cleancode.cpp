// Online C++ compiler to run C++ program online

#include <iostream>
using namespace std;

class RC {
	string vehicleRegNo;
public:
	~RC() {
		cout << "RC Destructed" << endl;
	}
	RC() {
		cout << "RC Constructed" << endl;
	}
};

class TPMS {
protected:

	~TPMS() {
		cout << "TPMS Destructed" << endl;
	}
	TPMS() {
		cout << "TPMS Constructed" << endl;
	}
};

class NexDigitronTPMS : public TPMS {
public:
	~NexDigitronTPMS() {
		cout << "NexDigitronTPMS Destructed" << endl;
	}
	NexDigitronTPMS() {
		cout << "NexDigitronTPMS Constructed" << endl;
	}
};
class BoschTPMS : public TPMS {
public:
	~BoschTPMS() {
		cout << "BoschTPMS Destructed" << endl;
	}
	BoschTPMS() {
		cout << "BoschTPMS Constructed" << endl;
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
	TPMS *tpms;
	string regNumber;
public:
	Car(TPMS *ptr) :
			tpms { ptr } {
		cout << "Car Constructed" << endl;
	}
	~Car() {
		cout << "Car Destructed" << endl;
	}
	void installTPMS(TPMS *ptr) {
		tpms = ptr;
	}
};

void buildCar(BoschTPMS *ptr) {
	Car alto { ptr };
}
void buildCar(NexDigitronTPMS *ptr) {
	Car swift { ptr };
}

int main() {

	// Write C++ code here
	BoschTPMS bTpms;
	NexDigitronTPMS ndTpms;
	buildCar(&bTpms);
	buildCar(&ndTpms);
	return 0;

}
