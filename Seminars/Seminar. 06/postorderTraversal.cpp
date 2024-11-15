class Solution
{
public:
        
    void pushFunc(TreeNode* node, std::vector<int>& arr) 
    {

        if (!node) return;

        pushFunc(node->left, arr);
        pushFunc(node->right, arr);
        arr.push_back(node->val);

    }

    std::vector<int> postorderTraversal(TreeNode* root)
    {

        std::vector<int> result;

        pushFunc(root, result);
        return result;

    }

};
