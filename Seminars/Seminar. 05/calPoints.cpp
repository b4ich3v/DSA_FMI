#include <string>
#include <stack>
#include <algorithm>

class Solution
{
public:

    int calPoints(std::vector<std::string>& operations)
    {

        std::vector<int> arr;
        int sum = 0;  

        for (const std::string& op : operations)
        {

            if (op == "C")
            {
               
                if (!arr.empty())
                {

                    sum -= arr.back();
                    arr.pop_back();

                }

            }
            else if (op == "D")
            {
               
                if (!arr.empty())
                {

                    int doubleLast = 2 * arr.back();
                    arr.push_back(doubleLast);
                    sum += doubleLast;

                }

            }
            else if (op == "+")
            {
                
                if (arr.size() >= 2)
                {

                    int sumLastTwo = arr[arr.size() - 1] + arr[arr.size() - 2];
                    arr.push_back(sumLastTwo);
                    sum += sumLastTwo;
                }

            }
            else
            {
                
                int points = std::stoi(op);
                arr.push_back(points);
                sum += points;

            }

        }

        return sum;

    }

};
