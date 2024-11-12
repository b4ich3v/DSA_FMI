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

    std::vector<std::vector<int>> levelOrder(TreeNode* root) 
    {

        std::vector<std::vector<int>>result;
        if (root == NULL)return result;

        std::queue<TreeNode*> q;

        q.push(root);
        while (!q.empty()) 
        {

            int size = q.size();
            std::vector<int>level;

            for (int i = 0;i < size;i++) 
            {

                TreeNode* node = q.front();
                q.pop();
                if (node->left != nullptr)q.push(node->left);
                if (node->right != nullptr)q.push(node->right);
                level.push_back(node->val);

            }

            result.push_back(level);

        }

        return result;

    }

};
