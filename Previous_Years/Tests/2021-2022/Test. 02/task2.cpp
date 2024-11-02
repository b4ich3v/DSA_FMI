#include <iostream>
#include <sstream>
#include <stack>

struct Node
{

    int value;
    Node* next;
 
    Node(int value, Node* next = nullptr) : value(value), next(next) {};

};

struct SinglyLinkedList
{

    Node* head, * tail;
    int size;

    SinglyLinkedList() :head(nullptr), tail(nullptr), size(0) {}; 

    void addAtHead(int X); 
    void addAtTail(int X); 
    void add(int X, int pos);

    void remove(int pos);

    void reverse(); 

    Node* reverseRecursiveUtil(Node* head); 
    void reverseRecursive(); 

    bool isPalindrom();

    int count(int X);

    void removeAll(int X);

    void group(int start, int end);

    friend std::ostream& operator<<(std::ostream& os, const SinglyLinkedList& list);

};


int main()
{

    size_t N, Q; std::cin >> N;

    int el(0), pos(0);

    for (size_t i = 0; i < N; i++)
    {

        SinglyLinkedList list;

        std::cin >> Q; std::cin.ignore();

        for (size_t i = 0; i < Q; i++)
        {

            std::string line; getline(std::cin, line);
            std::istringstream istr(line);

            std::string command; istr >> command;

            if (command == "add")
            {

                istr >> el >> pos;
                list.add(el, pos);

            }
            else if (command == "print")
            {

                std::cout << list;

            }
            else if (command == "remove")
            {

                istr >> pos;
                list.remove(pos);

            }
            else if (command == "count")
            {

                istr >> el;
                std::cout << list.count(el);

            }
            else
            {

                int count(0);

                while (istr)
                {

                    istr >> command;
                    count++;

                }

                i += count - 1;

            }

        }

        std::cout << '\n';

    }

    return 0;

}

std::ostream& operator<<(std::ostream& os, const SinglyLinkedList& list)
{

    Node* traverse = list.head;

    while (traverse != nullptr)
    {

        os << traverse->value << '#';
        traverse = traverse->next;

    } 

    return os;

}

void SinglyLinkedList::addAtHead(int X)
{

    Node* newNode = new Node(X);

    if (head == nullptr) 
    {

        head = tail = newNode;

    }
    else
    {

        Node* temp = head;
        newNode->next = temp;
        head = newNode;

    }

    size++;

}

void SinglyLinkedList::addAtTail(int X)
{

    Node* newNode = new Node(X);

    if (head == nullptr)
    {

        head = tail = newNode;

    }
    else
    {

        tail->next = newNode;
        tail = newNode;

    }

    size++;

}

void SinglyLinkedList::add(int X, int pos)
{

    if (pos == 0) 
    {

        addAtHead(X);

    }
    else if (pos < 0 || pos > size)
    {

        addAtTail(X);
        std::cout << "add_last";

    }
    else if (pos == size)
    {

        addAtTail(X);

    }
    else
    {
        Node* newNode = new Node(X);
        Node* traverse = head;
        for (int i = 1; i < pos; i++)
        {

            traverse = traverse->next;

        }      
        Node* temp = traverse->next; 
        traverse->next = newNode;
        newNode->next = temp;
        size++;

    }

}

void SinglyLinkedList::remove(int pos)
{

    if (pos < 0 || pos >= (int)size)
    {

        std::cout << "remove_failed";

    }
    else if (pos == 0)
    {

        Node* temp = head->next;
        delete head;
        head = temp;
        size--;

    }
    else
    {

        Node* traverse = head;

        for (int i = 0; i < pos - 1; i++)
        {

            traverse = traverse->next;

        } 

        Node* temp = traverse->next; 
        traverse->next = temp->next; 

        if (temp->next == nullptr)
        {

            tail = traverse;

        }

        delete temp; 
        size--;

    }

}


int SinglyLinkedList::count(int X)
{

    int counter = 0;
    Node* current = head;

    while (current != nullptr)
    {

        if (current->value == X)
        {

            counter++;

        }

        current = current->next;

    }

    return counter;

}
