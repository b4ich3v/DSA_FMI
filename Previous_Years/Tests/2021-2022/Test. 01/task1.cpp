#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main() 
{
    
    int n = 0;
    std::cin >> n;
    std::vector<int> array(n);
    for (int i = 0; i < n; i++) std::cin >> array[i];

    std::vector<bool> counter(70000, false);
    for (int i = 0; i < n; i++) counter[array[i]] = true;

    for (int i = 0; i < 70000; i++)
        if (counter[i]) std::cout << i << " ";

    return 0;

}

