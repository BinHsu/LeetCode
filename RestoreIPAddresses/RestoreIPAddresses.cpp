// RestoreIPAddresses.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> results;
        for (int i = 1; i < 4; ++i)
        {
            if (i + 3 > s.size())
            {
                continue;
            }
            auto strI = s.substr(0, i);
            if (strI.front() == '0' && strI.size() > 1)
            {
                continue;
            }
            auto intI = stoi(strI);
            if (intI > 255)
            {
                continue;
            }
            for (int j = 1; j < 4; ++j)
            {
                if (i + j + 2 > s.size())
                {
                    continue;
                }
                auto strJ = s.substr(i, j);
                if (strJ.front() == '0' && strJ.size() > 1)
                {
                    continue;
                }
                auto intJ = stoi(strJ);
                if (intJ > 255)
                {
                    continue;
                }
                for (int k = 1; k < 4; ++k)
                {
                    if (i + j + k + 1 > s.size())
                    {
                        continue;
                    }
                    auto strK = s.substr(i + j, k);
                    if (strK.front() == '0' && strK.size() > 1)
                    {
                        continue;
                    }
                    auto intK = stoi(strK);
                    if (intK > 255)
                    {
                        continue;
                    }
                    for (int l = 1; l < 4; ++l)
                    {
                        if (i + j + k + l != s.size())
                        {
                            continue;
                        }
                        auto strL = s.substr(i + j + k, l);
                        if (strL.front() == '0' && strL.size() > 1)
                        {
                            continue;
                        }
                        auto intL = stoi(strL);
                        if (intL > 255)
                        {
                            continue;
                        }
                        results.push_back(strI + '.' + strJ + '.' + strK + '.' + strL);
                    }
                }
            }
        }
        return results;
    }
};
int main()
{
    Solution solution;
    const auto results = solution.restoreIpAddresses("25525511135");
    for (const auto& result : results)
    {
        std::cout << result << std::endl;
    }
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
