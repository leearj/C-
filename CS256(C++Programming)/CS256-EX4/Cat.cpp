//Lee Jaeseung
//HW4-ex4
//Completed: 2016/01/31

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void replicate(string fileName);

int main(int arg, char* argtxt[]) {
	//if you type ur project name first to the cmd, it is considered as one.
	//Therefore, prints out appropriate error msg.
	if (arg == 1) cout << "[ERROR] : No arguments found." << endl;
	else
		for (int i = 0; i<arg; ++i)
			replicate(argtxt[i]);
	cout << "Hit enter to continue.";
	cin.get();
}
void replicate(string fileName) {
	string contents = "";
	ifstream fin(fileName);
	if (fin.fail()) cout << "Error: Invalid file: " << fileName << endl;
	while (fin >> contents) cout << contents << endl;
}