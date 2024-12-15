/*
--------------------------
Advent of Code 2024
Alireza Bolourian
Challenge 2 of 25
Part 2
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
		bool goodlevel = false;
		int badLevel = 0;
		for (int i = 0; i < report.size(); i++) {
			if (i == report.size() - 1) {
				safe++;
				break;
			}
			// Check to see if the difference between two consecutive numbers is less than 4 and it is increasing
			if (((report[i + 1] - report[i]) < 1) || ((report[i + 1] - report[i]) > 3)){
				for (int j = i; j < i+2; j++) {
					vector<int> temp = report;
					temp.erase(temp.begin() + j);
					for (int k = 0; k < temp.size(); k++) {
						if (k == temp.size() - 1) {
							safe++;
							goodlevel = true;
							break;
						}
						if (((temp[k + 1] - temp[k]) < 1) || ((temp[k + 1] - temp[k]) > 3)) {
							badLevel++;
							break;
						}
					}
					if (goodlevel)
						break;
				}
			}
			if ((goodlevel) || (badLevel > 1))
				break;
		}
	}

	for (auto report : reports) {
		bool goodlevel = false;
		int badLevel = 0;
		for (int i = 0; i < report.size(); i++) {
			if (i == report.size() - 1) {
				safe++;
				break;
			}
			// Check to see if the difference between two consecutive numbers is less than 4 and it is increasing
			if (((report[i] - report[i + 1]) < 1) || ((report[i] - report[i + 1]) > 3)) {
				// Remove the ith or (i+1)th element and check the rest of the elements
				for (int j = i; j < i + 2; j++) {
					vector<int> temp = report;
					temp.erase(temp.begin() + j);
					for (int k = 0; k < temp.size(); k++) {
						if (k == temp.size() - 1) {
							safe++;
							goodlevel = true;
							break;
						}
						if (((temp[k] - temp[k + 1]) < 1) || ((temp[k] - temp[k + 1]) > 3)) {
							badLevel++;
							break;
						}
					}
					if (goodlevel)
						break;
				}
			}
			if ((goodlevel) || (badLevel > 1))
				break;
		}
	}

	cout << "The number of safe reports is: " << safe << endl;

	return 0;
}