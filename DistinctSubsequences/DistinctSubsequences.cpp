// DistinctSubsequences.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
    int result = 0;
    void countDistinctV1(string s, string t, string tmp)
    {
        //std::cout << s << "\t" << t << "\t" << tmp << "\t" << result << std::endl;
        if (tmp == t)
        {
            ++result;
            return;
        }

        if (tmp != t.substr(0, tmp.size()) || s.size() + tmp.size() < t.size())
        {
            return;
        }

        if (s.empty())
        {
            return;
        }

        countDistinctV1(s.substr(1), t, tmp);
        tmp += s[0];
        countDistinctV1(s.substr(1), t, tmp);
    }
public:
    int numDistinctV1(string s, string t) {
        if (s.size() < t.size())
        {
            return 0;
        }
        countDistinctV1(s, t, std::string());
        return result;
    }
    int numDistinctV2(string s, string t) {
        if (s.empty() ||
            t.empty() ||
            s.size() < t.size()) {
            return 0;
        }

        std::vector<std::vector<unsigned int>> results;
        for (int i = 0; i < t.size(); ++i) {
            results.push_back(std::vector<unsigned int>());
            //std::cout << "row: " << i << std::endl;
            for (int j = 0; j < s.size(); ++j) {
                results[i].push_back(0);
                if (0 == i) {
                    if (t[i] == s[j]) {
                        if (0 == j) {
                            results[0][0] = 1;
                        }
                        else {
                            results[0][j] = results[0][j - 1] + 1;
                        }
                    }
                    else {
                        if (0 == j) {
                            results[0][0] = 0;
                        }
                        else {
                            results[0][j] = results[0][j - 1];
                        }
                    }
                }
                else if (j < i) {
                    results[i][j] = 0;
                }
                else
                {
                    if (t[i] == s[j]) {
                        results[i][j] = results[i - 1][j - 1] + results[i][j - 1];
                    }
                    else {
                        results[i][j] = results[i][j - 1];
                    }
                }
            }
            if (0 == results[i][s.size() - 1]) {
                std::cout << "no chance" << std::endl;
                return 0;
            }
        }

        for (int i = 0; i < t.size() - 1; ++i) {
            for (int j = 0; j < s.size() - 1; ++j) {
                std::cout << results[i][j] << ",";
            }
            std::cout << std::endl;
        }

        return results[t.size() - 1][s.size() - 1];
    }
};
int main()
{
    Solution sol;
    std::cout << sol.numDistinctV2("aabdbaabeeadcbbdedacbbeecbabebaeeecaeabaedadcbdbcdaabebdadbbaeabdadeaabbabbecebbebcaddaacccebeaeedababedeacdeaaaeeaecbe",
        "bddabdcae") << std::endl;
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
