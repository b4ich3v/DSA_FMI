#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

class Node 
{
public:

    int val;
    std::vector<Node*> neighbors;

    Node() 
    {

        val = 0;
        neighbors = std::vector<Node*>();

    }
    Node(int _val) 
    {

        val = _val;
        neighbors = std::vector<Node*>();

    }
    Node(int _val, std::vector<Node*> _neighbors) 
    {

        val = _val;
        neighbors = _neighbors;

    }

};

class Solution 
{
private:

    std::unordered_map<Node*, Node*> relation;

public:

    Node* cloneGraph(Node* node) 
    {

        if (node == nullptr) return nullptr;

        const auto& iter = relation.find(node);

        if (iter != relation.end()) return iter->second;

        Node* newNode = new Node(node->val);
        relation[node] = newNode;

        for (const auto& child : node->neighbors) 
        {

            newNode->neighbors.push_back(cloneGraph(child));

        }

        return newNode;

    }

};
