// BinaryTreeZigzagLevelOrderTraversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    void myZigzag(TreeNode* root, int level)
    {
        if (NULL == root)
        {
            return;
        }

        while (results.size() <= level) results.push_back(vector<int>{});

        if (level % 2)
        {
            results[level].insert(results[level].begin(), root->val);
        }
        else
        {
            results[level].push_back(root->val);
        }
        ++level;
        myZigzag(root->left, level);
        myZigzag(root->right, level);
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        myZigzag(root, 0);
        return results;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}