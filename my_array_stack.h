#ifndef MY_ARRAY_STACK_H_
#define MY_ARRAY_STACK_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct tag_my_array_stack {
	int* data;
	int max_size;
	int top;

} my_array_stack, *p_my_array_stack;

void init(p_my_array_stack this, int size);
void push(p_my_array_stack this, int element);
int pop(p_my_array_stack this);
void dismiss(p_my_array_stack this);
#ifdef __cplusplus
}
#endif

#endif//MY_ARRAY_STACK_H_
