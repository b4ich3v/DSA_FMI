#include <iostream>

struct ListNode 
{

    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}

};

class Solution 
{
public:

    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
  
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevLeft = dummy; 

        
        for (int i = 1; i < left; i++)  prevLeft = prevLeft->next;

        ListNode* start = prevLeft->next; 
        ListNode* then = start->next; 

        for (int i = 0; i < right - left; i++) 
        {
            start->next = then->next; 
            then->next = prevLeft->next; 
            prevLeft->next = then; 
            then = start->next; 

        }

        ListNode* newHead = dummy->next;
        delete dummy; 
        return newHead;

    }

};
