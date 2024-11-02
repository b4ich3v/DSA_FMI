#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

struct Node 
{

    Node* next;
    int data;

    Node(Node* _next, int _data)
    {

        next = _next;
        data = _data;

    }

};
class LinkedList 
{
public:

    LinkedList() 
    {

        head = NULL;

    }

    ~LinkedList() 
    {

        Node* tmp;

        while (head != NULL) 
        {

            tmp = head;
            head = head->next;
            delete tmp;

        }

    }

    void add(int number) 
    {

        Node* tmp = new Node(head, number);
        head = tmp;

    }

    void print() 
    {

        Node* curr = head;

        while (curr != NULL) 
        {

            std::cout << curr->data << " ";
            curr = curr->next;

        }

    }

    void removeComplex(int devidedBy) 
    {

        while (head != nullptr && head->data % devidedBy == 0) 
        {

            Node* temp = head;
            head = head->next;
            delete temp;

        }

        Node* current = head;

        while (current != nullptr && current->next != nullptr)
        {

            if (current->next->data % devidedBy == 0)
            {

                Node* iter = current->next;
                current->next = current->next->next;
                delete iter;

            }
            else
            {

                current = current->next;

            }

        }

    } 

private:

    Node* head;

};
int main() 
{

    LinkedList l;

    int n;
    std::cin >> n;
    int number;
    for (int i = 0; i < n; i++) 
    {

        std::cin >> number;
        l.add(number);

    }

    int devidedBy;
    std::cin >> devidedBy;
    l.removeComplex(devidedBy);
    l.print();

    return 0;

}
