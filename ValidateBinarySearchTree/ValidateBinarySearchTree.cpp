// ValidateBinarySearchTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>

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
    bool myValidBST(TreeNode* root, list<int> roots)
    {
        if (root == NULL)
        {
            std::cout << "root is null" << std::endl;
        }
        else
        {
            std::cout << "root: " << root->val << std::endl;
            if (root->left == NULL)
            {
                std::cout << "left is null" << std::endl;
            }
            else
            {
                std::cout << "left: " << root->left->val << std::endl;
            }
            if (root->right == NULL)
            {
                std::cout << "right is null" << std::endl;
            }
            else
            {
                std::cout << "right: " << root->right->val << std::endl;
            }
        }
        if (root == NULL)
        {
            return true;
        }
        if (root->left && root->left->val >= root->val)
        {
            return false;
        }
        if (root->right && root->right->val <= root->val)
        {
            return false;
        }
        //roots.push
        return myValidBST(root->left, roots) && myValidBST(root->right, roots);
    }

    std::list<int> results_;

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

    bool isValid(TreeNode* root)
    {
        visit(root);

        auto latest = int64_t(results_.front()) - 1;
        for (const auto result : results_)
        {
            if (result <= latest)
            {
                return false;
            }
            latest = result;
        }
        return true;
    }

public:
    bool isValidBST(TreeNode* root) {
        if (!root)
        {
            return true;
        }
        return isValid(root);
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
