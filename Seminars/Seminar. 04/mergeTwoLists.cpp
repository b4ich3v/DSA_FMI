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

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy; 

        while (list1 != nullptr && list2 != nullptr) 
        {

            if (list1->value < list2->value) 
            {

                current->next = list1; 
                list1 = list1->next;  

            }
            else
            {

                current->next = list2; 
                list2 = list2->next;    

            }

            current = current->next; 

        }

        if (list1 != nullptr)    current->next = list1;
        else  current->next = list2;

        ListNode* mergedList = dummy->next;
        delete dummy; 
        return mergedList;

    }

};
