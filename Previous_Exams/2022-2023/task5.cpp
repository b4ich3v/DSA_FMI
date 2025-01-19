#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <set>

int maxTime = -1;

std::unordered_map<int, int> bestSeller;
std::unordered_map<int, int> countOfPurchases;
std::set<int> times;

struct Node 
{
public:

    int id;
    int time;

};

int main() 
{

    int N = 0;
    std::cin >> N;
    
    std::queue<Node> q;

    for (int i = 0; i < N; i++)
    {

        int idInput = 0;
        int timeInput = 0;
        std::cin >> idInput >> timeInput;

        q.push({ idInput, timeInput });
        times.insert(timeInput);
        maxTime = std::max(maxTime, timeInput);

    }

    long long maxPair = 0;
    long long maxId = -1;

    while (!q.empty())
    {

        int currId = q.front().id;
        countOfPurchases[currId] += 1;

        if (countOfPurchases[currId] >= maxPair)
        {

            maxPair = countOfPurchases[currId];
            maxId = currId;

        }

        bestSeller[q.front().time] = maxId;
        q.pop();
    }

    int T;
    std::cin >> T;

    for (int i = 0; i < T; ++i)
    {

        int time;
        std::cin >> time;

        if (time >= maxTime)
        {

            std::cout << bestSeller[maxTime] << std::endl;
            continue;

        }

        auto temp = times.lower_bound(time);

        if (time < *temp)
        {

            if (temp == times.begin())
            {

                std::cout << -1 << std::endl;
                continue;

            }

            time = *(--temp);

        }
        else
        {

            time = *temp;

        }

        std::cout << bestSeller[time] << std::endl;

    }

    return 0;

}
