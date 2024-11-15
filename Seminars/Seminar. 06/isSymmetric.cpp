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

    bool isMinor(TreeNode* left, TreeNode* right)
    {

        if (!left && !right) return true;
        if (!left || !right) return false;
        if (left->val != right->val) return false;

        return isMinor(left->left, right->right) && isMinor(left->right, right->left);

    }

    bool isSymmetric(TreeNode* root) 
    {

        if (!root) return true;
        return isMinor(root->left, root->right);

    }

};
