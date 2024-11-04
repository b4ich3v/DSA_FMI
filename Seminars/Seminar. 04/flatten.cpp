#include <iostream>

class Node 
{
public:

	int val;
	Node* prev;
	Node* next;
	Node* child;

};

class Solution 
{
public:

	Node* flatten(Node* head) 
	{

		for (Node* current1 = head; current1; current1 = current1->next)
		{

			if (current1->child)
			{

				Node* next = current1->next;
				current1->next = current1->child;
				current1->next->prev = current1;
				current1->child = nullptr;

				Node* current2 = current1->next;
				while (current2->next) current2 = current2->next;
				current2->next = next;
				if (next) next->prev = current2;

			}

		}

		return head;

	}

};
