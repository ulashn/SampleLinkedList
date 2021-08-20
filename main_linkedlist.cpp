#include <iostream>

#include "LinkedList.hpp"
using namespace std;

int main() {
    LinkedList<int> llist;

    llist.insertAtTheFront(6);
    cout << "Number of Elements: " << llist.getNumberOfNodes() << endl;
    llist.printAllNodes();
    llist.insertAtTheFront(4);
    llist.insertAtTheFront(2);
    llist.insertAtTheEnd(8);
    llist.printAllNodes();
    cout << "---------" << endl;
    llist.insertAtTheFront(5);
    cout << llist.findNode(4)->element << endl;
    cout << "---------" << endl;
    llist.printAllNodes();
    cout << "Number of Elements: " << llist.getNumberOfNodes() << endl;
    cout << "First Node element: " << llist.getFirstNode()->element << endl;
    llist.removeNode(llist.findNode(4));
    cout << "Number of Elements: " << llist.getNumberOfNodes() << endl;
    cout << "---------" << endl;
    llist.printAllNodes();
    //cout << "---------" << endl;
    //llist.removeNode(llist.findNode(2));
    //llist.removeNode(llist.findNode(8));
    //llist.printAllNodes();
    cout << "---------" << endl;
    llist.swapNodes(llist.findNode(5),llist.findNode(6));
    llist.printAllNodes();
    //llist.insertAtTheFront(2);
    //llist.insertAtTheFront(4);
    //cout << "---------" << endl;
    //llist.printAllNodes();
    //llist.swapNodes(llist.findNode(2),llist.findNode(6));
    //cout << "---------" << endl;
    //llist.printAllNodes();

    return 0;
}