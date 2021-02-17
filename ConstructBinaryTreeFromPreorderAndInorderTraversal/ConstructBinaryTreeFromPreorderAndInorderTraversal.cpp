// ConstructBinaryTreeFromPreorderAndInorderTraversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
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
    TreeNode* results;
    void myBuildTree(TreeNode* root, vector<int>& preorder, vector<int>& inorder)
    {
        const auto val = preorder.front();
        root->val = val;
        const auto it = find(inorder.begin(), inorder.end(), val);
        auto inorderL = vector<int>(inorder.begin(), it);
        const auto inorderLSize = inorderL.size();
        std::cout << "inorderLSize" << inorderLSize << std::endl;
        if (inorderLSize)
        {
            auto preorderL = vector<int>(
                preorder.begin() + 1,
                preorder.begin() + 1 + inorderLSize);
            std::cout << "preorderLSize" << preorderL.size() << std::endl;
            root->left = new TreeNode();
            myBuildTree(root->left, preorderL, inorderL);
        }
        auto inorderR = vector<int>(it + 1, inorder.end());
        const auto inorderRSize = inorderR.size();
        std::cout << "inorderRSize" << inorderRSize << std::endl;
        if (inorderRSize)
        {
            auto preorderR = vector<int>(
                preorder.begin() + 1 + inorderLSize,
                preorder.begin() + 1 + inorderLSize + inorderRSize);
            std::cout << "preorderRSize" << preorderR.size() << std::endl;
            root->right = new TreeNode();
            myBuildTree(root->right, preorderR, inorderR);
        }
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty())
        {
            return results;
        }
        results = new TreeNode();
        myBuildTree(results, preorder, inorder);
        return results;
    }
};
int main()
{
    std::cout << "Hello World!\n";
}