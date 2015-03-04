#include "BinaryTree.h"

/*public function - insertNode is a recursive function that traverses a tree until child node is null
when the child node is null, the function inserts a new node and fills the data using the fill node funciton*/
void BinaryTree::insertNode(int nodeData, node* currentNode)
{
	//if the current data is less than the currentNodes data then go lef
	if(nodeData < currentNode->data)
	{
		//if the current nodes left child is not null the move down again
		if (currentNode->leftChild != nullptr)
		{
			//recursive function call
			insertNode(nodeData, currentNode->leftChild);
		}
		//else insert new node
		else 
		{
			//create new node
			currentNode->leftChild = new node;
			//pass the above node to be filled
			fillNode(nodeData, currentNode->leftChild);
		}
	}
	else if(nodeData >=currentNode->data)
	{
		if (currentNode->rightChild != nullptr)
		{
			insertNode(nodeData, currentNode->rightChild);
		}
	
		else 
		{
			currentNode->rightChild = new node;
			fillNode(nodeData, currentNode->rightChild);
		}
	}
	
}

/*public function works down the tree until the currentNodes data is matched with the findData parameter*/
node* BinaryTree::traverseTree(int findData, node *currentNode)
{
	//if the current node is null - then findData doesn't exist in tree
	if(currentNode == nullptr)
	{
		std::cout << "Value does not exsit!" << std::endl;

		return nullptr;
	}
	//if the currentNode data and findData match then node is discovered
	else if (currentNode->data == findData)
	{
		return  currentNode;
	}
	//if no match is found
	else if (currentNode->data != findData)
	{
		//and the find data is greater than the currentNode data - go right
		if(findData >= currentNode->data)
		{
			traverseTree(findData, currentNode->rightChild);
		}
		//otherwise go left!
		else 
		{
			traverseTree(findData, currentNode->leftChild);
		}
	}
}

/*private function fills the passed node with the correct data*/
void BinaryTree::fillNode(int nodeData, node* currentNode)
{
	currentNode->data = nodeData;
	currentNode->rightChild = nullptr;
	currentNode->leftChild = nullptr;
}
