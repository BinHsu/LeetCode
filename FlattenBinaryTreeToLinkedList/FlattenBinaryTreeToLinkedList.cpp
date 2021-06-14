// FlattenBinaryTreeToLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    vector<TreeNode*> tmp;
    void flatRead(TreeNode* root) {
        if (NULL == root)
        {
            return;
        }
        tmp.push_back(root);
        flatRead(root->left);
        flatRead(root->right);
    }
public:
    void flatten(TreeNode* root) {
        flatRead(root);
        for (int i = 0; i < tmp.size(); ++i)
        {
            if (i != tmp.size() - 1)
            {
                tmp[i]->right = tmp[i + 1];
                tmp[i]->left = NULL;
            }
            else
            {
                tmp[i]->right = NULL;
                tmp[i]->left = NULL;
            }
        }
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
