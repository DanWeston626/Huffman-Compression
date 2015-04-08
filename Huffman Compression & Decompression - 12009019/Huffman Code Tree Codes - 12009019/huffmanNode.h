/*Huffman data is the node description for all nodes to be set up in the huffman tree/priority queue. The header contains a class which describes
a  node for the tree. As well as this the header contains a custom comparator to be used for a priority queue */
#ifndef _HUFFMANDATA_H_
#define _HUFFMANDATA_H_
#include <iostream>

using std::string;

//class for huffman leaf nodes
class data{
public:
	string letter;
	int frequency;

	int huffmanCode;
	data* leftChild;
	data* rightChild;	
};

#endif