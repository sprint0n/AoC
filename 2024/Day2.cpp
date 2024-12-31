#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

bool isSafe(vector<int> values)
{
    bool anyNeg = false;
    bool anyPos = false;
    vector<int> changes;
    for (int i = 0; i < values.size() - 1; i++)
    {
        changes.push_back(values.at(i) - values.at(i + 1));
    }
    for (int i = 0; i < changes.size(); i++)
    {
        if (abs(changes.at(i)) <= 0 || abs(changes.at(i)) > 3)
        {
            return false;
        }

        if (changes.at(i) < 0)
        {
            anyNeg = true;
        }
        else if (changes.at(i) > 0)
        {
            anyPos = true;
        }
    }

    if (anyPos && !anyNeg)
    {
        return true;
    }
    if (anyNeg && !anyPos)
    {
        return true;
    }
    return false;
}

int main()
{
    ifstream inputFile("Day2.txt");
    string inputVal;
    int safeCount = 0;
    int dampCount = 0;

    while (getline(inputFile, inputVal))
    {
        vector<int> values = {};
        istringstream iss(inputVal);
        int n;
        // read line
        while (iss >> n)
        {
            values.push_back(n);
        }
        // create changes vec
        if (isSafe(values))
        {
            safeCount++;
        }
        else
        {
            for (int i = 0; i < values.size(); i++)
            {
                vector<int> copy = values;
                // https://cplusplus.com/reference/vector/vector/erase/
                copy.erase(copy.begin() + i);
                if (isSafe(copy))
                {
                    dampCount++;
                    break;
                }
            }
        }
    }
    cout << safeCount << endl;
    cout << dampCount + safeCount << endl;
}
