#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

bool pred(const std::pair<int, int>& p1, const std::pair<int, int>& p2) 
{

    if (p1.first == p2.first) return p1.second < p2.second;
    return p1.first < p2.first;

}

int main()
{

    long long N = 0;
    std::cin >> N;

    std::vector<std::pair<long long, long long>> intervals(N);
    for (long long i = 0; i < N; i++)
    {

        long long start = 0;
        long long end = 0;
        std::cin >> start >> end;
        intervals[i] = { start, end };

    }

    std::sort(intervals.begin(), intervals.end(), pred);

    long long result = 1;
    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> minHeap;
    minHeap.push(intervals[0].second);

    for (long long i = 1; i < N; i++)
    {

        while (!minHeap.empty() && intervals[i].first >= minHeap.top()) minHeap.pop();
        minHeap.push(intervals[i].second);
        result = std::max(result, (long long)minHeap.size());

    }

    std::cout << result;
    return 0;

}


