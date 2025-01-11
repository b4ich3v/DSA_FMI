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

    void pushFunc(TreeNode* node, std::vector<int>& arr)
    {

        if (!node) return;

        arr.push_back(node->val);
        pushFunc(node->left, arr);
        pushFunc(node->right, arr);

    }

    std::vector<int> preorderTraversal(TreeNode* root)
    {

        std::vector<int> result;

        pushFunc(root, result);
        return result;

    }

};
