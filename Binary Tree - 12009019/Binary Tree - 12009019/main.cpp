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


	int value;
	//do while loop - used for user to search tree
	do
	{
		//get value to find
		std::cout << "Enter a value to search: " << std::endl;
		std::cin >> value;

		//create a new 'temp' node to hold return
		node* searchedNode = binaryTree->traverseTree(value, treeRoot); 

		//make sure returned node is not null
		if(searchedNode != nullptr)
		{	
			//print the node data
			std::cout<< "Node data: ";
			std::cout<< searchedNode->data << std::endl; 	
		}

		//ask user if they would like to repeat - 1 for yes 0 for no
		std::cout<< "would you like to search again? - yes/no (1/0)" << std::endl;
		std::cin >> value;

		//delete 'temp' node
		delete searchedNode; 
	}while(value != 0);


	//pause console
	std::cin.get();

	//clean up objects 
	delete binaryTree;
	delete treeRoot;
	

	return 0;
}