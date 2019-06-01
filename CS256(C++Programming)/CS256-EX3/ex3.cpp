// Lee Jaeseung
// ex3
// Completed 1/22/2016

#include <iostream>
#include <string>;
using namespace std;

int main() {
	int line; //user will assgin the value of line
	int space = 0;
	bool OnOff = false; // false = add, true = subtract
	string s = "XXXXXXXXXXXXXXXXXXXX";
	cout << "How many lines do you want me to print? " << endl;
	cin >> line;

	if (line > 0) {
		for (int i = 0; i < line; i++) {
			for (int j = 0; j < space; j++)	cout << " ";
			cout << s << endl;;
			if (!OnOff && space < 50) // [addition-status] , direction: 0 -> 50
				space++;
			else if (OnOff && space > 0)// [subtraction-status] , direction: 49 -> 1
				space--;
			else if (!OnOff && space == 50) {// [status: space == 50] , time to go back(decrementing)
				space--; //do space--; and make it go back . Switch the Onoff to subtract status as well.
				OnOff = !OnOff;
			}
			else {//else(it reaches to 0 from direction: 49 -> 1) , space++;
				space++;
				OnOff = !OnOff;
			}
		}//end of for loop
	}//end of if statement
	else {//Case for invalid input
		cout << "ERROR occured. The system will exit. " << endl;
		exit(1);
	}
	cin.get();
	cin.get();
}//main end
