#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>

#include "Node.hpp"
using namespace std;

template <class T>
class LinkedList {
public: // DO NOT CHANGE THIS PART.
    LinkedList();
    LinkedList(const LinkedList &obj);

    ~LinkedList();

    Node<T> *getFirstNode() const;
    int getNumberOfNodes();
    bool isEmpty();

    void insertAtTheFront(const T &data);
    void insertAtTheEnd(const T &data);
    void insertAfterGivenNode(const T &data, Node<T> *prev);

    void removeNode(Node<T> *node);
    void removeAllNodes();

    Node<T> *findNode(const T &data);

    void swapNodes(Node<T> *node1, Node<T> *node2);

    void printAllNodes();

    LinkedList &operator=(const LinkedList &rhs);

private: // YOU MAY ADD YOUR OWN UTILITY MEMBER FUNCTIONS HERE.
	void swapHeadTail();
	bool isNext(Node<T> *node1, Node<T> *node2);
	

private: // DO NOT CHANGE THIS PART.
    Node<T> *head;
    Node<T> *tail;
};

template<class T>
LinkedList<T>::LinkedList() {
	tail = NULL;
	head = NULL;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList &obj) {
	Node<T> *temphead = obj.head;
	Node<T> *temptail = obj.tail;
	head = NULL;
	tail = NULL;
    if(temphead == NULL){
        head = NULL;
        tail = NULL;
        return;
    }

    while(temphead != temptail){
    	this->insertAtTheEnd(temphead->element);
    	temphead = temphead->next;
    }
    this->insertAtTheEnd(temptail->element);
}

template<class T>
LinkedList<T>::~LinkedList() {
	Node<T> *temp = head;
	Node<T> *near;
	while(temp){
		near = temp->next;
		delete temp;
		temp = near;
	}
}

template<class T>
Node<T> * LinkedList<T>::getFirstNode() const {
	if(head == NULL){
		return NULL;
	}
	else
    	return this->head;
}

template<class T>
int LinkedList<T>::getNumberOfNodes() {
    Node<T> *temp = head;
    int number = 0;
    while(temp){
    	number += 1;
    	temp = temp->next;
    }
    return number;
}

template<class T>
bool LinkedList<T>::isEmpty() {
    if(head == NULL){
    	return true;
    }
    else
    	return false;
}

template<class T>
void LinkedList<T>::insertAtTheFront(const T &data) {
	if (isEmpty()){
		Node<T> *temp = new Node<T>();
		temp->element = data;
		head = temp;
        tail = temp;
	}
	else if(head == tail){
		Node<T> *temp = new Node<T>();
		temp->element = data;
		head->prev = temp;
		temp->next = tail;
		head = temp;
        head->prev = NULL;
	}
	else{
		Node<T> *temp = new Node<T>();
		temp->element = data;
		temp->next = head;
		head->prev = temp;
		head = temp;
        head->prev = NULL;
	}
}

template<class T>
void LinkedList<T>::insertAtTheEnd(const T &data) {
	if (isEmpty()){
		Node<T> *temp = new Node<T>();
		temp->element = data;
		head = temp;
        tail = temp;
        head->prev = NULL;
        tail->next = NULL;
	}
	else if(head == tail){
		Node<T> *temp = new Node<T>();
		temp->element = data;
		tail->next = temp;
		temp->prev = head;
		tail = temp;
        tail->next = NULL;
	}
	else{
		Node<T> *temp = new Node<T>();
		temp->element = data;
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
        tail->next = NULL;
	}

}

template<class T>
void LinkedList<T>::insertAfterGivenNode(const T &data, Node<T> *prev) {
    Node<T> *temp = new Node<T>();
    temp->element = data;
    if (this->findNode(prev->element) == NULL){
    	return;
    }
    else{
    	Node<T> * temp2 = this->findNode(prev->element)->next;
    	this->findNode(prev->element)->next = temp;
    	temp->next = temp2;
    	temp2->prev = temp;
    	temp->prev = this->findNode(prev->element);
    }
}

template<class T>
void LinkedList<T>::removeNode(Node<T> *node) {
	if(this->findNode(node->element) == NULL){
		return;
	}
	else if(tail == head && this->findNode(node->element) != NULL){
		Node<T> *temp = this->findNode(node->element);
		delete temp;
		this->tail = NULL;
		this->head = NULL;
	}
	else if(this->getNumberOfNodes() == 2){
		if(this->findNode(node->element) == head){
			Node<T> *temp = this->findNode(node->element);
			tail->prev = NULL;
			head = tail;
			delete temp;
		}
		else if(this->findNode(node->element) == tail){
			Node<T> *temp = this->findNode(node->element);
			head->next = NULL;
			tail = head;
			delete temp;
		}
	}
	else{
		if(this->findNode(node->element) == head){
			Node<T> *temp = this->findNode(node->element);
			head = temp->next;
			head->prev = NULL;
			delete temp;
		}
		else if(this->findNode(node->element) == tail){
			Node<T> *temp = this->findNode(node->element);
			tail = temp->prev;
			tail->next = NULL;
			delete temp;
		}
		else{
			Node<T> *temp1 = this->findNode(node->element)->prev;
			Node<T> *temp2 = this->findNode(node->element)->next;
			Node<T> *temp = this->findNode(node->element);
			temp1->next = temp2;
			temp2->prev = temp1;
			delete temp;

		}
	}
}

