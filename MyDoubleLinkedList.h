/*
 * MyDoubleLinkedList.h
 *
 *  Created on: 2014年7月17日
 *      Author: Administrator
 */

#ifndef MYDOUBLELINKEDLIST_H_
#define MYDOUBLELINKEDLIST_H_

#include <stdexcept>

#ifndef NULL
#if defined(__cplusplus)
#define NULL 0
#else
#define NULL (void *)0
#endif
#endif

template<typename T>
class Node {
public:
	Node *prev;
	T element;
	Node *next;
public:
	Node(Node *prev, T e, Node *next) {
		this->prev = prev;
		this->element = e;
		this->next = next;
	}
};

template<typename T>
class DoubleLinkedListIterator {
private:
	Node<T> *cur;

public:
	DoubleLinkedListIterator() {
		cur = NULL;
	}
	DoubleLinkedListIterator(Node<T> *c) {
		cur = c;
	}

	DoubleLinkedListIterator& operator=(Node<T> *c) {
		cur = c;
		return *this;
	}

	int operator==(Node<T> *c) {
		return cur == c;
	}
	int operator!=(Node<T> *c) {
		return !operator==(c);
	}

	DoubleLinkedListIterator& operator++() { // override the ++x
		cur = cur->next;
		return *this;
	}

	int hasNext() {
		return (cur != NULL);
	}
	int hasPrevious() {
		return (cur != NULL);
	}

	Node<T>* next() {
		Node<T> *tmp = cur;
		cur = cur->next;
		return tmp;
	}

	T nextElement() {
		T e = getElement();
		next();
		return e;
	}

	Node<T>* previous() {
		Node<T> *tmp = cur;
		cur = cur->prev;
		return tmp;
	}

	T previousElement() {
		T e = getElement();
		previous();
		return e;
	}

	T getElement() {
		return cur->element;
	}

};

template<typename T>
class DoubleLinkedList {
private:
	Node<T> *head;
	Node<T> *tail;
	int size;

public:
	DoubleLinkedList() :
			head(NULL), tail(NULL), size(0) {
	}

	virtual ~DoubleLinkedList() {
		clear();
	}

	void pushFirst(T e) {
		Node<T> *f = this->head;
		Node<T> *newNode = new Node<T>(NULL, e, f);
		head = newNode;
		if (!tail) {
			tail = newNode;
		} else {
			f->prev = newNode;
		}
		size++;
	}

	void pushLast(T e) {
		Node<T> *l = this->tail;
		Node<T> *newNode = new Node<T>(l, e, NULL);
		if (!this->tail) {
			head = newNode;
		} else {
			tail = newNode;
			l->next = newNode;
		}
		size++;
	}

	T popFirst() {
		if (!head) {
			throw new std::out_of_range("The list is null!");
		} else {
			Node<T> *f = this->head;
			this->head = f->next;
			this->head->prev = NULL;
			T rv = f->element;
			delete f;
			size--;
			return rv;
		}
	}

	T popLast() {
		if (!tail) {
			throw new std::out_of_range("The list is null");
		} else {
			Node<T> *l = tail;
			tail = l->prev;
			tail->next = NULL;
			T rv = l->element;
			delete l;
			size--;
			return rv;
		}
	}

	int getSize() const {
		return size;
	}

	void clear() {
		Node<T> *c = head;
		while (c) {
			Node<T> *tmp = c;
			delete tmp;
			tmp = NULL;
			c = c->next;
			size--;
		}
	}

	DoubleLinkedListIterator<T> getIterator() {
		DoubleLinkedListIterator<T> iter = head;
		return iter;
	}

};

#endif /* MYDOUBLELINKEDLIST_H_ */
