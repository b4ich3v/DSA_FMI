#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>

class Solution 
{
public:

    std::vector<std::vector<int>> validArrangement(std::vector<std::vector<int>>& pairs)
    {

        std::unordered_map<int, std::vector<int>> graph;
        std::unordered_map<int, int> inDegree;
        std::unordered_map<int, int> outDegree;

        for (const auto& p : pairs) 
        {

            int start = p[0];
            int end = p[1];

            graph[start].push_back(end);
            outDegree[start]++;
            inDegree[end]++;
        
            if (!inDegree.count(start)) inDegree[start] = 0;
            if (!outDegree.count(end)) outDegree[end] = 0;

        }

        for (auto& entry : graph) std::sort(entry.second.begin(), entry.second.end());

        int startVertex = pairs[0][0]; 

        for (const auto& entry : outDegree) 
        {

            int v = entry.first;

            if (entry.second == inDegree[v] + 1) 
            {

                startVertex = v;
                break;

            }

        }

        std::stack<int> st;
        st.push(startVertex);
        std::vector<int> path;  

        while (!st.empty()) 
        {

            int current = st.top();

            if (!graph[current].empty()) 
            {

                int next = graph[current].back();
                graph[current].pop_back(); 
                st.push(next);

            }
            else 
            {

                path.push_back(current);
                st.pop();

            }

        }

        std::reverse(path.begin(), path.end());
        std::vector<std::vector<int>> answear;

        for (int i = 1; i < path.size(); i++) answear.push_back({ path[i - 1], path[i] });

        return answear;

    }

};
