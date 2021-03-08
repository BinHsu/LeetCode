// BalancedBinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
    int getNullLevel(TreeNode* root, int level)
    {
        if (NULL == root)
        {
            return level;
        }
        const auto leftNull = getNullLevel(root->left, level + 1);
        const auto rightNull = getNullLevel(root->right, level + 1);
        if (abs(leftNull - rightNull) > 1)
        {
            throw std::runtime_error("Gatcho");
        }
        return std::max(leftNull, rightNull);
    }
public:
    bool isBalanced(TreeNode* root) {
        try
        {
            getNullLevel(root, 0);
        }
        catch (std::exception)
        {
            return false;
        }
        return true;
    }
};
int main()
{
    std::cout << "Hello World!\n";
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
