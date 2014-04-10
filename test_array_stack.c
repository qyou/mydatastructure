#include "my_array_stack.h"
#include <stdio.h>

int main(int argc, char* argv[]) {
	my_array_stack stack;
	init(&stack, 10);
	for (int i=0; i<10; i++) {
		push(&stack, i);
	}
	push(&stack, 10);
	printf("%d\n", stack.top);
	for (int i=0; i<10; i++) {
		printf("%d ", pop(&stack));
	}
	printf("\n");
	pop(&stack);
	dismiss(&stack);
	return 0;
}
