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

    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) 
    {

        ListNode* iter1 = headA;
        ListNode* iter2 = headB;

        while (iter1 != iter2) 
        {

            if (iter1 != NULL) iter1 = iter1->next;
            else iter1 = headB;

            if (iter2 != NULL) iter2 = iter2->next;
            else iter2 = headA;


        }

        return iter1;

    }

};
