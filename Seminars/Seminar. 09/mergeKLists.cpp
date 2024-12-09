#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

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

    ListNode* mergeKLists(std::vector<ListNode*>& lists)
    {

        std::priority_queue<int, std::vector<int>, std::greater<int>> q;

        for (ListNode* current : lists)
        {

            while (current)
            {

                q.push(current->val);
                current = current->next;

            }

        }

        if (q.empty()) return nullptr;

        ListNode* result = new ListNode(q.top());
        ListNode* iter = result;
        q.pop();

        while (!q.empty())
        {

            iter->next = new ListNode(q.top());
            q.pop();
            iter = iter->next;

        }

        return result;

    }

};
