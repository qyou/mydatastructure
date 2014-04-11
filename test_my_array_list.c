#include "my_array_list.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[]) {
	my_array_list lis;
	init(&lis, 10);
	push_back(&lis, 4);
	push_back(&lis, 1);
	push_back(&lis, 3);
	push_back(&lis, 2);
	push_back(&lis, 5);

	insert(&lis, 1, 100);
	for (int i=0; i<lis.current_size; ++i) {
		printf("%d ", at(&lis, i));
	}
	dismiss(&lis);
	return 0;
}
