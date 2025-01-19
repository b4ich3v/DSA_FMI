#include <cmath>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

bool solve()
{

    std::string str = "";
    std::cin >> str;

    std::unordered_map<char, int> counter;
    for (const auto& current : str) counter[current] += 1;

    std::vector<int> numbers;
    for (const auto& current : counter) numbers.push_back(current.second);

    int maxElement = *std::max_element(numbers.begin(), numbers.end());
    int countOfLess = 0;
    int isThereOne = 0;

    int currentIndex = 0;
    int lastSeenIndex = 0;

    for (const auto& current : numbers)
    {

        if (current + 1 == maxElement) countOfLess += 1;
        if (current == 1) 
        {

            isThereOne += 1;
            lastSeenIndex = currentIndex;

        }

        currentIndex += 1;

    }

    currentIndex = 0;

    if (isThereOne == 1) 
    {

        for (const auto& current : numbers)
        {

            if (currentIndex == lastSeenIndex)
            {

                currentIndex += 1;
                continue;

            }
            if (current != maxElement) return false;
            currentIndex += 1;

        }

        return true;

    }

    return countOfLess == numbers.size() - 1;

}

int main()
{

    int N = 0;
    std::cin >> N;

    for (int i = 0; i < N; i++)
    {

        std::cout << solve() << std::endl;

    }

    return 0;

}
