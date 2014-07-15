/*
 * MyLinkedList.h
 *
 *  Created on: 2014年7月15日
 *      Author: Administrator
 */

#ifndef MYLINKEDLIST_H_
#define MYLINKEDLIST_H_

#include <iostream>
#include <stdexcept>


template <typename T>
class Node {
public:
	T val;
	Node<T> *next;
public:
	Node() : val(0), next(0) {}
	Node(T v) : val(v), next(0) {}

	Node& operator = (const Node& node) {
		val = node.val;
		next = node.next;
		return *this;
	}
};

template <typename T>
class LinkedList {
private:
	Node<T> *head;
	Node<T> *tail;
	size_t size;
public:
	LinkedList() : head(0), tail(0), size(0) {}
	LinkedList(T v)  {
		head = tail = new Node<T>(v);
		size = 1;
	}
	~LinkedList() {
		Node<T> *cur = head;
		while (head) {
			cur = head;
			head = head->next;
			delete cur;
		}

		head = tail = 0;
		size = 0;
	}

	void pushBack(T v) {
		if (!head) {
			head = tail = new Node<T>(v);
		} else {
			tail->next = new Node<T>(v);
			tail = tail->next;
		}
		size++;
	}

	void pushFront(T v) {
		Node<T>* node = new Node<T>(v);
		if (!head) {
			head = tail = node;
		} else {
			node->next = head;
			head = node;
		}
		size++;
	}

	void pushInto(int index, T v) {
		if (index <= 0) {
			pushFront(v);
		} else if (index > size ){
			pushBack(v);
		} else {
			Node<T> *cur = head;
			int pos = 1;
			while (pos != index) {
				cur = cur->next;
				pos++;
			}
			Node<T> *tmp = cur->next;
			Node<T> *node = new Node<T>(v);
			cur->next = node;
			node->next = tmp;
			size++;
		}
	}

	T popBack() {
		if (!head) {
			throw std::out_of_range("The list is empty!");
		} else if (head == tail) {
			T v = tail->val;
			delete tail;
			head = tail = 0;
			size--;
			return v;
		} else {
			Node<T> *cur = head;
			while (cur->next != tail) {
				cur = cur->next;
			}
			cur->next = 0;
			T v = tail->val;
			delete tail;
			tail = cur;
			size--;
			return v;
		}
	}

	T popFront() {
		if (!head) {
			throw std::out_of_range("The list is empty!");
		} else if (head == tail) {
			T v = head->val;
			delete head;
			head = tail = 0;
			size--;
			return v;
		} else {
			T v = head->val;
			delete head;
			head = head->next;
			size--;
			return v;
		}
	}

	T popFrom(int index) {
		if (index <= 0) {
			return popFront();
		} else if (index >= size) {
			return popBack();
		} else {
			Node<T> *cur = head;
			int pos = 1;
			while (pos != index) {
				cur = cur->next;
				pos++;
			}
			Node<T> *tmp = cur->next;
			cur->next = tmp->next;
			T v = tmp->val;
			delete tmp;
			size--;
			return v;
		}
	}

	void traversal() {
		Node<T> *cur = head;
		while (cur) {
			std::cout << cur->val << " ";
			cur = cur->next;
		}
		std::cout << std::endl;
	}

	size_t getSize() const {
		return size;
	}

};



#endif /* MYLINKEDLIST_H_ */
