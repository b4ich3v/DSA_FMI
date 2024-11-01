#include <iostream>
#include <vector>
#include <algorithm>

int main()
{

    int N;
    std::cin >> N;

    std::vector<int> array(N);
    std::vector<std::pair<int, int>> sorted_with_index(N);

    for (int i = 0; i < N; i++) 
    {

        std::cin >> array[i];
        sorted_with_index[i] = { array[i], i };

    }

    std::sort(sorted_with_index.begin(), sorted_with_index.end());
    std::vector<int> new_index(N);

    for (int i = 0; i < N; i++) new_index[sorted_with_index[i].second] = i;
    for (int i = 0; i < N; i++) std::cout << new_index[i] << " ";

    return 0;

}
