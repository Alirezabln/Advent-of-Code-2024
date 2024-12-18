/*
--------------------------
Advent of Code 2024
Alireza Bolourian
Challenge 3 of 25
Part 1
--------------------------
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>


using namespace std;

int main() {
	ifstream file("input_day3.txt");
	ostringstream ss;
	ss << file.rdbuf();
	string input = ss.str();

	file.close();
	
	regex re(R"(mul\(-?\d+,-?\d+\))");
	sregex_iterator begin(input.begin(), input.end(), re);
	sregex_iterator end;

	int total = 0;

	for (sregex_iterator i = begin; i != end; i++) {
		int mul = 1;
		string match = i->str();
		int pos = match.find(',');
		// First argument is the starting index, second is the length of the substring
		int number1 = stoi(match.substr(4, pos-4));
		int number2 = stoi(match.substr(pos + 1, match.size() - pos - 2));
		mul = number1 * number2;
		total += mul;
	}

	cout << "The total is: " << total << endl;

	return 0;
}