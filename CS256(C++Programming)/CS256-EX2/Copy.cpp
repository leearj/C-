// Lee Jaeseung
// Exercise 2
// Completed 1/18/2016

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

	string fileName1;
	string fileName2;
	int count = 0;
	char c = 0;

	cout << "Enter from file: ";
	getline(cin, fileName1);
	ifstream fin(fileName1);
	if (fin) {
		cout << " Enter to file: ";
		getline(cin, fileName2);
	}
	else {
		cout << "File open failed.\nNow the program will exit ";
		exit(1);
	}
	ofstream fout(fileName2);
	while (!fin.eof()) {//until it reaches to the end of line.
		fin >> c; //store one char to c
		fout << c; //copy it to the file2
		count++; //count it how many char
	}
	cout << "Copied " << count << " characters." << endl;

	fin.close();
	fout.close();

	cin.get();
	cin.get();
	return 0;
}