#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <iterator>

using namespace std;

int mul(int x, int y)
{
    return x * y;
}

int main()
{
    ifstream inputFile("Day3.txt");
    int part1_sum = 0;
    int part2_sum = 0;
    string inputVal;
    // mul(NUMBER,NUMBER)
    // NUMBER == 0,1,2,3,4,5,6,7,8,9 1-3

    const string re_str = "(mul|do|don't)\\((\\d+)?,?(\\d+)?\\)";
    // mul(1)
    // mul(1,)
    // mul()

    regex check(re_str);
    bool multiplying = true;
    while (getline(inputFile, inputVal))
    {
        auto muls_begin = sregex_iterator(inputVal.begin(), inputVal.end(), check);
        auto muls_end = sregex_iterator();

        for (sregex_iterator i = muls_begin; i != muls_end; i++)
        {
            smatch match = *i;
            string match_str = match.str();
            // match[0] = mul(1,2) or do() or don't()
            // match[1] = mul or do or dont
            // match[2] = first num
            // match[3] = second num
            if (match[1].str() == "do")
            {
                multiplying = true;
            }
            else if (match[1].str() == "don't")
            {
                multiplying = false;
            }
            else if (match[1].str() == "mul" && match.size() == 4)
            {
                
                int left_number = stoi(match[2].str());
                int right_number = stoi(match[3].str());
                // cout << match_str << " -> " << left_number << " * " << right_number << " = " << mul(left_number, right_number) << endl;
                if (multiplying)
                {
                    part2_sum += mul(left_number, right_number);
                }
                part1_sum += mul(left_number, right_number);
            }
        }
    }
    cout << "Part 1 answer: " << part1_sum << endl;
    cout << "Part 2 answer: " << part2_sum << endl;

    return 0;
}