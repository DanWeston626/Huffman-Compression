#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_
#include "node.h"


class BinaryTree
{
public:
	
	void traverseTree();
	void insertNode(int nodeData, node* currentNode);
};
#endif