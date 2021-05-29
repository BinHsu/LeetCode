// PathSum2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
    vector<vector<int>> results;
    void hasPathSum(TreeNode* root, int targetSum, vector<int> result) {
        if (root == NULL)
        {
            return;
        }
        result.push_back(root->val);
        int sum = targetSum - root->val;
        if (NULL == root->left && NULL == root->right)
        {
            if (0 == sum)
            {
                results.push_back(result);
            }
            return;
        }

        hasPathSum(root->left, sum, result);
        hasPathSum(root->right, sum, result);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> result;
        hasPathSum(root, targetSum, result);
        return results;
    }
};
int main()
{
    std::cout << "Hello World!\n";
}