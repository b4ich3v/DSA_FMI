#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <unordered_set>

class Solution 
{
public:

    int toInt(std::string str) 
    {

        int product = 1;
        int result = 0;

        for (int i = str.size() - 1; i >= 0; i--) 
        { 

            if (str[i] == '1') result += product;
            product *= 2;

        }

        return result;

    }

    std::string toStr(int number, int length) 
    { 

        std::string result = "";

        while (number)
        {

            int rem = number % 2;
            number /= 2;
            result += std::to_string(rem);

        }

        while (result.size() < length) result += "0";

        std::reverse(result.begin(), result.end());
        return result;

    }

    std::string findDifferentBinaryString(std::vector<std::string>& nums) 
    {

        std::unordered_set<int> s;
        int iter = nums[0].size();
        int largestNumber = (1 << iter) - 1; 

        for (const auto& current : nums) s.insert(toInt(current));

        for (int i = 0; i <= largestNumber; i++) 
        { 

            if (s.find(i) == s.end()) 
            {

                return toStr(i, iter);

            }

        }

        return "";

    }

};
