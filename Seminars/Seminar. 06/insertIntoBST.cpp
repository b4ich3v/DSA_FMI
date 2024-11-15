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

    TreeNode* insertIntoBST(TreeNode* root, int val)
    {
        
        if (!root) return new TreeNode(val);

        TreeNode* current = root;

        while (true)
        {

            if (val < current->val)
            {
                
                if (!current->left)
                {

                    current->left = new TreeNode(val);
                    break;

                }
                else current = current->left;

            }
            else if (val > current->val)
            {
               
                if (!current->right)
                {

                    current->right = new TreeNode(val);
                    break;

                }
                else current = current->right;

            }

        }

        return root; 
       
    }

};
