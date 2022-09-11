#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "input.h"
using namespace std;

int globalnum2, globalnum3;

int input::return_num2() {
	return globalnum2;
}

int input::return_num3() {
	return globalnum3;
}

vector<string> input::main() {

	string userinput;
	cout << "Beginning simulation" << endl;
	cout << "Please enter the name of the configuration file:"; //user inputs file name
	cin >> userinput;


	fstream file;
	file.open(userinput); //open file

	while(!file.is_open()) { // if file doesnt open stay in loop until it does
		cout << "ERROR: COULD NOT OPEN FILE" << endl; 
		cout << "Please enter the name of the configuration file:"; //user inputs file name
		cin >> userinput;
		file.open(userinput); //open file
	}

	string line1, line2, line3, testline;
	int linenum2, linenum3;

	getline(file, line1); //get first line of config
	getline(file, line2); //second line
	getline(file, line3); //third line

	line1.erase(line1.begin(), line1.begin() + 14); //erase the Region Layout: part
	line2.erase(line2.begin(), line2.begin() + 11); //erase the Time Limit: part
	line3.erase(line3.begin(), line3.begin() + 13); //erase the Refresh Rate: part

	linenum2 = stoi(line2); //turn string into int
	linenum3 = stoi(line3);

	globalnum2 = linenum2;
	globalnum3 = linenum3;

	file.close();
	file.open(line1); //open layout file

	vector<string> storage;   //vector storage for the layout
	string interim;
	int num = 1; //replace loop iterator
	int i = 0; //iterator
	int replacenum = 0; //index to replace
	int notspacenum = 0; //number of not-spaces
	int stringnum = 1; //string iterator

	while (!file.eof()) {
		getline(file, interim); //grab a line
		num = 1; //reset num to 1
		replacenum = 1; //reset this to 1
		if (interim.length() == 0) {
			break;
		}
		else {
			stringnum = interim.length() + 3; //length of string
		}
		notspacenum = (interim.length() - 1) / 2;

		while (interim.begin() + num < interim.end() - notspacenum) { //this is how many times we need to replace in a line
			interim.replace(replacenum, 1, " "); //replace commas with spaces
			num = num + 1; //next space
			replacenum = replacenum + 2; //replace the next-next index
		}

		storage.push_back(interim); //put line in vector
		i++; //iterate
	}

	int vectornum = 0; //vector iterator
	num = 0; //normal iterator

	cout << "Initial Region State" << endl;
	while (num < stringnum) { //output a line of --- as long as the string + 2
		cout << "-";
		num++;
	}
	cout << endl;

	while (storage.begin() + vectornum < storage.end()) { //for the duration of the vector
		interim = storage.at(vectornum); //grab a string
		cout << "|" << interim << " |" << endl; //print it with walls
		vectornum = vectornum + 1; //move to next vector iterator
	}
	num = 0; //reset normal iterator to 0

	while (num < stringnum) { //output a line of --- as long as the string + 2
		cout << "-";
		num++;
	}
	cout << endl;
	cout << endl;

	return storage;
}
