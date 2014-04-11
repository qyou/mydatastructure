#ifndef MY_ARRAY_LIST_H_
#define MY_ARRAY_LIST_H_
typedef struct tag_my_array_list {
	int* data;
	int max_size;
	int current_size;
} my_array_list, *p_my_array_list;

void init(p_my_array_list this, int size);
void dismiss(p_my_array_list this);
void push_back(p_my_array_list this, int e);
int pop_back(p_my_array_list this);

void insert(p_my_array_list this, int pos, int e);
int find(p_my_array_list this, int e);
int at(p_my_array_list this, int pos);

void clear(p_my_array_list this);

#endif//MY_ARRAY_LIST_H_
