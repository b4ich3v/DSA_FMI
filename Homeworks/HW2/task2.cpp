#include <iostream>
#include <vector>

int main() 
{

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    const int MAX_POINTS = 100000; 
    std::vector<int> frequency(MAX_POINTS + 1, 0);

    for (int i = 0; i < n; i++) 
    {

        int point;
        std::cin >> point;
        frequency[point]++;

    }

    for (int i = 1; i <= MAX_POINTS; i++) frequency[i] += frequency[i - 1];

    for (int i = 0; i < q; i++) 
    {

        int a, b;
        std::cin >> a >> b;

        a = (a < 0) ? 0 : a; 
        b = (b > MAX_POINTS) ? MAX_POINTS : b;  

        int result = frequency[b] - (a > 0 ? frequency[a - 1] : 0);
        std::cout << result << '\n';

    }

    return 0;

}
