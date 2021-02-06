// SearchA2DMatrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
    bool MySearch(const vector<vector<int>>& matrix, const int target)
    {
        auto H = matrix.size() - 1;
        auto L = 0;
        while (H > L)
        {
            std::cout << L << " - " << H << std::endl;
            auto M = (H + L) / 2;
            if (matrix[M].front() > target)
            {
                if (!M)
                {
                    return false;
                }
                H = M - 1;
                continue;
            }
            if (matrix[M].back() < target)
            {
                L = M + 1;
                continue;
            }
            H = M;
            break;
        }

        auto it = find(matrix[H].begin(), matrix[H].end(), target);
        return it != matrix[H].end();
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return MySearch(matrix, target);
    }
};
int main()
{
    Solution solution;
    vector<vector<int>> request{ {1,2,3}, {9,11,13}, {16,19,100} };
    std::cout << solution.searchMatrix(request, 11) << std::endl;
    return 0;
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
