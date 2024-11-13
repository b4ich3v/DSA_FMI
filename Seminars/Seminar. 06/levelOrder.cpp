#include <vector>
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

        std::vector<std::vector<int>> result;
        std::queue<TreeNode*> q;

        if (!root) return result;

        q.push(root);

        while (!q.empty())
        {

            int size = q.size();
            std::vector<int> currentLevel;

            for (int i = 0; i < size; i++)
            {

                TreeNode* currentNode = q.front();
                q.pop();

                if (currentNode->left != nullptr) q.push(currentNode->left);
                if (currentNode->right != nullptr) q.push(currentNode->right);

                currentLevel.push_back(currentNode->val);

            }

            result.push_back(currentLevel);

        }

        return result;

    }

};
