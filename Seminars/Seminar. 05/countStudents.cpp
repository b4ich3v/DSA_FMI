#include <queue>
#include <vector>
#include <stack>

class Solution 
{
public:

    int countStudents(std::vector<int>& students, std::vector<int>& sandwiches) 
    {

        std::queue<int> forStudents;
        std::stack<int> forSandwiches;

        for (int i = 0; i < students.size(); i++) forStudents.push(students[i]);
        for (int i = sandwiches.size() - 1; i >= 0 ; i--) forSandwiches.push(sandwiches[i]);
        
        int noMatchCount = 0;

        while (!forSandwiches.empty() && noMatchCount < forStudents.size())
        {

            if (forStudents.front() == forSandwiches.top())
            {

                forStudents.pop();
                forSandwiches.pop();
                noMatchCount = 0;

            }
            else
            {

                forStudents.push(forStudents.front());
                forStudents.pop();
                noMatchCount++;

            }

        }

        return forStudents.size();

    }

};
