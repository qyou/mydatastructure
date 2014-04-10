#include "my_array_queue.h"
#include <stdio.h>

int main(int argc, char* argv[]) {
	my_array_queue queue;
	init(&queue, 10);
	for (int i=0; i<10; i++) {
		enqueue(&queue, i);
	}
	enqueue(&queue, 10);
	for (int i=0; i<10; i++) {
		printf("%d ",dequeue(&queue));
	}
	printf("\n");
	dequeue(&queue);

	enqueue(&queue, 4);
	enqueue(&queue, 1);
	enqueue(&queue, 3);
	printf("%d ",dequeue(&queue));
	enqueue(&queue, 8);
	printf("%d ",dequeue(&queue));
	printf("%d ",dequeue(&queue));
	printf("%d ",dequeue(&queue));
	printf("%d ",dequeue(&queue));

	dismiss(&queue);
	return 0;
}
