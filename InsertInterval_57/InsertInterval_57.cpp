// InsertInterval_57.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty())
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        vector<vector<int>> results;
        bool bInserted(false);
        for (auto it = intervals.begin(); it != intervals.end(); ++it)
        {
            if (!bInserted)
            {
                if (newInterval.back() < it->front())
                {
                    results.push_back(newInterval);
                    bInserted = true;
                    results.insert(results.end(), it, intervals.end());
                    break;
                }

                if (it->front() <= newInterval.back() && it->back() >= newInterval.front())
                {
                    if (it->front() <= newInterval.front() &&
                        it->back() >= newInterval.back())
                    {
                        bInserted = true;
                        results.insert(results.end(), it, intervals.end());
                        break;
                    }
                    if (newInterval.front() < it->front())
                    {
                        bInserted = true;
                        it->front() = newInterval.front();
                        results.push_back(*it);
                        newInterval = *it;
                    }
                    if (newInterval.back() > it->back())
                    {
                        bInserted = true;
                        it->back() = newInterval.back();
                        results.push_back(*it);
                        newInterval = *it;
                    }
                }
            }
            else
            {
                if (it->front() > newInterval.back())
                {
                    results.insert(results.end(), it, intervals.end());
                    break;
                }

                if (it->front() <= newInterval.back() && it->back() >= newInterval.front())
                {

                }

            }
            
        }
        std::cout << bInserted << std::endl;
        for (const auto interval : intervals)
        {
            std::cout << "[" << interval.front() << "," << interval.back() << "]" << std::endl;
        }
        /*if (!bInserted)
        {
            for (auto it = intervals.begin(); it != intervals.end(); ++it)
            {
                if (it->front() > newInterval.front())
                {
                    std::cout << "it->front() > newInterval.front()" <<std::endl;
                    intervals.insert(it, newInterval);
                    bInserted = true;
                    break;
                }
            }
            if (!bInserted)
            {
                intervals.push_back(newInterval);
            }
            return intervals;
        }


        for (auto it = intervals.begin(); it != intervals.end();)
        {
            auto itTmp = it;
            if (++itTmp != intervals.end())
            {
                if (it->back() >= itTmp->front())
                {
                    it->back() = itTmp->back();
                    intervals.erase(itTmp);
                    continue;
                }
                ++it;
            }
            else
            {
                break;
            }
        }*/
        return results;
    }
};

int main()
{
    std::cout << "Hello World!\n";
    Solution solution;
    std::vector<std::vector<int>> intervals{ {1, 2}, { 3, 4 }, { 5, 6 }};
    std::vector<int> newInterval{0, 2000};
    auto results = solution.insert(intervals, newInterval);
    for (const auto result : results)
    {
        std::cout << "[" << result.front() << "," << result.back() << "]" << std::endl;
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
