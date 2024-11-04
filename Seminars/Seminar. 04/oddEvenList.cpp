#include <iostream>
#include <vector>
#include <algorithm>

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

    int sizeOfList(ListNode* head)
    {

        ListNode* current = head;
        int counter = 0;

        while (current)
        {

            current = current->next;
            counter++;

        }

        return counter;

    }

    ListNode* oddEvenList(ListNode* head)
    {

        if (!head || !head->next) return head;  

        int size = sizeOfList(head);

        ListNode** nodes = new ListNode * [size];
        ListNode* current = head;

        for (int i = 0; i < size; i++)
        {

            nodes[i] = current;
            current = current->next;

        }

        ListNode* result = nodes[0];
        current = result;

        for (int i = 0; i < size; i += 2)
        {

            current->next = nodes[i];
            current = current->next;

        }

        for (int i = 1; i < size; i += 2)
        {

            current->next = nodes[i];
            current = current->next;

        }

        current->next = nullptr;
        delete[] nodes;
        return result;

    }

};
