#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    scanf("%d %d", &t, &n);

    list<int> cache;
    vector<bool> isInCache(100001, false);
    vector<list<int>::iterator> positions(100001);

    int packet;
    for (int i = 0; i < t; ++i)
    {

        scanf("%d", &packet);

        if (isInCache[packet])
        {

            cache.erase(positions[packet]);
            cache.push_back(packet);
            positions[packet] = --cache.end();
            printf("%s\n", "true");

        }
        else
        {

            if (cache.size() == n)
            {

                isInCache[cache.front()] = false;
                cache.pop_front();

            }

            cache.push_back(packet);
            isInCache[packet] = true;
            positions[packet] = --cache.end();
            printf("%s\n", "false");

        }

    }

    return 0;

}
