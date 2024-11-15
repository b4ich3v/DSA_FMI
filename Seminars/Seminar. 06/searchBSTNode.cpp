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

    TreeNode* searchBST(TreeNode* root, int val) 
    {

        TreeNode* current = root;

        while (current) 
        {

            if (current->val == val) return current;
            else if (current->val > val) current = current->left;
            else if (current->val < val) current = current->right;

        }

        return nullptr;

    }

};
