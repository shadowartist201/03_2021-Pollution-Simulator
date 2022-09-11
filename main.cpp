#include <string>
#include <vector>
#include <iostream>
#include "input.h"
#include "residential.h"

using namespace std;

int main() {
	input in;
	residential res;
	vector<string> storage;
	int num2, num3;
	storage = in.main(); //take the vector from input
	num2 = in.return_num2();
	num3 = in.return_num3();
	storage = res.main(storage, num2, num3); //put vector (and config) through residential

}
