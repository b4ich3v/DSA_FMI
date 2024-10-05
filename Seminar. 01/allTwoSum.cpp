#include <iostream>
#include <vector>

int main()
{

    int size = 0;
    int target = 0;
    std::cin >> size >> target;
    std::vector<int> nums(size);

    for (int i = 0; i < size; i++)
    {

        std::cin >> nums[i];

    }

    std::vector<std::pair<int, int>> data(size);

    for (int i = 0; i < size; i++)
    {

        data[i].first = nums[i];
        data[i].second = i;

    }

    int left = 0;
    int right = data.size() - 1;
    int count = 0;

    while (left < right)
    {

        int sum = data[left].first + data[right].first;

        if (sum == target)
        {

            int leftCount = 1;
            int rightCount = 1;

            while (left + 1 < right && nums[left] == nums[left + 1])
            {

                left++;
                leftCount++;

            }

            while (right - 1 > left && nums[right] == nums[right - 1])
            {

                right--;
                rightCount++;

            }

            count += (leftCount * rightCount);
            left++;
            right--;

        }

        else if (sum > target)
        {

            right--;

        }

        else if (sum < target)
        {

            left++;

        }

    }

    std::cout << count << std::endl;
    return 0;

}
