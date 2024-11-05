struct SinglyLinkedListNode 
{

    int data;
    SinglyLinkedListNode* next;
    SinglyLinkedListNode(int _data, SinglyLinkedListNode* _next = nullptr) : data(_data), next(_next) {}

};

SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist)
{

    SinglyLinkedListNode* result = new SinglyLinkedListNode(0);
    result->next = llist;

    SinglyLinkedListNode* iter = result;

    while (iter)
    {

        while (iter->next && iter->next->next && iter->next->data == iter->next->next->data)
        {

            iter->next = iter->next->next;

        }

        iter = iter->next;

    }

    return result->next;

}
