#include <iostream>
#include <vector>
#include "BinaryTree.h"
#include "node.h"



int main ()
{
	//objects
	BinaryTree* binaryTree = new BinaryTree();
	
	std::vector<int> b_data;
	b_data.push_back(6);
	b_data.push_back(14);
	b_data.push_back(5);
	b_data.push_back(8);
	b_data.push_back(11);
	b_data.push_back(18);

	//create new node
	node* treeRoot = new node;
	treeRoot->data = 10;
	treeRoot->leftChild = nullptr;
	treeRoot->rightChild = nullptr;

	int size = b_data.size();

	for (int i = 0; i < size; i ++)
	{
		int temp = b_data[i];

		binaryTree->insertNode(temp, treeRoot);
	}

	std::cin.get();

	delete binaryTree;
	return 0;
}