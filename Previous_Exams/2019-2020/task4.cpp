#include <cmath>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

struct Node
{

    Node* left;
    Node* right;
    int value;

    Node(int value) 
    {

        this->value = value;
        this->left = NULL;
        this->right = NULL;

    }

};

class BST 
{
public:

    BST() 
    {

        root = NULL;

    }

    void insert(int value)
    {

        root = insert(root, value);

    }

    void printLeftProfile() 
    {

        if (root == nullptr) return;

        std::queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) 
        {

            int size = q.size();

            for (int i = 0; i < size; i++)
            {

                const auto current = q.front();
                q.pop();

                if (i == 0) std::cout << current->value << " ";
                     
                if (current->left != nullptr) q.push(current->left);
                if (current->right != nullptr) q.push(current->right);

            }

        }

    }

private:

    Node* root;

    Node* insert(Node* curNode, int value) 
    {

        if (curNode == NULL) 
        {

            curNode = new Node(value);

        }
        else if (curNode->value < value) 
        {

            curNode->right = insert(curNode->right, value);

        }
        else if (curNode->value > value) 
        {

            curNode->left = insert(curNode->left, value);

        }
        else 
        {

            //if we already have this value at the tree - do nothing

        }

        return curNode;

    }

};

int main() 
{

    int n;
    std::cin >> n;
    int value;
    BST tree;

    for (int i = 0; i < n; i++) 
    {

        std::cin >> value;
        tree.insert(value);

    }

    tree.printLeftProfile();
    return 0;

}
