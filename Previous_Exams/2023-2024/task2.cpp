#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

int main()
{

    long long N;
    std::cin >> N;

    std::vector<long long> array(N);
    for (long long i = 0; i < N; i++) std::cin >> array[i];

    sort(array.begin(), array.end());

    long long Q;
    std::cin >> Q;

    for (int i = 0; i < Q; i++)
    {

        long long number;
        std::cin >> number;

        auto iter = lower_bound(array.begin(), array.end(), number);

        if (iter == array.end()) std::cout << -1 << std::endl;

        else if (iter == array.begin())
        {

            if (iter + 1 != array.end()) std::cout << *(iter + 1) << std::endl;
            else std::cout << -1 << std::endl;

        }
        else if (iter != array.end() && *iter == number)
        {

            if (iter + 1 != array.end()) std::cout << *(iter + 1) << std::endl;
            else std::cout << -1 << std::endl;

        }
        else
        {

            auto left = (iter - 1);

            if (abs(*left - number) >= abs(*iter - number))
            {

                if (iter + 1 != array.end()) std::cout << *(iter + 1) << std::endl;
                else std::cout << -1 << std::endl;

            }

            else std::cout << *iter << std::endl;

        }

    }

    return 0;

}
