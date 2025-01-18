#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iostream>
#include <climits>
#include <algorithm>

bool pred(const std::string& str1, const std::string& str2) 
{

    return str1 < str2;

}

int main()
{

    std::string str1 = "";
    std::string str2 = "";

    std::getline(std::cin, str1);
    std::getline(std::cin, str2);

    std::vector<std::string> allWords;
    std::string currentWord;
    int prevIndex = 0;

    for (int i = 0; i < str1.size(); i++)
    {

        if (str1[i] == ' ') 
        {

            currentWord = str1.substr(prevIndex, i - prevIndex);
            allWords.push_back(currentWord);
            prevIndex = i + 1;

        }

    }

    if (prevIndex < str1.size()) 
    {

        currentWord = str1.substr(prevIndex);
        allWords.push_back(currentWord);

    }

    prevIndex = 0;

    for (int i = 0; i < str2.size(); i++)
    {

        if (str2[i] == ' ')
        {

            currentWord = str2.substr(prevIndex, i - prevIndex);
            allWords.push_back(currentWord);
            prevIndex = i + 1;

        }

    }

    if (prevIndex < str2.size()) 
    {

        currentWord = str2.substr(prevIndex);
        allWords.push_back(currentWord);

    }

    std::unordered_map<std::string, int> counter;

    for (const auto& current : allWords) counter[current] += 1;

    std::vector<std::string> result;

    for (const auto& current : counter)
    {

        if (current.second == 1) result.push_back(current.first);

    }

    std::sort(result.begin(), result.end(), pred);

    for (const auto& current : result) std::cout << current << std::endl;

    return 0;

}


