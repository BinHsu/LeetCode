// ConstructBinaryTreeFromInorderAndPostorderTraversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
        {
            return false;
        }

        int sum = targetSum - root->val;
        if (NULL == root->left && NULL == root->right)
        {
            if (0 == sum)
            {
                return true;
            }
            return false;
        }

        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};
int main()
{
    std::cout << "Hello World!\n";
}