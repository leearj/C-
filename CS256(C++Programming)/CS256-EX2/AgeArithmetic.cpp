// Lee Jaeseung
// Homework 1
// Completed 1/15/2016

#include <iostream>
using namespace std;

int main()
{
	int age;
	int ageSquared;
	int ageHalved;

	cout << "Please enter your age" << endl;
	cin >> age;
	while (age < 0 || age == 0) {
		cout << "The age can't be negative or 0.\n[Please enter your age again!]" << endl;
		cin >> age;
	}

	ageSquared = age*age;
	ageHalved = age / 2;

	//Taking care of boundary.
	if (ageHalved == 0) cout << "ageHalved value is 0 and can't proceed the calculation with it." << endl;
	else {
		//Task1 : Printout all the variables
		cout << "[age / ageSuqared / ageHalved] : " << age << ", " << ageSquared << ", " << ageHalved << endl;

		//Task2 : Calculations
		cout << "[age * ageHalved] : " << age*ageHalved << endl;
		cout << "[ageSquared / ageHalved] : " << ageSquared / ageHalved << endl;
		cout << "[remainder of ageSquared / ageHalved] : " << (ageSquared%ageHalved) << endl;
		cout << "[subtract ageHalved from age] : " << age - ageHalved << endl;
		cout << "[divide age by ageSquared] : " << age / ageSquared << endl;
		cout << "[add ageSquared to age] : " << ageSquared + age << endl;
		cout << "[mean of  age, ageSquared, and ageHalved] : " << (double)(age + ageSquared + ageHalved) / 3 << endl;
	}
	cin.get();
	cin.get();
	return 0;
}