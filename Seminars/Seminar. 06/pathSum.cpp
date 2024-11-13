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

    int pathSum(TreeNode* root, long long targetSum)
    {

        if (!root) return 0;

        long long pathsFromRoot = countPaths(root, targetSum);
        long long pathsInLeftSubtree = pathSum(root->left, targetSum);
        long long pathsInRightSubtree = pathSum(root->right, targetSum);

        return pathsFromRoot + pathsInLeftSubtree + pathsInRightSubtree;

    }

    int countPaths(TreeNode* node, long long targetSum)
    {

        if (!node) return 0;

        long long pathCount = (node->val == targetSum) ? 1 : 0;

        pathCount += countPaths(node->left, targetSum - node->val);
        pathCount += countPaths(node->right, targetSum - node->val);

        return pathCount;

    }
    
};
