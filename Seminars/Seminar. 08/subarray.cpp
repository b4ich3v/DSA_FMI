#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

int main() 
{
    
    int N = 0;
    std::cin >> N;

    std::vector<int> arr(N);
    for (int i = 0; i < N; i++) std::cin >> arr[i];
    
    for (int i = 0; i < N; i++)
    {

        if (arr[i] == 0) arr[i] = -1;

    }

    int prefSum = 0;
    int result = 0;
    std::unordered_map<int, int> mp;

    for (int i = 0; i < N; i++) 
    {                          

        prefSum += arr[i];

        if (mp.find(prefSum) != mp.end()) result = std::max(result, i - mp[prefSum]);
        else mp[prefSum] = i;

    }

    std::cout << result;
    return 0;

}
