#ifndef _NODE_H_
#define _NODE_H_

struct node{
	char letter;
	int frequency;
	node* leftChild;
	node* rightChild;
};

#endif