template<class T>
void LinkedList<T>::removeAllNodes() {
	Node<T> *temp = head;
	Node<T> *temp2 = head;
    while(temp){
    	temp2=temp2->next;
    	removeNode(temp);
    	temp = temp2;
    }
}

template<class T>
Node<T> * LinkedList<T>::findNode(const T &data) {
   	Node<T> *temp = head;
   	while(temp != NULL){
   		if(temp->element == data){
   			return temp;
   		}
   		else{
   			temp = temp->next;
   		}
   	}
   	return NULL;
}

template<class T>
void LinkedList<T>::swapNodes(Node<T> *node1, Node<T> *node2) {
    if(this->findNode(node1->element) == NULL && this->findNode(node2->element) == NULL){
    	return;
    }
    else if(this->getNumberOfNodes() == 2){
    	Node<T> *temp = head;
    	head = tail;
    	tail = temp;
    	tail->prev = head;
    	head->next = tail;
    	tail->next = NULL;
    	head->prev = NULL;
    }
    else if(this->findNode(node1->element) == head){
    	if(this->findNode(node2->element) == tail){
    		Node<T> *temp = head;
    		Node<T> *temp2 = tail;
    		temp2->next = temp->next;
    		temp->prev = temp2->prev;
    		temp2->prev->next = temp;
    		temp->next->prev = temp2;
    		temp2->prev = NULL;
    		temp->next = NULL;
    		head = temp2;
    		tail = temp;
    	}
    	else{
    		Node<T> *temp = head;
    		Node<T> *temp2 = this->findNode(node2->element);
    		temp->prev = temp2->prev;
    		temp->next->prev = temp2;
    		temp->next = temp2->next;
    		temp2->prev->next = temp;
    		temp2->next->prev = temp;
    		temp2->prev = NULL;
    		head = temp2;
    	}
    }
    else if(this->findNode(node1->element) == tail){
    	if(this->findNode(node2->element) == head){
    		Node<T> *temp = head;
    		Node<T> *temp2 = tail;
    		temp2->next = temp->next;
    		temp->prev = temp2->prev;
    		temp2->prev->next = temp;
    		temp->next->prev = temp2;
    		temp2->prev = NULL;
    		temp->next = NULL;
    		head = temp2;
    		tail = temp;
    	}
    	else{
    		Node<T> *temp = tail;
    		Node<T> *temp2 = this->findNode(node2->element);
    		Node<T> *tempprev = tail->prev;
    		temp->next = temp2->next;
    		temp->prev = temp2->prev;
    		temp->prev->next = temp2;
    		temp2->prev->next = temp;
    		temp2->next->prev = temp;
    		temp2->prev = tempprev;
    		temp2->next = NULL;
    		tail = temp2;

    	}
    }
    else{
    	Node<T> *temp = this->findNode(node1->element);
    	Node<T> *temp2 = this->findNode(node2->element);
    	Node<T> *tempprev = this->findNode(node1->element)->prev;
    	Node<T> *tempnext = this->findNode(node1->element)->next;
    	Node<T> *temp2prev = this->findNode(node2->element)->prev;
    	Node<T> *temp2next = this->findNode(node2->element)->next;
    	if(tempnext == temp2){
    		tempprev->next = temp2;
    		temp2->prev = tempprev;
    		temp2->next = temp;
    		temp->next = temp2next;
    		temp->prev = temp2;
    	}
    }

}

template<class T>
void LinkedList<T>::printAllNodes() {
	if(isEmpty()){
		return;
	}
	else{
		Node<T> *temp = head;
		cout << temp->element << endl;
    	while(temp != tail){
    		cout << temp->next->element << endl;
    		temp = temp->next;
    	}
    }
}

template<class T>
LinkedList<T> & LinkedList<T>::operator=(const LinkedList &rhs) {
    this->removeAllNodes();
    Node<T> *temp = rhs.getFirstNode();
    while(temp){
    	this->insertAtTheEnd(temp->element);
    	temp = temp->next;
    }
    return *this;
}

template<class T>
void LinkedList<T>::swapHeadTail(){
	Node<T> *temp = head;
	Node<T> *temp2 = tail;
	temp2->prev->next = temp2;
	temp->next->prev = temp2;
	temp->prev = temp2->prev;
	temp2->next = temp->next;
	temp2->prev = NULL;
	temp->next = NULL;
	head = temp2;
	tail = temp;
}

template<class T>
bool LinkedList<T>::isNext(Node<T> *node1, Node<T> *node2){
	if(this->findNode(node1->element)->next == this->findNode(node2->element)){
		return true;
	}
	else if(this->findNode(node2->element)->next == this->findNode(node1->element)){
		return true;
	}
	else
		return false;
}

#endif //LINKED_LIST_HPP