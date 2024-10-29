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

    ListNode* reverse(ListNode* head) 
    {
  
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;

        while (current != nullptr) 
        {

            next = current->next;
            current->next = prev;
            prev = current;
            current = next;

        }

        head = prev;
        return head;

    }

};
