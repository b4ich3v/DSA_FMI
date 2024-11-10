#include <vector>
#include <stack>

struct ListNode
{

    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

};

class Solution
{
public:

    std::vector<int> nextLargerNodes(ListNode* head)
    {

        std::vector<int> values;
        ListNode* current = head;

        while (current)
        {

            values.push_back(current->val);
            current = current->next;

        }

        int size = values.size();
        std::vector<int> result(size, 0);
        std::stack<int> indexes;

        for (int i = 0; i < size; ++i)
        {

            while (!indexes.empty() && values[i] > values[indexes.top()])
            {

                result[indexes.top()] = values[i];
                indexes.pop();

            }

            indexes.push(i);

        }

        return result;

    }

};
