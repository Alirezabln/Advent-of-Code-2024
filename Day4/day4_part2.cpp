/*
--------------------------
Advent of Code 2024
Alireza Bolourian
Challenge 4 of 25
Part 2
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

	// find diagonal 'MAS' or 'SAM' words in the search vector
	for (int i = 0; i < search.size() - 2; i++) {
		for (int j = 0; j < search[i].size() - 2; j++) {
			if ((search[i][j] == 'M' && search[i + 1][j + 1] == 'A' && search[i + 2][j + 2] == 'S') || 
											(search[i][j] == 'S' && search[i + 1][j + 1] == 'A' && search[i + 2][j + 2] == 'M')) {
				// check if X-'MAS || SAM' is present l
				if ((search[i][j+2] == 'M' && search[i + 2][j] == 'S') || (search[i][j + 2] == 'S' && search[i + 2][j] == 'M'))
					total++;
			}
		}
	}

	cout << "The number of 'X-MAS' words in the input is: " << total << endl;


	return 0;
}