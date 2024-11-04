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

		for (Node* i = head; i; i = i->next)
		{

			if (i->child)
			{

				Node* next = i->next;
				i->next = i->child;
				i->next->prev = i;
				i->child = nullptr;

				Node* j = i->next;
				while (j->next) j = j->next;
				j->next = next;
				if (next) next->prev = j;
			}

		}

		return head;

	}

};
