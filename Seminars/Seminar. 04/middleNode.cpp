#include <iostream>

struct ListNode 
{

    int value;
    ListNode* next;
    ListNode(int x) : value(x), next(nullptr) {}

};

class Solution 
{
public:

    ListNode* middleNode(ListNode* head) 
    {

        ListNode* slow = head; 
        ListNode* fast = head; 

        while (fast != nullptr && fast->next != nullptr) 
        {

            slow = slow->next;       
            fast = fast->next->next; 

        }
        
        return slow; 

    }

};
