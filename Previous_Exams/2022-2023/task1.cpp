#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

int main() 
{
   
    int N = 0;
    std::cin >> N;

    std::vector<int> stickersContainer;
    std::vector<int> wantedStickers;
    std::unordered_map<int, int> s;

    for (int i = 0; i < N; i++)
    {

        int sticker = 0;
        std::cin >> sticker;
        stickersContainer.push_back(sticker);

    }

    for (int i = 0; i < N; i++)
    {

        int sticker = 0;
        std::cin >> sticker;
        wantedStickers.push_back(sticker);

    }

    int counter = 0;

    for (int i = 0; i < N; i++)
    {

        s[stickersContainer[i]] += 1;
        if (s[wantedStickers[i]] <= 0) counter += 1;
        else s[wantedStickers[i]] -= 1;

    }

    std::cout << counter;

    return 0;
}
