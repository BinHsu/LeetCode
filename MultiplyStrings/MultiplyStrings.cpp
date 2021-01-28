#include <iostream>
#include <vector>
using namespace std;
class Solution {

    int ctoi(const char src)
    {
        return src - '0';
    }

    char itoc(const int src)
    {
        return '0' + src;
    }

    unsigned long long stoi(const std::string& src)
    {
        unsigned long long result = 0;
        for (const auto srcC : src)
        {
            result = result * 10 + ctoi(srcC);
        }


        return result;
    }
public:

    string multiply(string num1, string num2) {
        std::string& top(num1), down(num2);
        if (num1.length() < num2.length())
        {
            top.swap(down);
        }
        std::vector<std::vector<int>> results;
        for (int i = down.length() - 1, j = 0; i >= 0; --i, ++j)
        {
            std::vector<int> result;
            for (int k = 0; k <= j; ++k)
            {
                result.push_back(0);
            }
            for (int l = top.length() - 1; l >= 0; --l)
            {
                const auto downNum = ctoi(down[i]);
                const auto topNum = ctoi(top[l]);
                std::cout << downNum << "*" << topNum << "+" << result.back() << std::endl;
                const auto answer = downNum * topNum + result.back();
                result.back() = answer % 10;
                result.push_back(answer / 10);
            }
            if (result.back() == 0)
            {
                result.pop_back();
            }
            results.push_back(result);
        }

        std::vector<int> resultFinal;
        resultFinal.push_back(0);
        for (int i = 0; i < results.back().size(); ++i)
        {
            int sum = 0;
            for (const auto& result : results)
            {
                if (result.size() > i)
                {
                    std::cout << i << ":" << result[i] << std::endl;
                    sum += result[i];
                }
            }
            std::cout << i << ":" << resultFinal.back() << std::endl;
            sum += resultFinal.back();
            resultFinal.back() = sum % 10;
            resultFinal.push_back(sum / 10);
        }
        if (resultFinal.back() == 0)
        {
            resultFinal.pop_back();
        }
        while (resultFinal.back() > 9)
        {
            auto tmp = resultFinal.back();
            resultFinal.back() = tmp % 10;
            resultFinal.push_back(tmp / 10);
        }
        
        std::string resultStr;
        for (auto it = resultFinal.rbegin(); it != resultFinal.rend(); ++it)
        {
            resultStr.push_back(itoc(*it));
        }
        
        return resultStr;
    }
};

int main()
{
    Solution solution;
    std::cout << solution.multiply("9", "99") << std::endl;
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
