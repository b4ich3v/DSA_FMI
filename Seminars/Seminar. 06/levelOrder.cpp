#include <vector>

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

    void travel(TreeNode* node, std::vector<int>& v)
    {

        if(!node) return;

        v.push_back(node->val);

        travel(node->left, v);
        travel(node->right, v);

    }

    std::vector<int> preorderTraversal(TreeNode* root) 
    {

        std::vector<int> result;
        travel(root, result);

        return result;

    }

};
