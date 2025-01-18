#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iostream>
#include <climits>
#include <algorithm>

struct Tree
{
public:

    int value;
    Tree* left;
    Tree* right;

    Tree(int number) : value(number), left(nullptr), right(nullptr) {}

};

Tree* add(Tree* root, int number) 
{
    
    if (root == nullptr) return new Tree(number);
    if (root->value > number) root->left = add(root->left, number);
    else if (root->value < number) root->right = add(root->right, number);
    else return root;

    return root;

}

void print(Tree* root) 
{

    if (root == nullptr) return;

    std::cout << root->value << " ";
    print(root->left);
    print(root->right);

}

int main()
{

    int N = 0;
    std::cin >> N;
    std::cin.ignore();

    Tree* root = nullptr;

    for (int i = 0; i < N; i++)
    {

        std::string operation;
        std::getline(std::cin, operation);

        if (operation.empty())
            continue;

        if (operation.size() >= 3 && operation.substr(0, 3) == "add") 
        {

            int position = operation.find(' ');

            if (position != std::string::npos) 
            {
  
                std::string numberStr = operation.substr(position + 1);
                int number = std::stoi(numberStr);
                root = add(root, number);

            }

        }
        else if (operation == "print")  print(root);

    }

    return 0;

}


