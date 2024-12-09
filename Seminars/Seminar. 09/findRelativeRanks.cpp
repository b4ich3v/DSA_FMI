#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>

struct comparator 
{

    bool operator()(const std::pair<int, int>& p1, const std::pair<int, int>& p2) 
    {

        return p1.second < p2.second;

    }

};

class Solution 
{
public:

    std::vector<std::string> findRelativeRanks(std::vector<int>& score) 
    {

        std::priority_queue < std::pair<int, int>, std::vector<std::pair<int, int>>, comparator> q;
        std::vector<std::string> result(score.size());
        for (int i = 0; i < score.size(); i++) q.push({ i, score[i] });
       
        if (!q.empty()) { result[q.top().first] = "Gold Medal"; q.pop(); }
        if (!q.empty()) { result[q.top().first] = "Silver Medal"; q.pop(); }
        if (!q.empty()) { result[q.top().first] = "Bronze Medal"; q.pop(); }

        int rank = 4;

        while (!q.empty())
        {

            std::pair<int, int> current = q.top();
            result[current.first] = std::to_string(rank);
            rank += 1;
            q.pop();

        }

        return result;

    }

};


