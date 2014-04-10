#include "my_array_stack.h"
#include <stdio.h>
#include <stdlib.h>

void init(p_my_array_stack this, int size) {
	this->max_size = size;
	this->data = malloc(size * sizeof(int));
	this->top = -1;
}

void dismiss(p_my_array_stack this) {
	this->top = -1;
	this->max_size = 0;
	free(this->data);
	this->data = (p_my_array_stack)0;
}

static int is_empty(p_my_array_stack this) {
	if (this->top == -1) return 1;
	else return 0;
}

static int is_full(p_my_array_stack this) {
	if (this->top == this->max_size-1) return 1;
	else return 0;
}

void push(p_my_array_stack this, int element) {
	if (is_full(this)) {
		fprintf(stderr, "Error: is full!\n");
		return;
	}

	this->data[++this->top] = element;
}

int pop(p_my_array_stack this) {
	if (is_empty(this)) {
		fprintf(stderr, "Error: is empty\n");
		return -1;
	}

	return this->data[this->top--];
}
