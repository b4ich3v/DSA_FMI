#include <iostream>

struct ListNode 
{

    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};
 
class Solution
{
public:

    ListNode* detectCycle(ListNode* head)
    {

        ListNode* fast = head;
        ListNode* slow = head;

        while (fast && fast->next)
        {

            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow)
            {

                ListNode* result = head;

                while (result != slow) 
                {

                    result = result->next;
                    slow = slow->next;

                }

                return result;

            }

        }

        return nullptr;

    }

};
