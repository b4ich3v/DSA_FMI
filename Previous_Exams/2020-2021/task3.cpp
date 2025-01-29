#include <iostream>

struct Node 
{

    int data;
    Node* next;

};

struct List 
{

    Node* head = nullptr;
    Node* tail = nullptr;

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

    void reverse(int from, int to) 
    {
        
        if (!head || from < 1 || to < 1 || from > to) return;

        int size = 0;
        Node* temp = head;

        while (temp) 
        {

            size++;
            temp = temp->next;

        }

        if (from > size) return;

        to = std::min(size, to);
            
        if (from >= to) return;

        Node* currrent = head;
        int index = 1;

        Node* lastFromFirst = nullptr;
        while (index < from)
        {

            lastFromFirst = currrent;
            currrent = currrent->next;
            index += 1;

        }

        Node* firstFromSecond = currrent;
        Node* prev = nullptr;

        while (index <= to)
        {

            Node* nextElement = currrent->next;
            currrent->next = prev;
            prev = currrent;
            currrent = nextElement;
            index += 1;

        }

        if (lastFromFirst) lastFromFirst->next = prev;
        else head = prev;

        firstFromSecond->next = currrent;

        if (currrent == nullptr) tail = firstFromSecond;

    }

    void print() 
    {

        Node* temp = head;

        while (temp)
        {

            std::cout << temp->data << " ";
            temp = temp->next;

        }

        std::cout << std::endl;

    }

    ~List() 
    {

        Node* curr = head;

        while (curr)
        {

            Node* prev = new Node;
            prev = curr;
            curr = curr->next;
            delete prev;

        }

        delete curr;

    }

};

int main() 
{

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    List testList;

    int queries;
    std::cin >> queries;

    for (int t = 0; t < queries; t++)
    {

        std::string op;
        std::cin >> op;

        if (op == "add") 
        {

            int num;
            std::cin >> num;
            testList.add(num);

        }

        if (op == "print")
        {

            testList.print();

        }

        if (op == "reverse") 
        {

            int from, to;
            std::cin >> from >> to;
            testList.reverse(from, to);

        }

    }

    return 0;

}
