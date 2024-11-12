#include <vector>
#include <iostream>

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

   

    void pushingElements(TreeNode* root, std::vector<int>& result)
    {

        if (!root) return;

        result.push_back(root->val);

        pushingElements(root->left, result);
        pushingElements(root->right, result);

    }

    std::vector<int> preorderTraversal(TreeNode* root)
    {

        std::vector<int> result;
        pushingElements(root, result);

        return result;

    }

};
