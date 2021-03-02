#include <vector>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
 
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
  
class Solution {
    TreeNode* createTree(vector<int>& nums)
    {
        if (nums.empty())
        {
            return NULL;
        }
        auto pos = nums.size() / 2;
        auto numsL = vector<int>(nums.begin(), nums.begin() + pos);
        auto numsR = vector<int>(nums.begin() + pos + 1, nums.end());
        return new TreeNode(nums[pos], createTree(numsL), createTree(numsR));
    }
    void toVector(ListNode* src, vector<int>& dst)
    {
        while (src != NULL)
        {
            dst.push_back(src->val);
            src = src->next;
        }
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        toVector(head, nums);
        return createTree(nums);
    }
};
int main()
{
    std::cout << "Hello World!\n";
}