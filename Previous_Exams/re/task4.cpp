#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

int main() 
{
    
    int N = 0;
    std::cin >> N;

    std::vector<int> array(N);
    for (int i = 0; i < N; i++) std::cin >> array[i];

    int result = 1;
    std::unordered_map<int, int> counter;
    std::vector<int> dp(N, 0);

    counter[array[0]] = 0;
    dp[0] = 1;

    for (int i = 1; i < N; i++)
    {

        if (counter.find(array[i]) == counter.end() ||
            counter[array[i]] < i - dp[i - 1])
        {

            dp[i] = dp[i - 1] + 1;

        }
        else
        {

            dp[i] = i - counter[array[i]];

        }

        counter[array[i]] = i;
        result = std::max(result, dp[i]);

    }

    std::cout << result;

    return 0;

}
