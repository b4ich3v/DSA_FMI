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

    ListNode* insertionSortList(ListNode* head) 
    {

        ListNode* dummy = new ListNode(0);
        ListNode* current = head;

        while (current != nullptr) 
        {
            
            ListNode* nextTemp = current->next; 
            ListNode* sorted = dummy; 

            while (sorted->next != nullptr && sorted->next->value < current->value) sorted = sorted->next;

            current->next = sorted->next; 
            sorted->next = current; 

            current = nextTemp;

        }

        ListNode* sortedHead = dummy->next;
        delete dummy; 
        return sortedHead;

    }

};


