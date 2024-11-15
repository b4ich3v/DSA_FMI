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

    void reversedInorder(TreeNode* node, int& sum)
    {

        if (!node) return;

        reversedInorder(node->right, sum);
        sum += node->val;
        node->val = sum;
        reversedInorder(node->left, sum);

    }

    TreeNode* convertBST(TreeNode* root)
    {

        if (!root) return nullptr;

        int totalSum = 0;
        TreeNode* current = root;

        reversedInorder(root, totalSum);

        return root;

    }

};


