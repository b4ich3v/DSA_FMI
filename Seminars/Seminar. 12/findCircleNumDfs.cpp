#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

class Solution 
{
public:

    void dfs(int current, std::unordered_set<int>& visited, std::unordered_map<int, std::unordered_set<int>>& graph) 
    {

        visited.insert(current);

        for (const auto& child : graph[current])
        {

            if (visited.find(child) == visited.end())
            {

                dfs(child, visited, graph);

            }

        }

    }

    int findCircleNum(std::vector<std::vector<int>>& isConnected)
    {

        std::unordered_map<int, std::unordered_set<int>> graph;
        int countOfNodes = isConnected.size();

        for (int i = 0; i < countOfNodes; i++)
        {

            for (int j = 0; j < countOfNodes; j++)
            {

                if (isConnected[i][j] == 1)
                {

                    graph[i].insert(j);
                    graph[j].insert(i);

                }
                
            }

        }

        int result = 0;
        std::unordered_set<int> visited;

        for (const auto& current : graph) 
        {

            if (visited.find(current.first) != visited.end()) continue;
            dfs(current.first, visited, graph);
            result += 1;

        }

        return result;

    }

};
