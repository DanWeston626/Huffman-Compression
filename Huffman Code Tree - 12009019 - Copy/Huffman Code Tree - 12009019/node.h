#ifndef _NODE_H_
#define _NODE_H_
#include "huffmanData.h"

//class for a node to be used inside a huffman coding tree
class node{
public:
	int frequency;
	data* leftChild;
	data* rightChild;
};

//custom comparator for the node class
struct compareNode
{
	bool operator()(const node* a, const node* b)
	{
		return a->frequency < b->frequency;
	}
};

#endif