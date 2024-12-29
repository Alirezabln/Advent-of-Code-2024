/*
--------------------------
Advent of Code 2024
Alireza Bolourian
Challenge 4 of 25
Part 1
--------------------------
*/

#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

int main() {
	ifstream file("input_day4.txt");
	vector<vector<char>> search;
	// create a vector of char vectors to store the input
	if (file.is_open()) {
		char c;
		vector<char> temp;
		while (file.get(c)) {
			if (c == '\n') {
				// deep copy
				search.push_back(temp);
				temp.clear();
			}
			else {
				temp.push_back(c);
			}
		}
		search.push_back(temp);
	}

	int total = 0;

	// search for the horizontal word 'XMAS' in the search vector 
	for (int i = 0; i < search.size(); i++) {
		for (int j = 0; j < search[i].size() - 3; j++) {
			if (search[i][j] == 'X' && search[i][j + 1] == 'M' && search[i][j + 2] == 'A' && search[i][j + 3] == 'S') {
				total++;
			}
		}
	}

	// search for the backward word 'XMAS' in the search vector
	for (int i = 0; i < search.size(); i++) {
		for (int j = 3; j < search[i].size(); j++) {
			if (search[i][j] == 'X' && search[i][j - 1] == 'M' && search[i][j - 2] == 'A' && search[i][j - 3] == 'S') {
				total++;
			}
		}
	}

	// search for the vertical word 'XMAS' in the search vector
	for (int i = 0; i < search.size() - 3; i++) {
		for (int j = 0; j < search[i].size(); j++) {
			if (search[i][j] == 'X' && search[i + 1][j] == 'M' && search[i + 2][j] == 'A' && search[i + 3][j] == 'S') {
				total++;
			}
		}
	}

	// search for the backward vertical word 'XMAS' in the search vector
	for (int i = 3; i < search.size(); i++) {
		for (int j = 0; j < search[i].size(); j++) {
			if (search[i][j] == 'X' && search[i - 1][j] == 'M' && search[i - 2][j] == 'A' && search[i - 3][j] == 'S') {
				total++;
			}
		}
	}

	// search for the right diagonal word 'XMAS' in the search vector
	for (int i = 0; i < search.size() - 3; i++) {
		for (int j = 0; j < search[i].size() - 3; j++) {
			if (search[i][j] == 'X' && search[i + 1][j + 1] == 'M' && search[i + 2][j + 2] == 'A' && search[i + 3][j + 3] == 'S') {
				total++;
			}
		}
	}

	// search for the left diagonal word 'XMAS' in the search vector
	for (int i = 0; i < search.size() - 3; i++) {
		for (int j = 3; j < search[i].size(); j++) {
			if (search[i][j] == 'X' && search[i + 1][j - 1] == 'M' && search[i + 2][j - 2] == 'A' && search[i + 3][j - 3] == 'S') {
				total++;
			}
		}
	}

	// search for the backward right diagonal word 'XMAS' in the search vector
	for (int i = 3; i < search.size(); i++) {
		for (int j = 0; j < search[i].size() - 3; j++) {
			if (search[i][j] == 'X' && search[i - 1][j + 1] == 'M' && search[i - 2][j + 2] == 'A' && search[i - 3][j + 3] == 'S') {
				total++;
			}
		}
	}

	// search for the backward left diagonal word 'XMAS' in the search vector
	for (int i = 3; i < search.size(); i++) {
		for (int j = 3; j < search[i].size(); j++) {
			if (search[i][j] == 'X' && search[i - 1][j - 1] == 'M' && search[i - 2][j - 2] == 'A' && search[i - 3][j - 3] == 'S') {
				total++;
			}
		}
	}

	cout << "The number of 'XMAS' words in the input is: " << total << endl;


	return 0;
}