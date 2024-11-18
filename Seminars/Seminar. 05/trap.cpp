#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <map>

class Solution 
{
public:

    int trap(std::vector<int>& h) 
    {

        std::deque<std::pair<int,int>> blocks;
        int result = 0;

        for (int i = 0; i < h.size(); i++)
        {

            while (!blocks.empty() && blocks.back().first < h[i]) 
            {

                std::pair<int, int > currentBlock = blocks.back();
                blocks.pop_back();

                if (blocks.empty()) continue;

                int countOfBlocks = std::min(h[i], blocks.front().first) - currentBlock.first;
                int interval = currentBlock.second - blocks.back().second;
                result += interval * countOfBlocks;

            }

            blocks.push_back({ h[i], i });

        }

        return result;

    }

};

