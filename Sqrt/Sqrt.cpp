// Sqrt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        if (1 >= x)
        {
            return x;
        }

        int H = x, L = 1;
        while (H - L > 1)
        {
            const auto M2 = int64_t(H) + L;
            const auto M = M2 % 2 ? M2 / 2 + 1 : M2 / 2;
            const auto P2 = pow(M, 2);
            if (P2 == x)
            {
                return M;
            }
            if (P2 >= x)
            {
                H = M;
            }
            else
            {
                L = (M == L ? M + 1 : M);
            }
            //std::cout << H << " : " << L << std::endl;
        }
        return L;
    }
};


int main()
{
    Solution solution;
    solution.mySqrt(183692038);
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
