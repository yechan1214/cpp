#pragma once
#include <iostream>

template<class T>
class SSL_Node {
public:
	SSL_Node() {}
	~SSL_Node() {};
	T var;
	SSL_Node<T>* next;
};

template<class T>
class singleLinkedList {
	
private:
	SSL_Node<T>* head_node = nullptr;
	int list_size = 0;
public:
	singleLinkedList() {}

	void push(T var) {
		if (head_node == nullptr) {
			head_node = new SSL_Node<T>();
			head_node->var = var;
			head_node->next = nullptr;
		}
		else {
			SSL_Node<T>* new_node = new SSL_Node<T>();
			SSL_Node<T>* temp_node = head_node;
			new_node->var = var;
			new_node->next = head_node;
			head_node = new_node;
			new_node = temp_node;
		}
		list_size++;
	}

	void pop() {
		if (head_node == nullptr) return;
		SSL_Node<T>* temp_node = head_node->next;
		delete head_node;
		head_node = temp_node;
		list_size--;
	}

	void print() {
		SSL_Node<T>* temp_node = head_node;
		while (temp_node != nullptr) {
			std::cout << temp_node->var << " ";
			temp_node = temp_node->next;
		}
		std::cout << std::endl;
	}

	T top() {
		return head_node->var;
	}

	int size() {
		return this->list_size;
	}
};
