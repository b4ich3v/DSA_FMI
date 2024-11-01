#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main() 
{
    
    int N = 0;
    std::cin >> N;
    std::vector<int> array1(N);
    for (int i = 0; i < N; i++) std::cin >> array1[i];

    int M = 0;
    std::cin >> M;
    std::vector<int> array2(M);
    for (int i = 0; i < M; i++) std::cin >> array2[i];

    std::vector<bool> counter1(100001, false);
    std::vector<bool> counter2(100001, false);

    for (int i = 0; i < N; i++) counter1[array1[i]] = true;
    for (int i = 0; i < M; i++) counter2[array2[i]] = true;
    
    int sum = 0;
    for (int i = 0; i <= 100000; i++) if (counter1[i] && counter2[i])  sum += i;
        
    std::cout << sum;
    return 0;

}
