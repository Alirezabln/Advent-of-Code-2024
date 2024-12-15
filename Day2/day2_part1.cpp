/*
--------------------------
Advent of Code 2024
Alireza Bolourian
Challenge 2 of 25
Part 1
--------------------------
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
	ifstream file("input_day2.txt");
	vector<vector<int>> reports;

	// Reading the file into a vector of vectors
	string row;
	int number;
	while (getline(file, row)) {
		vector<int> report;
		stringstream ss(row);
		while (ss >> number) {
			report.push_back(number);
		}
		reports.push_back(report);
	}
	file.close();

	// The algorithm
	int safe = 0;
	for (auto report : reports) {
		bool increasing = false;
		// Determine if the report is increasing or decreasing
		if (report[0] < report[1]) 
			increasing = true;
		for (int i = 0; i < report.size(); i++){
			if (i == report.size() - 1) {
				safe++;
				break;
			}
			if (increasing) {
					// Check to see if the difference between two consecutive numbers is less than 4 and it is increasing
					if (((report[i+1] - report[i]) < 1) || ((report[i + 1] - report[i]) > 3))
						break;
			}
					// Check to see if the difference between two consecutive numbers is less than 4 and it is decreasing
			else{
					if (((report[i] - report[i + 1]) < 1) || ((report[i] - report[i + 1]) > 3))
						break;
			}
		}
	}

	cout << "The number of safe reports is: " << safe << endl;

	return 0;
}