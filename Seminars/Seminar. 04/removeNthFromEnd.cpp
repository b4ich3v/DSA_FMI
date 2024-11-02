#include <iostream>

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

    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {

        ListNode* fast = head;
        ListNode* slow = head;

        for (int i = 0; i < n; i++)  fast = fast->next;


        while (fast->next)
        {

            slow = slow->next;
            fast = fast->next;

        }

        ListNode* oper = slow->next;
        slow->next = slow->next->next;
        delete oper;

        return head;

    }

};
