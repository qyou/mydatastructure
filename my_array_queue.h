#ifndef MY_ARRAY_QUEUE
#define MY_ARRAY_QUEUE

#ifdef __cplusplus
extern "C" {
#endif
typedef struct tag_my_array_queue {
	int* data;
	int max_size;
	int* head;
	int* tail;
} my_array_queue, *p_my_array_queue;

void init(p_my_array_queue this, int size);
void dismiss(p_my_array_queue);

void enqueue(p_my_array_queue this, int e);
int dequeue(p_my_array_queue this);

#ifdef __cplusplus
}
#endif
#endif//MY_ARRAY_QUEUE
