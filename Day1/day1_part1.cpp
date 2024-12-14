/*
--------------------------
Advent of Code 2024
Alireza Bolourian
Challenge 1 of 25
Part 1
--------------------------
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main() {
	ifstream file("input_part1.txt");
	vector<int> col1;
	vector<int> col2;
	int number;
	while (file >> number) {
		col1.push_back(number);
		file >> number;
		col2.push_back(number);
	}
	file.close();

	sort(col1.begin(), col1.end());
	sort(col2.begin(), col2.end());
	int total = 0;
	
	for (int i = 0; i < col1.size(); i++) {
		total += abs(col1[i] - col2[i]);
	}

	cout << "Total: " << total << endl;

	return 0;
}