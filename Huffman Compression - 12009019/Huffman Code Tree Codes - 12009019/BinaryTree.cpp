#include "BinaryTree.h"

/*public function - insertNode is a recursive function that traverses a tree until child node is null
when the child node is null, the function inserts a new node and fills the data using the fill node funciton*/
void BinaryTree::insertNode(int nodeData, node* currentNode)
{
	//if the current data is less than the currentNodes data then go left
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

/*public function works down the tree returing nodes until node is null*/
node* BinaryTree::traverseTree(node *currentNode)
{
	//if the current node is null - then end of tree
	if(currentNode == nullptr)
	{
		std::cout << "end of tree!" << std::endl;
		return nullptr;
	}
	//else return the child 
	else
	{
		return  currentNode;
	}
}

/*private function fills the passed node with the correct data*/
void BinaryTree::fillNode(int nodeData, node* currentNode)
{
	currentNode->data = nodeData;
	currentNode->rightChild = nullptr;
	currentNode->leftChild = nullptr;
}
