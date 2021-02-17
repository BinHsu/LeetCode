// RecoverBinarySearchTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <algorithm>
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

    list<int> results_;
    void visit(TreeNode* root)
    {
        if (root == NULL)
        {
            return;
        }

        visit(root->left);
        results_.push_back(root->val);
        visit(root->right);
    }

    void revisit(TreeNode* root)
    {
        if (root == NULL)
        {
            return;
        }

        revisit(root->left);
        const auto node = results_.front();
        results_.pop_front();
        root->val = node;
        revisit(root->right);
    }

    void recover(TreeNode* root)
    {
        visit(root);
        results_.sort();
        revisit(root);
    }

public:
    void recoverTree(TreeNode* root) {
        if (!root)
        {
            return;
        }
        return recover(root);
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
