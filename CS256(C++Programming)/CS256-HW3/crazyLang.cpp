// Andrew Trang and Jaeseung Lee
// HW3
// 02-10-2016

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int tape[1000] = { 0 };
int index = 0;
int ui = 0; //current pointer
int* ptr = tape;
string input = "";

//Adds or Subtracts from the index of the tape.
void increment(int x) {
	if (x == 1 && ui < 9) {
		ptr++;
		ui++;
	}
	else if (x == 1 && index < 991)
		index++;
	else if (x == -1 && ui > 0) {
		ui--;
		ptr--;
	}
	else if (x == -1 && index > 0)
		index--;
	else
		cout << ">> Error: Index is out of bounds." << endl;
}

//Checks each case and performs the action
//for each index of the tape/file.
void execute(string str) {
	int counter = 0;
	int *find = ptr;
	for (int i = 0, j = i; i < str.length(); ++i) {
		switch (str[i]) {
		case '+':
			(*ptr)++;
			break;
		case '-':
			(*ptr)--;
			break;
		case '>':
			increment(1);
			break;
		case '<':
			increment(-1);
			break;
		case ':':
			cout << "Character: " << (char)*ptr << endl << endl;
			break;
		case '.':
			cout << "Integer: " << *ptr << endl << endl;
			break;
		case '{':
			counter=0;
			while (j < str.length()) {
				cout << str[j] << endl;
				if ((str[j]) == '{')
					counter++;
				else if ((str[j]) == '}')
					counter--;
				//find++;
				j++;
			}
			//if the value ptr value is 0,
			if (*ptr == 0)
				ptr = find;
			else
				execute(str.substr(i + 1, str.length()));
			break;
		}
	}
}

//Converts the script to C++ code
string codeWriter(string code) {
	string convertedScript = "";
	for (int i = 0; i < code.length(); ++i) {
		switch (code[i]) {
		case '+':
			convertedScript += "\t*ptr++;\r\n";
			break;
		case '-':
			convertedScript += "\t*ptr--;\r\n";
			break;
		case '>':
			convertedScript += "\tptr++;\r\n";
			break;
		case '<':
			convertedScript += "\tptr--;\r\n";
			break;
		case ':':
			convertedScript += "\tcout << tape[ui] << endl;\r\n";
			break;
		case '.':
			convertedScript += "\tcout << (char)tape[ui] << endl;\r\n";
			break;
		case '{':

			break; //NEED IMPLEMENTATION
		case '}':
			break; //NEED IMPLEMENTATION
		}
	}
	return convertedScript;
}
//Prints out the table.
void interface() {
	cout << endl << string(80, '-');
	printf("%42s\n", "TABLE");
	cout << string(80, '-');
	printf("Char:    | %4c | %4c | %4c | %4c | %4c | %4c | %4c | %4c | %4c | %4c |\n",
		tape[index], tape[index + 1], tape[index + 2], tape[index + 3], tape[index + 4], tape[index + 5],
		tape[index + 6], tape[index + 7], tape[index + 8], tape[index + 9], tape[index + 10]);
	printf("Value:   | %4d | %4d | %4d | %4d | %4d | %4d | %4d | %4d | %4d | %4d |\n",
		tape[index], tape[index + 1], tape[index + 2], tape[index + 3], tape[index + 4], tape[index + 5],
		tape[index + 6], tape[index + 7], tape[index + 8], tape[index + 9], tape[index + 10]);
	printf("Index:   | %4d | %4d | %4d | %4d | %4d | %4d | %4d | %4d | %4d | %4d |\n",
		index, index + 1, index + 2, index + 3, index + 4, index + 5, index + 6,
		index + 7, index + 8, index + 9, index + 10);
	cout << "              ";
	for (int i = 0; i < ui; i++)
		cout << "       ";
	cout << "^\n" << endl;
}

//Compiles the provided script to C++
void compile() {
	string outputFile;
	string code;
	ifstream fin(input.substr(3, input.length()));
	if (fin) {
		cout << "Enter a filename: ";
		getline(cin, outputFile);
		cout << (input.substr(input.length() - 4, input.length() - 1));
		if ((outputFile.substr(outputFile.length() - 4, outputFile.length() - 1).compare(".cpp")))
			outputFile += ".cpp";
		cout << "\n>> Compiling '" << outputFile << "'..\n" << endl;
		ofstream fout(outputFile);
		fout << "#include <iostream>\r\n\r\nint main(){\r\n\tint tape[1000] = {0};\r\n\tint *ptr = tape;\r\n" << endl;
		while (getline(fin, code))
			fout << codeWriter(code);
		fout << "\t}\r\n}" << endl;
		cout << ">> File saved." << endl;
	}
	else {
		cout << "Error: File Not Found" << endl;
	}
}

//Reads the premade WTFLanguage script and executes it
void read() {
	ifstream fin(input.substr(3, input.length()));
	if (fin) {
		cout << "\n>> Executing script from '" << input.substr(3, input.length()) << "'..\n" << endl;
		input = "";
		while (getline(fin, input))
			execute(input);
	}
	else {
		cout << "Error: File Not Found" << endl;
	}
}

//Main Loop
//Option to compile/execute/interactive mode.
void console() {
	if (input.length() == 0) {
		cout << "\n>> Interactive Mode Enabled\n" << endl;
		interface();
		while (input != "exit") {
			cout << "Enter a command: ";
			getline(cin, input);
			execute(input);
			interface();
		}
	}
	else if (input[0] == '-')
		if (input[1] == 'c')
			compile();
		else if (input[1] == 'e')
			read();
		else;
	else
		cout << "Error: '" << input << "' is not a valid command.\n";
}
//Title & starts loop
int main() {
	cout << string(80, '-');
	printf("%48s\n", "THE WTF COMPILER");
	cout << string(80, '-');
	while (input != "exit") {
		cout << "\nEnter a Command: ";
		getline(cin, input);
		console();
	}
	return 0;
}