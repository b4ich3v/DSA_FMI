#include <cmath>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

bool pred(const std::pair<int, std::string>& p1, const std::pair<int, std::string>& p2)
{

    if(p1.first != p2.first) return p1.first < p2.first;
    return p1.second < p2.second;

}

class Solution 
{
public:

    std::vector<std::string> watchedVideosByFriends(std::vector<std::vector<std::string>>& watchedVideos, 
                                                    std::vector<std::vector<int>>& friends, int id, int level) 
    {

        int size = friends.size();
        int currentLevel = 0;

        std::unordered_set<int> visited;
        std::queue<int> q;
        q.push(id);
        visited.insert(id);

        while (!q.empty() && currentLevel < level) 
        {

            int currentSize = q.size();
            
            for (int i = 0; i < currentSize; i++)
            {

                const auto current = q.front();
                q.pop();

                for (const auto& child : friends[current])
                {

                    if (visited.find(child) == visited.end())
                    {

                        visited.insert(child);
                        q.push(child);

                    }

                }

            }

            currentLevel += 1;

        }

        if (currentLevel != level) return {};

        std::unordered_map<std::string, int> videoCount;

        while (!q.empty()) 
        {

            int friendId = q.front();
            q.pop();

            for (const auto& video : watchedVideos[friendId]) videoCount[video]++;

        }

        std::vector<std::pair<int, std::string>> sortedVideos;
        for (const auto& current : videoCount) sortedVideos.push_back({ current.second, current.first });

        sort(sortedVideos.begin(), sortedVideos.end(), pred);

        std::vector<std::string> result;
        for (const auto& p : sortedVideos) result.push_back(p.second);

        return result;

    }

};
