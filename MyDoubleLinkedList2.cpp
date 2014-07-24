#define INT_MAX 0x7fffffff

int binary_search(int *p_array, int l, int r, int key) {
	int m;
	if (l <= r) {
		m = l + (r - l) / 2; // not (l+r)/2 which may cause overflow
		if (key == p_array[m])
			return m;
		else if (key < p_array[m])
			r = m - 1;
		else
			l = m + 1;
	}
	return -1;
}

void insert_sort(int *p_array, int l, int r) {
	for (int j = l + 1; j <= r; ++j) {
		int i = l - 1;
		int key = p_array[j];
		while (i >= 0 && p_array[i] > key) {
			p_array[i + 1] = p_array[i];
			--i;
		}
		p_array[i + 1] = key;
	}
}

void merge(int *p_array, int l, int p, int r) {
	int llen = p - l + 1;
	int rlen = r - p;
	int *p_left = new int[llen + 1];
	int *p_right = new int[rlen + 1];
	int len = llen + rlen;
	int i = 0, j = 0, k = 0;
	for (; i < llen; ++i) {
		p_left[i] = p_array[l + i];
	}
	p_left[llen] = INT_MAX;
	for (; j < rlen; ++j) {
		p_right[j] = p_array[p + 1 + j];
	}
	p_right[rlen] = INT_MAX;
	i = 0;
	j = 0;
	for (; k < len; ++k) {
		if (p_left[i] < p_right[j]) {
			p_array[l + k] = p_left[i];
			++i;
		} else {
			p_array[l + k] = p_right[j];
			++j;
		}
	}
}

void merge_sort(int *p_array, int l, int r) {
	if (l < r) {
		int p = l + (r - l) / 2;
		merge_sort(p_array, l, p);
		merge_sort(p_array, p + 1, r);
		merge(p_array, l, p, r);
	}
}

void swap(int *p, int *q) {
	int tmp = *p;
	*p = *q;
	*q = tmp;
}

int partition(int *p_array, int l, int r) {
	int key = p_array[r];
	int j = 0;
	int i = j - 1;
	for (; j < r; ++j) {
		if (p_array[j] <= key) {
			++i; // the left border which are less and equal than the key
			swap(p_array + j, p_array + i);
		}
	}
	++i;
	swap(p_array + r, p_array + i);
	return i;
}

void quick_sort(int *p_array, int l, int r) {
	if (l < r) {
		int p = partition(p_array, l, r);
		quick_sort(p_array, l, p - 1);
		quick_sort(p_array, p + 1, r);
	}
}

int find_min(int a, int b, int c) {
	int tmp = (a < b) ? a : b;
	return (tmp < c) ? tmp : c;
}

int find_ugly_number(int *p_ugly_numbers, int n) {
	p_ugly_numbers[0] = 1;
	int idx2 = 0, idx3 = 0, idx5 = 0;
	for (int i = 1; i < n; ++i) {
		int tmp = find_min(2 * p_ugly_numbers[idx2], 3 * p_ugly_numbers[idx3],
				5 * p_ugly_numbers[idx5]);
		p_ugly_numbers[i] = tmp;
		if (tmp == 2 * p_ugly_numbers[idx2])
			++idx2;
		if (tmp == 3 * p_ugly_numbers[idx3])
			++idx3;
		if (tmp == 5 * p_ugly_numbers[idx5])
			++idx5;
	}
	int ret = p_ugly_numbers[n - 1];
	return ret;
}
#include <stdexcept>
template<typename T>
class Node {
public:
	Node *prev;
	T value;
	Node *next;
public:
	Node(Node *p, T v, Node *n) {
		prev = p;
		value = v;
		next = n;
	}
};
template<typename T>
class LinkedList {
public:
	Node<T> *head;
	Node<T> *tail;
	int size;
public:
	LinkedList() :
			head(0), tail(0), size(0) {
	}
	~LinkedList() {
		clear();
	}
	void push_back(T v) {
		Node<T> *node = new Node<T>(tail, v, 0);
		if (!tail) {
			head = tail = node;
		} else {
			tail->next = node;
			tail = tail->next;
		}
		++size;
	}

	void push_front(T v) {
		Node<T> *node = new Node<T>(0, v, head);
		if (head) {
			head = tail = node;
		} else {
			head->prev = node;
			head = head->prev;
		}
		++size;
	}

	bool is_empty() {
		return size == 0;
	}

	T pop_back() {
		if (is_empty()) {
			throw new std::out_of_range("The list is empty!");
		}
		Node<T> *node = tail;
		tail = tail->prev;
		if (tail) {
			tail->next = 0;
		}
		T ret = node->value;
		delete node;
		--size;
		return ret;
	}

	T pop_front() {
		if (is_empty()) {
			throw new std::out_of_range("The list is empty!");
		}
		Node<T> *node = head;
		head = head->next;
		if (head) {
			head->prev = 0;
		}
		T ret = node->value;
		delete node;
		--size;
		return ret;
	}

	int get_size() const {
		return this->size;
	}

	void clear() {
		while (tail) {
			Node<T> *node = tail;
			tail = tail->prev;
			if (tail) {
				tail->next = 0;
			}
			delete node;
		}
		head = tail = 0;
		size = 0;
	}

	int index_of(int key) {
		Node<T> *cur = head;
		int idx = -1;
		while (cur) {
			++idx;
			if (cur->value == key)
				return idx;
			cur = cur->next;
		}
		return -1;
	}

	int last_index_of(int key) {
		Node<T> *cur = tail;
		int idx = size;
		while (cur) {
			--idx;
			if (cur->value == key)
				return idx;
			cur = cur->prev;
		}
		return -1;
	}

	void to_array(int **p_array) {
		*p_array = new int[size];
		Node<T> *cur = head;
		int idx = -1;
		while (cur) {
			++idx;
			*(*p_array + idx) = cur->value;
			cur = cur->next;
		}
	}

	void to_reversed_array(int **p_array) {
		*p_array = new int[size];
		Node<T> *cur = tail;
		int idx = -1;
		while (cur) {
			++idx;
			*(*p_array + idx) = cur->value;
			cur = cur->prev;
		}
	}
};
#include <iostream>
void print_array(int *p_array, int n) {
	for (int i = 0; i < n; ++i) {
		std::cout << p_array[i] << " ";
	}
	std::cout << std::endl;
}

int main(int argc, char* argv[]) {
	LinkedList<int> linkedList;
	linkedList.push_back(2);
	linkedList.push_back(1);
	linkedList.push_back(4);
	linkedList.push_back(3);
	linkedList.push_back(7);
	linkedList.push_back(8);
	linkedList.push_back(6);
	linkedList.push_back(3);
	linkedList.push_back(5);
	std::cout << linkedList.last_index_of(3) << std::endl;
	std::cout << linkedList.index_of(3) << std::endl;
	std::cout << linkedList.pop_back() << std::endl;
	std::cout << linkedList.pop_front() << std::endl;
	int *p = 0;
	int size = linkedList.size;
	std::cout << size << std::endl;
	linkedList.to_array(&p);
	print_array(p, size);
	delete[] p;
	linkedList.to_reversed_array(&p);
	print_array(p, size);
	delete[] p;
	return 0;
}
