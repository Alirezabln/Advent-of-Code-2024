/*
--------------------------
Advent of Code 2024
Alireza Bolourian
Challenge 3 of 25
Part 2
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

	// Serach for multiple expressions
	regex re(R"(mul\(-?\d+,-?\d+\)|do\(\)|don't\(\))");
	sregex_iterator begin(input.begin(), input.end(), re);
	sregex_iterator end;

	int total = 0;
	int number3 = 1;

	for (sregex_iterator i = begin; i != end; i++) {
		int mul = 1;
		string match = i->str();
		// if the match is "do()" then number3 is 1, otherwise it is 0 (no multiplication)
		if (match == "do()") 
			number3 = 1;
		else if (match == "don't()")
			number3 = 0;
		else {
			int pos = match.find(',');
			// First argument is the starting index, second is the length of the substring
			int number1 = stoi(match.substr(4, pos - 4));
			int number2 = stoi(match.substr(pos + 1, match.size() - pos - 2));
			mul = number1 * number2 * number3;
			total += mul;
		}
	}

	cout << "The total is: " << total << endl;

	return 0;
}