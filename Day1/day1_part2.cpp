/*
--------------------------
Advent of Code 2024
Alireza Bolourian
Challenge 1 of 25
Part 2
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

	int total = 0;

	for (int i = 0; i < col1.size(); i++) {
		int number1 = col1[i];
		int count = 0;
		for (int j = 0; j < col2.size(); j++) {
			if (col2[j] == number1) {
				count++;
			}
		}
		total += (number1 * count);
	}

	cout << "Total Similarity Score: " << total << endl;

	return 0;
}