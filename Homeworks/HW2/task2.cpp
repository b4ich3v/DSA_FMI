#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>  

int main()
{

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long n, q;
    std::cin >> n >> q;

    std::vector<long long> scores(n);
    for (long long i = 0; i < n; i++) std::cin >> scores[i];

    std::sort(scores.begin(), scores.end());

    for (long long i = 0; i < q; i++)
    {

        long long a, b;
        std::cin >> a >> b;

        auto lower = std::lower_bound(scores.begin(), scores.end(), a);
        auto upper = std::upper_bound(scores.begin(), scores.end(), b);

        long long count = upper - lower;
        std::cout << count << '\n';

    }

    return 0;

}
