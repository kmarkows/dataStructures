#include <iostream>

template<typename T>
struct NodeForLinkedList
{
    T data;
    NodeForLinkedList* next;

    NodeForLinkedList()
    {
        data = 0;
        next = nullptr;
    }

    NodeForLinkedList(T givenData)
    {
        data = givenData;
        next = nullptr;
    }
};

template<typename T>
class LinkedList
{
    NodeForLinkedList<T>* head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void insertNode(T givenData)
    {
        NodeForLinkedList<T>* newNodeForLinkedList = new NodeForLinkedList<T>(givenData);
        if (head == nullptr)
        {
            head = newNodeForLinkedList;
            return;
        }
        
        NodeForLinkedList<T>* temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNodeForLinkedList;
    }

    void insertNode(NodeForLinkedList<T>* givenNodeForLinkedList)
    {
        if (head == nullptr)
        {
            head = givenNodeForLinkedList;
            return;
        }
        
        NodeForLinkedList<T>* temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = givenNodeForLinkedList;
    }

    void insertNode(LinkedList<T>* givenLinkedList)
    {
        if (head == nullptr)
        {
            head = givenLinkedList->head;
            return;
        }
        NodeForLinkedList<T>* temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = givenLinkedList->head;
    }

    void deleteNode(T dataToDeletion)
    {
        NodeForLinkedList<T>* temp1 = head;
        NodeForLinkedList<T>* temp2 = nullptr;

        if (head->data == dataToDeletion)
        {
            head = head->next;
            delete temp1;
            return;
        }

        temp1 = head->next;
        temp2 = head;

        while (temp1 != nullptr)
        {
            if (temp1->data == dataToDeletion)
            {
                temp2->next = temp1->next;
                delete temp1;
                return;
            }
            else
            {
                temp2 = temp1;
                temp1 = temp1->next;
            }
        }
    }

    void printList()
    {
        NodeForLinkedList<T>* temp = head;
        while (temp != nullptr)
        {
            std::cout<<temp->data<<" ";
            temp = temp->next;
        }
        std::cout<<std::endl;
    }

};