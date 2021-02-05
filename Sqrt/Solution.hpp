#pragma once
using namespace std;
namespace MySqrt {
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
};