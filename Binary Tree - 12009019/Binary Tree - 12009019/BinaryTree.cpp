#include "BinaryTree.h"

/*insertNode is a recursive function that traverses a tree until child node is null
when the child node is null, the function inserts a new node*/
void BinaryTree::insertNode(int nodeData, node* currentNode)
{
	/****************/
	/*Left Children*/
	/**************/
	//if the current data is less than the currentNodes data then go lef
	if(nodeData < currentNode->data)
	{
		//if the current nodes left child is not null the move down again
		if (currentNode->leftChild != nullptr)
		{
			//recuursive function call
			insertNode(nodeData, currentNode->leftChild);
		}
		//else insert new node
		else 
		{
			currentNode->leftChild = new node;
			currentNode->leftChild->data = nodeData;
			currentNode->leftChild->rightChild = nullptr;
			currentNode->leftChild->leftChild = nullptr;

		}
	}

	/*****************/
	/*Right Children*/
	/***************/
	
	else if(nodeData >=currentNode->data)
	{
		if (currentNode->rightChild != nullptr)
		{
			insertNode(nodeData, currentNode->rightChild);
		}
	
		else 
		{
			currentNode->rightChild = new node;
			currentNode->rightChild->data = nodeData;
			currentNode->rightChild->rightChild = nullptr;
			currentNode->rightChild->leftChild = nullptr;
		}
	}
	
}

void BinaryTree::traverseTree()
{
}