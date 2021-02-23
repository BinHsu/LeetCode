// ConstructBinaryTreeFromInorderAndPostorderTraversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    TreeNode* results;
    void myBuildTree(TreeNode* root, vector<int>& inorder, vector<int>& postorder)
    {
        const auto val = postorder.back();
        root->val = val;
        const auto it = find(inorder.begin(), inorder.end(), val);
        auto inorderL = vector<int>(inorder.begin(), it);
        const auto inorderLSize = inorderL.size();
        //std::cout << "inorderLSize" << inorderLSize << std::endl;
        if (inorderLSize)
        {
            auto postorderL = vector<int>(
                postorder.begin(),
                postorder.begin() + inorderLSize);
            std::cout << "postorderLSize" << postorderL.size() << std::endl;
            root->left = new TreeNode();
            myBuildTree(root->left, inorderL, postorderL);
        }
        auto inorderR = vector<int>(it + 1, inorder.end());
        const auto inorderRSize = inorderR.size();
        std::cout << "inorderRSize" << inorderRSize << std::endl;
        if (inorderRSize)
        {
            auto postorderR = vector<int>(
                postorder.begin() + inorderLSize,
                postorder.begin() + inorderLSize + inorderRSize);
            //std::cout << "postorderRSize" << postorderR.size() << std::endl;
            root->right = new TreeNode();
            myBuildTree(root->right, inorderR, postorderR);
        }
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty())
        {
            return results;
        }
        results = new TreeNode();
        myBuildTree(results, inorder, postorder);
        return results;
    }
};
int main()
{
    std::cout << "Hello World!\n";
}