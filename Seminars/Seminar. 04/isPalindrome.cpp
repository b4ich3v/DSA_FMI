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

    ListNode* reverse(ListNode* head)
    {

        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;

        while (current) 
        {

            next = current->next;
            current->next = prev;
            prev = current;
            current = next;

        }

        return prev; 

    }

    bool isPalindrome(ListNode* head)
    {

        if (!head || !head->next) return true; 

        ListNode* fast = head;
        ListNode* slow = head;

        while (fast && fast->next) 
        {

            fast = fast->next->next;
            slow = slow->next;

        }

        ListNode* reversedSecondHalf = reverse(slow);
        ListNode* current = head;

        while (reversedSecondHalf) 
        {
            if (current->val != reversedSecondHalf->val) return false;
            current = current->next;
            reversedSecondHalf = reversedSecondHalf->next;

        }

        return true; 

    }

};
