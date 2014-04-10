#include "my_array_queue.h"
#include <stdlib.h>
#include <stdio.h>

void init(p_my_array_queue this, int size) {
	this->max_size = size;
	this->data = malloc(size * sizeof(int));
	this->head = this->data;
	this->tail = this->head;
}

void dismiss(p_my_array_queue this) {
	this->max_size = 0;
	free(this->data);
	this->data = (p_my_array_queue)0;
	this->head = this->data;
	this->tail = this->data;
}

static int is_empty(p_my_array_queue this) {
	if (this->head == this->tail) return 1;
	else return 0;
}
static int is_full(p_my_array_queue this) {
	if (this->tail - this->data == this->max_size) return 1;
	else return 0;
}

void enqueue(p_my_array_queue this, int e) {
	if (is_full(this)) {
		if (!is_empty(this)) {
			fprintf(stderr, "Error: full!\n");
			return;
		}
		this->tail = this->data;
		this->head = this->tail;
	}
	*(this->tail)++ = e;
}

int dequeue(p_my_array_queue this) {
	if (is_empty(this)) {
				fprintf(stderr, "Error: is empty!\n");
				return -1;
		} 

	return *(this->head)++;
}
