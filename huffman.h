#ifndef HUFFMAN_H
#define HUFFMAN_H
#include <stdio.h>


typedef struct _Node 
{
	int priority; //weight
   	void *ptr; //char
   	struct _Node *next; //this is for the linked list
	struct _Node *left;
	struct _Node *right;

} Node;

void print_output_1(FILE* input_file, FILE* output_file_1, int* num_times);

void print_output_2(FILE* output_file_2, Node* head);

void print_output_3(Node* head, char* array, int top, FILE* output_file_3);

Node* create_tree(Node** left_head, Node** right_head);

void pq_enqueue(Node **pq, const void *new_object, int priority);

void destroy_node(Node *list);

void enqueue_tree(Node** list_head, Node** tree_head);
Node *stack_pop(Node **stack);
#endif


/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
