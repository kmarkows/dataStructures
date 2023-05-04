#include "myVector.hpp"
#include "./dataStructures/linkedList.hpp"
#include "./dataStructures/stack.hpp"

int main()
{
    // LinkedList<int> testList;
    // testList.insertNode(5);
    // testList.insertNode(6);
    // testList.printList();

    // NodeForLinkedList<int> nodeToAdd(7);
    // testList.insertNode(&nodeToAdd);
    // testList.printList();

    // testList.insertNode(8);
    // testList.printList();

    // LinkedList<int> testList1;
    // testList.insertNode(9);
    // testList.insertNode(10);
    // testList.insertNode(&testList1);
    // testList.printList();

    // testList.deleteNode(5);
    // testList.printList();
    
    // testList.deleteNode(8);
    // testList.printList();

    Stack<int> testStack(5);
    testStack.print();
    testStack.pop();

    testStack.push(1);
    testStack.push(2);
    testStack.push(3);
    testStack.push(4);
    testStack.push(5);
    testStack.push(6);
    testStack.push(7);
    testStack.print();

    testStack.pop();
    testStack.pop();
    testStack.print();


    return 0;
}