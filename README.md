# huffman_encoding

Brief Description of Project:

The goal of this project is to learn to create and manipulate linked lists and trees by creating a huffman tree.
Huffman coding is a data compression algorithm where the most frequent character is assigned the smallest value (to take less memory), and the least frequent character is assigned the greatest value. 

If a given text file contains the string "go go gophers". Then 'g' will be encoded in memory as 00 (most frequent char is encoded with only 2 bits). 'r' will be encoded with 1111 (least frequent char taking 4 bits).

output_file_1:
-A file with 256 lines of output
-Each line represents the number of occurrences each ASCII character is in the input file
-For instance, line 65 will represent the frequency 'A' occurs.

output_file_2:
-A file that reprents the linked list of chars from the input file
-This linked list must be enqueued such that the char with the highest frequency/priority appears first.

output_file_3:
-This file will contain the binary stream for every char in the input file

**For a complete description of the assignment: https://engineering.purdue.edu/ece264/17au/hw/HW13
