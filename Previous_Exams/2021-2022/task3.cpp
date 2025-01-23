#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <string>
#include <stack>

struct Node 
{

    Node* next;
    int data;

};

class LinkedList 
{
public:

    LinkedList() 
    {

        head = nullptr;
        tail = nullptr;

    }

    ~LinkedList() 
    {

        Node* temp;

        while (head != nullptr) 
        {

            temp = head;
            head = head->next;
            delete temp;

        }

    }

    void add(int value) 
    {

        Node* temp = new Node;
        temp->data = value;
        temp->next = nullptr;

        if (head == nullptr and tail == nullptr)
        {

            head = tail = temp;

        }
        else 
        {

            tail->next = temp;
            tail = temp;

        }

    }

    void print() 
    {

        Node* curr = head;

        while (curr != nullptr) 
        {

            std::cout << curr->data << " ";
            curr = curr->next;

        }

    }

    Node* head, * tail;

};

void solve(LinkedList& num1, LinkedList& num2) 
{

    Node* current1 = num1.head;
    Node* current2 = num2.head;

    std::stack<int> s;
    int carry = 0;
    
    while (current1 != nullptr || current2 != nullptr || carry != 0) 
    {

        int digit1 = 0;
        int digit2 = 0;

        if (current1 != nullptr) digit1 = current1->data;
        if (current2 != nullptr) digit2 = current2->data;

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        int currentDigit = sum % 10;

        s.push(currentDigit);

        if (current1 != nullptr) current1 = current1->next;
        if (current2 != nullptr) current2 = current2->next;

    }

    while (!s.empty())
    {

        int currentDigit = s.top();
        s.pop();

        std::cout << currentDigit;

    }

}

int main() 
{

    LinkedList num1, num2;

    int size1, size2;
    std::cin >> size1;

    for (int i = 0; i < size1; i++) 
    {

        int digit;
        std::cin >> digit;
        num1.add(digit);

    }

    std::cin >> size2;
    for (int i = 0; i < size2; i++) 
    {

        int digit;
        std::cin >> digit;
        num2.add(digit);

    }

    solve(num1, num2);

    return 0;

}
