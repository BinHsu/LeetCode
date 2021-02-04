// SimplifyPath.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    string SubPath(string& path)
    {
        auto it = path.find_first_of('/');
        string subpath;
        if (it != string::npos)
        {
            path = path.substr(it);
            subpath = path.substr(0, it);
        }
        else
        {
            subpath
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
        ShellSlash(path);
        for (string subStr = SubPath(path); !subStr.empty(); subStr = SubPath(path))
        {
            std::cout << subStr << std::endl;
            std::cout << path << std::endl;
            ShellSlash(subStr);
            if (subStr == ".")
            {
                continue;
            }
            if (subStr == ".." && paths.size())
            {
                paths.pop_back();
                continue;
            }
            paths.push_back(subStr);
        }

        string result = "/";
        for (const auto& subPath : paths)
        {
            result += subPath;
        }
        return result;
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
