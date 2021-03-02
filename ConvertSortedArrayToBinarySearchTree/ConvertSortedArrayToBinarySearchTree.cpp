// ConvertSortedArrayToBinarySearchTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    TreeNode* createTree(vector<int>& nums)
    {
        if (nums.empty())
        {
            return NULL;
        }
        auto pos = nums.size() / 2;
        auto numsL = vector<int>(nums.begin(), nums.begin() + pos);
        auto numsR = vector<int>(nums.begin() + pos + 1, nums.end());
        return new TreeNode(nums[pos], createTree(numsL), createTree(numsR));
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createTree(nums);
    }
};
int main()
{
    std::cout << "Hello World!\n";
}