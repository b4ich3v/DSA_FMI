#include <vector>
#include <stack>

class Solution 
{
public:

    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) 
    {

        int size = temperatures.size();
        std::vector<int> result(size, 0);  
        std::stack<int> indexes;        

        for (int i = 0; i < size; i++) 
        {
           
            while (!indexes.empty() && temperatures[i] > temperatures[indexes.top()]) 
            {

                int index = indexes.top();
                indexes.pop();
                result[index] = i - index;  

            }

            indexes.push(i);

        }

        return result;

    }

};

