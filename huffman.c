#include "huffman.h"
#include <stdio.h>
#include <stdlib.h>

void print_output_1(FILE* input_file, FILE* output_file_1, int* priority_of_char){

	const int TOTAL_ASCII = 256; //this is the total number of ASCII characters;

	for(int i = 0; i < TOTAL_ASCII; i++){ //inititalize every value to zero;
		priority_of_char[i] = 0;
	}
	
	while(1){ //count the number of times each char occurs in FILE;

		char c = fgetc(input_file);

		if(feof(input_file)){
			break;
		}

		priority_of_char[(int)c]++;
	}

	for(int i = 0; i < TOTAL_ASCII; i++){ 
		fprintf(output_file_1, "%d\n", priority_of_char[i]); //print frequency of each char to output_file_1
	}
}


void print_output_2(FILE* output_file_2, Node* list){

	for(Node* curr = list; curr != NULL; curr = curr -> next){
		fprintf(output_file_2, "%c:%d->", *(const int*) curr -> ptr, curr -> priority); //print linked list
	}

   fprintf(output_file_2, "NULL\n");

}


void print_output_3(Node* head, char* array, int top, FILE* output_file_3){

	//traverse tree..going left? encode a zero. going right? encode a 1
	if(head -> left != NULL){
		array[top] = '0';
		print_output_3(head -> left, array, top + 1, output_file_3);
	}

	if(head -> right != NULL){
		array[top] = '1';
		print_output_3(head -> right, array, top + 1, output_file_3);
	}

	if(!(head -> left != NULL) && !(head -> right)){
		array[top] = '\0'; //end char* with NULL character to prevent valgrind error
		fprintf(output_file_3, "%c:%s\n", *(const char*) head -> ptr, array);
	}

}


Node* create_tree(Node** left_head, Node** right_head){ //given two node heads, pair them together.

	Node* tree = malloc(sizeof(*tree));
	Node* left_temp =  *left_head;
	Node* right_temp = *right_head;
	

	tree -> ptr = NULL;
	tree -> priority = left_temp -> priority + right_temp -> priority;
	tree -> left = *left_head;
	tree -> right = *right_head;


	return tree;
}

//enque a node that has non null left and right pointers. 
void enqueue_tree(Node** list_head, Node** tree_head){ 

	Node* temp = *list_head;	
	Node* new_node = *tree_head;
	
	
		if(temp != NULL && new_node -> priority - temp -> priority < 0){
			new_node -> next = temp;
			*list_head = new_node;
			return;
		}
		
		while(temp -> next != NULL && new_node -> priority - temp -> next -> priority >= 0){
			temp = temp -> next;
		}

		new_node -> next = temp -> next;
		temp -> next = new_node;

}


void pq_enqueue(Node **pq, const void *new_object, int priority){

	Node* temp;
	Node* new_node;
	
	if(new_object == NULL || priority == 0){ //if priority is zero then nothing needs to be enqueued
		return;
	}
	else{
		temp = *pq;
		new_node = malloc(sizeof(*new_node));
	}

	//assign fields
	new_node -> ptr = (void*) new_object;
	new_node -> priority = priority;
	new_node -> left = NULL;
	new_node -> right = NULL; 
	
	if(temp == NULL){
		new_node -> next = temp;
		*pq = new_node;
	}

	else{
		enqueue_tree(pq, &new_node); //enqueue_tree is essentially a helper function here.
	}

}

Node* stack_pop(Node **stack){ //remove first node from list

	Node* temp = *stack;
	Node* delete = *stack;
	if(temp == NULL){
		return NULL;
	}
		
	temp = temp -> next;
	*stack = temp;

	delete -> next = NULL;

	return delete;
}

void destroy_node(Node *root){ //destroy the linked list

	if(root == NULL){
		return;
	}

	destroy_node(root -> left);
	destroy_node(root -> right);
	free(root);
}

/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
