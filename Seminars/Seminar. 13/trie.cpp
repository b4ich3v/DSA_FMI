#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

struct TrieNode
{

    std::unordered_map<char, TrieNode*> children;
    bool isEnd = false;

};

class Trie 
{

    TrieNode* root;

public:

    Trie() 
    {

        root = new TrieNode();

    }

    void insert(std::string word)
    {

        TrieNode* iter = root;

        for (int i = 0; i < word.size(); i++)
        {

            if (!iter->children.count(word[i]))  iter->children[word[i]] = new TrieNode();
            iter = iter->children[word[i]];

        }

        iter->isEnd = true;

    }

    bool search(std::string word) 
    {

        TrieNode* iter = root;

        for (int i = 0; i < word.size(); i++)
        {

            if (!iter->children.count(word[i])) return false;
            iter = iter->children[word[i]];

        }

        return iter->isEnd;

    }

    bool startsWith(std::string prefix) 
    {

        TrieNode* iter = root;

        for (int i = 0; i < prefix.size(); i++) 
        {

            if (!iter->children.count(prefix[i])) return false;
            iter = iter->children[prefix[i]];

        }

        return true;

    }

};

