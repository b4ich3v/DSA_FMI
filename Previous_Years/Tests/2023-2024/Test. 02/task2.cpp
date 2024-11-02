#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

int main() 
{

    int T = 0;
    std::cin >> T;

    for (int i = 0; i < T; i++)
    {

        int X = 0;
        std::cin >> X;

        int N = 0;
        std::cin >> N;

        std::vector<std::pair<int, int>> array(N);
        for (int i = 0; i < N; i++) { std::cin >> array[i].first; array[i].second = i; }
        std::sort(array.begin(), array.end());

        int startPtr = 0;
        int endPtr = N - 1;

        bool good = false;

        while (startPtr < endPtr)
        {

            if (array[startPtr].first + array[endPtr].first > X) endPtr--;
            else if (array[startPtr].first + array[endPtr].first < X) startPtr++;
            else { good = true; break; }

        }

        if (good)
        {

            int first = std::min(array[startPtr].second + 1, array[endPtr].second + 1);
            int second = std::max(array[startPtr].second + 1, array[endPtr].second + 1);

            std::cout << first << " " << second;

        }

        std::cout << std::endl;

    }

    return 0;

}
