#include "huffmanTree.h"

//populate priority queue for huffman code tree
void huffmanTree::createLeafNodes()
{
	//create vector to store data for queue
	vector<data*>* leafNodes = new vector<data*>;

	//create leaf nodes
	data *mData =  new data;
	leafNodes->push_back(mData);
	(*leafNodes)[0]->letter = "r";
	(*leafNodes)[0]->frequency = 1;

	mData =  new data;
	leafNodes->push_back(mData);
	(*leafNodes)[1]->letter = "n";
	(*leafNodes)[1]->frequency = 1;

	mData =  new data;
	leafNodes->push_back(mData);
	(*leafNodes)[2]->letter = "e";
	(*leafNodes)[2]->frequency = 2;

	mData =  new data;
	leafNodes->push_back(mData);
	(*leafNodes)[3]->letter = "b";
	(*leafNodes)[3]->frequency = 2;

	mData =  new data;
	leafNodes->push_back(mData);
	(*leafNodes)[4]->letter = "t";
	(*leafNodes)[4]->frequency = 3;

	mData =  new data;
	leafNodes->push_back(mData);
	(*leafNodes)[5]->letter = "o";
	(*leafNodes)[5]->frequency = 4;

	mData =  new data;
	leafNodes->push_back(mData);
	(*leafNodes)[6]->letter = "_";
	(*leafNodes)[6]->frequency = 5;


	//set up priority queue
	priority_queue<data*, vector<data*>, compare>* huffmanQueue = new priority_queue<data*, vector<data*>, compare>;
	//add all leaf nodes to queue
	for(int i = 0; i < leafNodes->size(); i ++)
	{
		huffmanQueue->push((leafNodes)->at(i));
	}

	delete leafNodes;

	createHuffmanTree(huffmanQueue);
}

//create huffman code tree
void huffmanTree::createHuffmanTree(priority_queue<data*, vector<data*>, compare>* huffQueue)
{
	//set up new priority queue for huffman tree
	priority_queue<node*, vector<node*>, compareNode>* huffmanTree = new priority_queue<node*, vector<node*>, compareNode>;

	//create vector to store parent nodes
	vector<data*>* parent = new vector<data*>;
	data* _node;
	data* _leaf;
	int pos = 0;

	bool loop = true;
	//create huffman tree
	while (loop)
	{
		int lFreq, rFreq, freq;
		string letter;
		//set up data node in vect
		_node = new data;
		parent->push_back(_node);

		//make sure that the top is not null
		if(huffQueue->top() != nullptr)
		{
			//remove first node from tree
			_leaf = huffQueue->top();

			(*parent)[pos]->rightChild = new data;
			(*parent)[pos]->rightChild = _leaf;
			letter = _leaf->letter;
			lFreq = _leaf->frequency;
			huffQueue->pop();	

			(*parent)[pos]->frequency = lFreq;
			(*parent)[pos]->letter = letter;
		}

		//If the current size is equal to one then parent has been found


		//remove next node in tree and place as right child
		_leaf = huffQueue->top();
		(*parent)[pos]->leftChild = new data; //create right child
		(*parent)[pos]->leftChild = _leaf; //place first node to right child
		letter += _leaf->letter;
		rFreq = _leaf->frequency; //get frequency of current node
		huffQueue->pop();

		//set the frequency of current node to combined freq of node 1 and 2
		freq = lFreq + rFreq;
		(*parent)[pos]->frequency = freq;
		(*parent)[pos]->letter = letter;	

		//push two nodes back into queue
		huffQueue->push((parent)->at(pos));
		pos++;	

		if(huffQueue->size() == 1)
		{
			loop = false;
			//push two nodes back into queue
			/*huffQueue->push((parent)->at(pos));
			pos++;	*/
		}
	}
	//loop while more than one node in queue

	//create root node with last node in the huffmanQueue
	/*_node = new data;
	parent->push_back(_node);
	_leaf = huffQueue->top(); 
	(*parent)[pos]->leftChild = new data;
	(*parent)[pos]->leftChild = _leaf;
	(*parent)[pos]->frequency = _leaf ->frequency;
	huffQueue->pop();

	huffQueue->push((parent)->at(pos));*/

	delete huffQueue;
	delete huffmanTree;
}
