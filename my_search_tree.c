#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

struct tree_node {
	struct tree_node *left, *right;
	int value;
};


static struct tree_node* form_node(int value) {
	struct tree_node *node = malloc(sizeof(struct tree_node));
	node->left = NULL;
	node->right = NULL;
	node->value = value;
	return node;
}

//static int look_up(struct tree_node* root, int v) {
//	if (root == NULL) return FALSE;
//	if (v == root->value) {
//		return TRUE;
//	} else if (v < root->value) {
//		return look_up(root->left, v);
//	} else {
//		return look_up(root->right, v);
//	}
//}

// if we need to revise the struct node*, we need to pass the pointer to struct node*
struct tree_node* add_node(struct tree_node** root, int v) {
	if (*root == NULL) {
		*root = form_node(v);
	} else {
		if (v <= (*root)->value) {
			add_node(&((*root)->left), v);
		} else {
			add_node(&((*root)->right), v);
		}
	}
	return *root;
}



void destroy_tree(struct tree_node** root) {
	if (*root != NULL) {
		destroy_tree(&((*root)->left));
		destroy_tree(&((*root)->right));
		free(*root);
	}
}

void preorder_traversal(struct tree_node* root) {
	if (root != NULL) {
		fprintf(stdout, "%d ", root->value);
		preorder_traversal(root->left);
		preorder_traversal(root->right);
	}
}

void inorder_traversal(struct tree_node* root) {
	if (root != NULL) {
		inorder_traversal(root->left);
		fprintf(stdout, "%d ", root->value);
		inorder_traversal(root->right);
	}
}

void postorder_traversal(struct tree_node* root) {
	if (root != NULL) {
		postorder_traversal(root->left);
		postorder_traversal(root->right);
		fprintf(stdout, "%d ", root->value);

	}
}
