// UniquePaths2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
    int result = 0;
    void Cal(vector<vector<int>>& obstacleGrid, int i, int j)
    {
        if (obstacleGrid[i][j] == 1)
        {
            return;
        }
        
        auto iMax = obstacleGrid.size() - 1;
        auto jMax = obstacleGrid[0].size() - 1;
        if (i == iMax &&
            j == jMax)
        {
            ++result;
            return;
        }

        if (i !=  iMax)
        {
            Cal(obstacleGrid, i + 1, j);
        }
        if (j != jMax)
        {
            Cal(obstacleGrid, i, j + 1);
        }
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //Cal(obstacleGrid, 0, 0);
        //return result;
        if (obstacleGrid.empty() || obstacleGrid[0].empty())
        {
            return 0;
        }

        vector<vector<int64_t>> results(obstacleGrid.size(), vector<int64_t>(obstacleGrid[0].size(), 0));
        if (obstacleGrid[0][0])
        {
            return 0;
        }
        results[0][0] = 1;
        int i, j;
        for (i = 0; i < obstacleGrid.size(); ++i)
        {
            auto& row = obstacleGrid[i];
            for (j = 0; j < row.size(); ++j)
            {
                if (0 == row[j])
                {
                    results[i][j] += (0 <= j - 1 ? results[i][j - 1] : 0);
                    results[i][j] += (0 <= i - 1 ? results[i - 1][j] : 0);
                }
            }
        }
        return results[i - 1][j - 1];
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> inputs{ {0,0,0}, {0,1,0}, {0,0,0} };
    std::cout << solution.uniquePathsWithObstacles(inputs) << std::endl;
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
