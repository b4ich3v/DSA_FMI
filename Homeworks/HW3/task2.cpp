struct SinglyLinkedListNode 
{

    int data;
    SinglyLinkedListNode* next;
    SinglyLinkedListNode(int _data, SinglyLinkedListNode* _next = nullptr) : data(_data), next(_next) {}

};

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position)
{

    SinglyLinkedListNode* llistStart = llist;
    int index = 1;

    while (index < position)
    {

        llist = llist->next;
        index++;

    }

    SinglyLinkedListNode* nextNode = llist->next;
    SinglyLinkedListNode* inserted = new SinglyLinkedListNode(data);
    inserted->next = nextNode;
    llist->next = inserted;

    return llistStart;

}
