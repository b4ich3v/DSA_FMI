#include <vector>
#include <iostream>
#include <queue>

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

    bool helperBST(TreeNode* node, long  min, long  max)
    {

        if (!node) return true;
        if (node->val <= min || node->val >= max) return false;

        return helperBST(node->left, min, node->val) && helperBST(node->right, node->val, max);

    }

    bool isValidBST(TreeNode* root) 
    {

        return helperBST(root, LONG_MIN, LONG_MAX);

    }

};
