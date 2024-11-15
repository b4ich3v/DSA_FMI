#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <set>

struct TreeNode
{

    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};

class Solution 
{
public:

    void inOrder(TreeNode* node, int& result, int low, int high)
    {

        if (!node) return;

        inOrder(node->left, result, low, high);
        if (node->val >= low && node->val <= high) result += node->val;
        inOrder(node->right, result, low, high);

    }

    int rangeSumBST(TreeNode* root, int low, int high) 
    {

        int result = 0;
        inOrder(root, result, low, high);

        return result;

    }

};
