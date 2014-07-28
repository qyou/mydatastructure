#include <iostream>
#include <memory>
#include <stdexcept>
using namespace std;

template<typename T>
class ArrayList {
private:
	enum {
		INIT_CAPACITY = 10
	};
	size_t capacity;
	T *array;

	size_t size;
public:
	ArrayList() :
			capacity(INIT_CAPACITY), array(new T[capacity]), size(0) {
	}
	ArrayList(size_t init_capacity) :
			capacity(init_capacity), array(new T[capacity]), size(0) {
	}
	virtual ~ArrayList() {
		delete[] array;
		array = nullptr;
		size = 0;
	}

	T& operator[](size_t idx) {
		return array[idx];
	}

	bool is_empty() {
		return size == 0;
	}

	bool is_full() {
		return size == capacity;
	}

	void append(T v) {
		if (is_full()) {
			resize();
		}
		array[size++] = v;
	}

	void clear() {
		delete[] array;
		array = nullptr;
		size = 0;
	}

	int index_of(T v) {
		int idx = 0;
		while (idx < size) {
			if (array[idx] == v)
				return idx;
			++idx;
		}
		return -1;
	}

	int last_index_of(T v) {
		int idx = size - 1;
		while (idx >= 0) {
			if (array[idx] == v)
				return idx;
			--idx;
		}
		return -1;
	}

	void resize() {
		capacity >>= 1;
		T *tmp = new T[capacity];
		for (size_t i = 0; i < size; ++i) {
			tmp[i] = array[i];
		}
		delete[] array;
		array = tmp;
	}

	void insert(int idx, T v) {
		if (idx < 0 || idx > size)
			throw new std::out_of_range("Illegal index argument!");
		if (is_full())
			resize();
		for (int i = size - 1; i >= idx; --i) {
			int j = i + 1;
			array[j] = array[i];
		}
		array[idx] = v;
		++size;
	}

	void remove(int idx) {
		if (idx < 0 || idx > size)
			throw new std::out_of_range("Illegal index argument!");
		for (int i = idx+1; i < size; ++i) {
			int j = i - 1;
			array[j] = array[i];
		}
		--size;
	}

};
