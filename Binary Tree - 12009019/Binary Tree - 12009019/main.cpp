#include <iostream>
#include <vector>
#include "BinaryTree.h"
#include "node.h"

int main ()
{
	//objects
	BinaryTree* binaryTree = new BinaryTree();
	
	//create vector and push back random values
	std::vector<int> b_data;
	b_data.push_back(12);
	b_data.push_back(7);
	b_data.push_back(10);
	b_data.push_back(16);
	b_data.push_back(22);
	b_data.push_back(9);

	//create new node - this is the root
	node* treeRoot = new node;
	treeRoot->data = 10;
	treeRoot->leftChild = nullptr;
	treeRoot->rightChild = nullptr;

	//get size of vect 
	int size = b_data.size();

	//loop around vect creating binary tree
	for (int i = 0; i < size; i ++)
	{
		//current vect var
		int temp = b_data[i];
		//insert new node into binary tree 
		binaryTree->insertNode(temp, treeRoot);
	}

	//print root node
	std::cout<< "Root Node: ";
	std::cout << treeRoot->data << std::endl;

	//set up binary tree to hold current node
	node* searchedNode = new node;
	*searchedNode = *treeRoot;

	//do while loop - used for user to search tree
	do
	{
		//node for swapping
		node* returnNode = new node;
		
		//go right down the tree
		returnNode = binaryTree->traverseTree(searchedNode->rightChild);
		*searchedNode = *returnNode;

		//print node if it's not null
		if(searchedNode != nullptr)
		{	
			//print the node data
			std::cout<< "Right Child: ";
			std::cout<< returnNode->data << std::endl; 	
		}

		//clean up swapping node
		delete returnNode;
	}while(searchedNode->rightChild != nullptr);


	//pause console
	std::cin.get();

	//clean up objects 
	delete binaryTree;
	delete treeRoot;
	delete searchedNode; 

	return 0;
}