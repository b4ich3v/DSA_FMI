#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main() 
{
   
    int N = 0;
    std::cin >> N;

    std::vector<int> array(N);
    for (int i = 0; i < N; i++) std::cin >> array[i];
   
    auto K = *max_element(array.begin(), array.end()) + 1;
    std::vector<int> counter(K);

    for (int i = 0; i < N; i++) counter[array[i]]++;
    for (int i = 0; i < K; i++) 
    {

        if (counter[i] != 0) std::cout << i << " ";

    }

    return 0;

}

