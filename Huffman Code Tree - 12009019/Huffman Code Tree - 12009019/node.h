#ifndef _NODE_H_
#define _NODE_H_
#include "huffmanData.h"

class node{
public:
	int frequency;
	data* root;
	data* leftChild;
	data* rightChild;
};

struct compareNode
{
	bool operator()(const node* a, const node* b)
	{
		return a->frequency > b->frequency;
	}
};

#endif