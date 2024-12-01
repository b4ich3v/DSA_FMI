#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <algorithm>

class Solution 
{
public:

    int shortestSequence(std::vector<int>& rolls, int k) 
    {

        std::unordered_set<int> s;
        int result = 0;

        for (int i = 0; i < rolls.size(); ++i) 
        {

            s.insert(rolls[i]);

            if (s.size() == k) 
            {

                s.clear();
                result++;

            }


        }


        return result + 1;

    }

};
