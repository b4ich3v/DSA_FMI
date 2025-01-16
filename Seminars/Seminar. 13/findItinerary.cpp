#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>

class Solution 
{
public:

    std::vector<std::string> findItinerary(std::vector<std::vector<std::string>>& tickets)
    {

        std::unordered_map<std::string, std::priority_queue<std::string, std::vector<std::string>, std::greater<std::string>>> graph;
        for (auto& ticket : tickets) graph[ticket[0]].push(ticket[1]);

        std::vector<std::string> result;
        std::stack<std::string> st;
        st.push("JFK");

        while (!st.empty()) 
        {

            std::string current = st.top();

            if (!graph[current].empty()) 
            {

                st.push(graph[current].top());
                graph[current].pop();

            }
            else 
            {

                result.push_back(st.top());
                st.pop();

            }

        }

        reverse(result.begin(), result.end());
        return result;

    }

};

