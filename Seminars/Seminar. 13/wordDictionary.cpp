#include <cmath>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

struct TrieNode 
{

    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord = false;

};

class WordDictionary 
{
private:

    TrieNode* root;

public:

    WordDictionary() : root(new TrieNode()) {}

    void addWord(std::string word)
    {

        TrieNode* iter = root;

        for (char ch : word) 
        {

            if (!iter->children.count(ch)) iter->children[ch] = new TrieNode();
            iter = iter->children[ch];

        }

        iter->isEndOfWord = true;

    }

    bool searchUtil(std::string word, TrieNode* root)
    {

        TrieNode* iter = root;

        for (int i = 0; i < word.length(); i++) 
        {

            if (word[i] == '.') 
            {

                for (auto& kvp : iter->children) 
                {

                    if (searchUtil(word.substr(i + 1), kvp.second)) return true;

                }

                return false;

            }

            if (!iter->children.count(word[i])) return false;
            iter = iter->children[word[i]];

        }

        return iter->isEndOfWord;

    }

    bool search(std::string word)
    {

        return searchUtil(word, root);

    }

};
