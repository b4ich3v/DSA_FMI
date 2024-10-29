#include <iostream>
#include <vector>
#include <list>

struct ListNode 
{

    int value;
    ListNode* next;
    ListNode(int x) : value(x), next(nullptr) {}

};

class Solution 
{
public:

    ListNode* removeElements(ListNode* head, int target) 
    {
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* current = head;

        while (current->next != nullptr) 
        {

            if (current->next->value == target)
            {

                ListNode* needToBeDeleted = current->next;
                current->next = current->next->next;
                delete needToBeDeleted;

            }
            else
            {

                current = current->next;

            }

        }

        ListNode* newHead = dummy->next;
        delete dummy; 
        return newHead;

    }

};
