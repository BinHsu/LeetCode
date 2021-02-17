// BinaryTreeLevelOrderTraversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    vector<vector<int>> results;
    void myTreeLevelOrderTraversal(TreeNode* root, int level)
    {
        if (NULL == root)
        {
            return;
        }
        while (results.size() <= level)
        {
            results.push_back(vector<int>{});
        }
        results[level].push_back(root->val);
        ++level;
        myTreeLevelOrderTraversal(root->left, level);
        myTreeLevelOrderTraversal(root->right, level);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        myTreeLevelOrderTraversal(root, 0);
        return results;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
