#include <iostream>
#include <string>
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

    if (root == nullptr)  return new Tree(number);

    if (number < root->value)  root->left = add(root->left, number);
    else if (number > root->value) root->right = add(root->right, number);
    else return root;

    return root;

}

Tree* findMin(Tree* root) 
{

    while (root && root->left != nullptr)  root = root->left;
    return root;

}

Tree* remove(Tree* root, int number) 
{

    if (root == nullptr)  return root;
       

    if (number < root->value) root->left = remove(root->left, number);
    else if (number > root->value) root->right = remove(root->right, number);
    else 
    {

        if (root->left == nullptr && root->right == nullptr) 
        {

            delete root;
            return nullptr;

        }
        else if (root->left == nullptr)
        {

            Tree* temp = root->right;
            delete root;
            return temp;

        }
        else if (root->right == nullptr) 
        {

            Tree* temp = root->left;
            delete root;
            return temp;

        }
        else
        {

            Tree* temp = findMin(root->right);
            root->value = temp->value;
            root->right = remove(root->right, temp->value);

        }

    }

    return root;

}

void print(Tree* root) 
{

    if (root == nullptr)  return;
       
    std::cout << root->value << " ";
    print(root->left);
    print(root->right);

}

void printOddLayers(Tree* root, int level)
{

    if (root == nullptr)  return;
       
    if (level % 2 == 1) std::cout << root->value << " ";
    printOddLayers(root->left, level + 1);
    printOddLayers(root->right, level + 1);

}

void print_odd_layers(Tree* root) 
{

    printOddLayers(root, 1);

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
        else if (operation.size() >= 6 && operation.substr(0, 6) == "remove")
        {

            int position = operation.find(' ');

            if (position != std::string::npos)
            {

                std::string numberStr = operation.substr(position + 1);
                int number = std::stoi(numberStr);
                root = remove(root, number);

            }

        }
        else if (operation == "print_odd_layers") print_odd_layers(root);
        else if (operation == "print") print(root);

    }

    return 0;

}
