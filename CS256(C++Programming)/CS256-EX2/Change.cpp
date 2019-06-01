// Lee Jaeseung
// Exercise 2
// Completed 1/18/2016

#include <iostream>
using namespace std;

int main() {

	int cents;
	int quarter;
	int dime;
	int nickel;
	int penny;
	int remainder;

	cout << "Please enter a number in the range [0 ~ 99]: ";
	cin >> cents;

	while (cents > 99 || cents < 0) {
		cout << "The number is out of range. Please try again." << endl;
		cin >> cents;
	}
	cout << "The proper change is:" << endl;

	if (cents == 0)
		cout << "0 quarter.\n0 dime.\n0 nickel.\n0 penny." << endl;




	quarter = cents / 25; remainder = cents % 25;
	dime = remainder / 10; remainder = remainder % 10;
	nickel = remainder / 5; remainder = remainder % 5;
	penny = remainder;

	if (quarter == 1)
		cout << quarter << " quarter." << endl;
	else if (quarter > 1)
		cout << quarter << " quarters." << endl;

	if (dime == 1)
		cout << dime << " dime." << endl;
	else if (dime > 1)
		cout << dime << " dimes." << endl;

	if (nickel == 1)
		cout << nickel << " nickel." << endl;
	else if (nickel > 1)
		cout << nickel << " nickels." << endl;

	if (penny == 1)
		cout << penny << " penny." << endl;
	else if (penny > 1)
		cout << penny << " pennies." << endl;

	cin.get();
	cin.get();
	return 0;
}
