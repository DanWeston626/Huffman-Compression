/*The BinaryTree class is used to insert new nodes into a Binary Tree using the insertNode and fillNode functions. As well as this the BinaryTree class can traverse a tree and return
the searched value using the traverseTree function*/
#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_
#include "node.h"
#include <iostream>

class BinaryTree
{
public:
	/*recursive function works down tree until finds null*/
	void insertNode(int nodeData, node* currentNode);

	/*searches tree for a value*/
	node* traverseTree(node* currentNode);

private:
	/*fills the 'null' node discovered from instert node*/
	void fillNode(int nodeData, node *currentNode);
	
};
#endif