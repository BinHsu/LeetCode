// RemoveCoveredIntervals_1288.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const vector<int>& lhs, const vector<int>& rhs) {
            return lhs[0] < rhs[0] || (lhs[0] == rhs[0] && lhs[1] > rhs[1]);
        });
        //for (const auto& interval : intervals) {
        //    std::cout << interval[0] << "," << interval[1] << std::endl;
        //}
        //std::cout << "BBB" << std::endl;
        for (int i(0); i + 1 < intervals.size(); ++i) {
            std::cout << intervals[i][0] << "," << intervals[i][1] << std::endl;
            for (auto itFindCovered = intervals.begin() + i + 1; itFindCovered != intervals.end();) {
                if (intervals[i][0] <= (*itFindCovered)[0] && intervals[i][1] >= (*itFindCovered)[1]) {
                    itFindCovered = intervals.erase(itFindCovered);
                }
                else {
                    ++itFindCovered;
                }

            }
        }
        return intervals.size();
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
