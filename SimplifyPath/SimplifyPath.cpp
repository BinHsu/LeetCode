// SimplifyPath.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <gtest/gtest.h>
#include "../Sqrt/test.hpp"
using namespace std;
namespace SimplifyPath {
    class Solution {
        string SubPath(string& path)
        {
            ShellSlash(path);
            auto it = path.find_first_of('/');
            string subpath;
            if (it != string::npos)
            {
                subpath = path.substr(0, it);
                path = path.substr(it);
            }
            else
            {
                subpath = path;
                path = "";
            }
            return subpath;
        }

        void ShellSlash(string& path)
        {
            for (auto it = path.begin(); it != path.end();)
            {
                if (*it == '/')
                {
                    it = path.erase(it);
                    continue;
                }
                break;
            }
        }
    public:
        string simplifyPath(string path) {
            vector<string> paths;
            for (string subStr = SubPath(path); !subStr.empty(); subStr = SubPath(path))
            {
                std::cout << subStr << std::endl;
                std::cout << path << std::endl;
                ShellSlash(subStr);
                if (subStr == ".")
                {
                    continue;
                }
                if (subStr == "..")
                {
                    if (paths.size())
                    {
                        paths.pop_back();
                    }
                    continue;
                }
                paths.push_back(subStr);
            }

            string result;
            for (const auto& subPath : paths)
            {
                result += '/';
                result += subPath;
            }

            return paths.empty() ? "/" : result;
        }
    };
};

TEST(simplifyPath, normal)
{
    std::string test("/Data/VVTK/");
    SimplifyPath::Solution solution;
    const std::string answer("/Data/VVTK");
    EXPECT_EQ(answer, solution.simplifyPath(test));
}

int main(int argc, char* argv[])
{
    SimplifyPath::Solution solution;
    std::cout << solution.simplifyPath("/Data/VVTK/") << std::endl;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
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
