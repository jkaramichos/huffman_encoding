#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "huffman.h"

int main(int argc, char* argv[]){

	//error handling..program must receive 5 inputs including the program executable
	if(argc != 5){
		return EXIT_FAILURE;
	}
	else{
		FILE* input_file = fopen(argv[1], "r");
		FILE* output_file_1 = fopen(argv[2], "w");
		FILE* output_file_2 = fopen(argv[3], "w");
		FILE* output_file_3 = fopen(argv[4], "w");
	
		const int TOTAL_ASCII = 256;

		int priority_array[256];

		print_output_1(input_file, output_file_1, priority_array); //do everything required for output_file 1;
		
		/****enqueue the array that we just created in step 1****/	
		Node* head = NULL;
		char char_array[256];
		
		for(int i = 0; i < TOTAL_ASCII; i++){
			char_array[i] = (char)i;
			pq_enqueue(&head, &char_array[i], priority_array[i]);
		}

		print_output_2(output_file_2, head);

		Node* left_node;
		Node* right_node;
		Node* tree;

		while(1){

			if(head -> next -> next == NULL){ //this is done for the last pairing of the linked list..if this if statement is not done it results in a seg fault
				
				left_node = stack_pop(&head);
				right_node = stack_pop(&head);

				tree = create_tree(&left_node, &right_node); //no need to enqueue this tree node. this is the completed huffman tree.
				break;

			}
			else{
				
				//pop two nodes from linked list then merge them together to create tree
				left_node = stack_pop(&head);
				right_node = stack_pop(&head);

				tree = create_tree(&left_node, &right_node);
				
				enqueue_tree(&head, &tree); //enqueue tree node into list
				
			}

		}

		print_output_3(tree, char_array, 0, output_file_3);
	
		//free all memory
		destroy_node(tree);
		destroy_node(head);
		
		fclose(input_file);
		fclose(output_file_1);
		fclose(output_file_2);
		fclose(output_file_3);
		return EXIT_SUCCESS;
	}

}


/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
