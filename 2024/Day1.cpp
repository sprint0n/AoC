#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;




int main()
{
	
	vector<int> left = {};
	vector<int> right = {};
	ifstream inputFile("day1input.txt");
	int leftCol;
	int rightCol;
	int result = 0;

	while (inputFile >> leftCol >> rightCol) {
		left.push_back(leftCol);
		right.push_back(rightCol);
	}
	cout << left.size() << endl;
	cout << right.size() << endl;
	sort(left.begin(), left.end());
	sort(right.begin(), right.end());

	
	for (int i = 0; i < right.size(); i++) {
		result += abs(right.at(i) - left.at(i));
	}
	cout << result << endl;


	result = 0;
	for (int i = 0; i < left.size(); i++) {
		int tempCount = 0;
		for (int j = 0; j < right.size(); j++) {
			if (left.at(i) == right.at(j)) {
				tempCount++;
			}
		}
		result += tempCount * left.at(i);
	}
	cout << result << endl;


	return 0;

}

