#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{

    int N;
    std::cin >> N;

    std::vector<int> array(N);

    for (int i = 0; i < N; i++)  std::cin >> array[i];
    std::sort(array.begin(), array.end());

    bool pred = false;

    for (int i = N - 1; i >= 0; i--)
    {

        int target = array[i];
        int left = 0;
        int right = i - 1;


        while (left < right) 
        {

            int currentSum = array[left] + array[right];

            if (currentSum == target) { pred = true;  break; }
            else if (currentSum < target) left++;
            else right--;

        }

        if (pred) break;

    }

    if (pred) std::cout << "true" << std::endl;
    else std::cout << "false" << std::endl;

    return 0;

}
