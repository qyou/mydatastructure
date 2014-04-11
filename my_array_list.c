#include "my_array_list.h"
#include <stdio.h>
#include <stdlib.h>

void init(p_my_array_list this, int size) {
	this->max_size = size;
	this->data = malloc(size * sizeof(int));
	this->current_size = 0;
}

void dismiss(p_my_array_list this) {
	this->current_size = 0;
	free(this->data);
	this->data = (p_my_array_list)(void* )0;
	this->max_size = 0;
}

static int is_full(p_my_array_list this) {
	return (this->current_size == this->max_size);
}
static int is_empty(p_my_array_list this) {
	return (this->current_size == 0);
}
void push_back(p_my_array_list this, int e) {
	if (is_full(this)) {
		fprintf(stderr, "Error: is full, should reallocate the memory!\n");
		return;
	}
	this->data[this->current_size++] = e;
}

int pop_back(p_my_array_list this) {
	if (is_empty(this)) {
		fprintf(stderr, "Error: is empty. No element to pop!\n");
		return -1;
	}
	return this->data[this->current_size--];
}

static void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void insert(p_my_array_list this, int pos, int e) {
	if (pos < 0 || pos >= this->max_size) {
		fprintf(stderr, "%Error: position is wrong!\n" );
		return;
	}

	if (pos >= this->current_size) {
		
		for (int i=this->current_size; i<pos+1; ++i) {
			this->data[i] = 0;
		}
		this->data[pos] = e;
		this->current_size=pos+1;
		return;
	} 
	this->data[this->current_size] = e;
	for (int i=this->current_size; i>pos; --i) {
		swap(this->data+i, this->data+i-1);
	}
	++this->current_size;
}

int find(p_my_array_list this, int e) {
	for (int i=0; i<this->current_size; i++) {
		if (*(this->data+i) == e) return i;
	}
	return -1;
}

int at(p_my_array_list this, int pos) {
	if (pos < 0 || pos >= this->max_size) {
		fprintf(stderr, "%Error: position is wrong!\n" );
		return;
	}
	return this->data[pos];
}	

void clear(p_my_array_list this) {
	for (int i=0; i<this->current_size; ++i) {
		this->data[i] = 0;
	}
	this->current_size = 0;
}
