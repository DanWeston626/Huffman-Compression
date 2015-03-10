#include "huffmanData.h"
#include "node.h"
#include <iostream>
#include <queue>
#include <vector>
using std::priority_queue;
using std::vector;
using std::cout;
using std::cin;




int main ()
{
	//create vector to store data for queue
	vector<data*>* leafNodes = new vector<data*>;

	//create leaf nodes
	data *mData =  new data;
	leafNodes->push_back(mData);
	(*leafNodes)[0]->letter = ' ';
	(*leafNodes)[0]->frequency = 302;

	mData =  new data;
	leafNodes->push_back(mData);
	(*leafNodes)[1]->letter = ',';
	(*leafNodes)[1]->frequency = 15;

	mData =  new data;
	leafNodes->push_back(mData);
	(*leafNodes)[2]->letter = '.';
	(*leafNodes)[2]->frequency = 20;

	mData =  new data;
	leafNodes->push_back(mData);
	(*leafNodes)[3]->letter = 'd';
	(*leafNodes)[3]->frequency = 71;

	mData =  new data;
	leafNodes->push_back(mData);
	(*leafNodes)[4]->letter = 'e';
	(*leafNodes)[4]->frequency = 138;

	mData =  new data;
	leafNodes->push_back(mData);
	(*leafNodes)[5]->letter = 'g';
	(*leafNodes)[5]->frequency = 38;


	//set up priority queue
	priority_queue<data*, vector<data*>, compare>* huffmanQueue = new priority_queue<data*, vector<data*>, compare>;
	//add all leaf nodes to queue
	for(int i = 0; i < leafNodes->size(); i ++)
	{
		huffmanQueue->push((leafNodes)->at(i));
	}

	//set up new priority queue for huffman tree
	priority_queue<node*, vector<node*>, compareNode>* huffmanTree = new priority_queue<node*, vector<node*>, compareNode>;

	//create vector to store parent nodes
	vector<node*>* parent = new vector<node*>;
	node* _node;
	data* _leaf;
	int pos = 0;

	//create huffman tree
	do
	{
		int lFreq, rFreq, freq;
		//set up data node in vect
		_node = new node;
		parent->push_back(_node);

		//fail safe check
		if(huffmanQueue->top() != nullptr)
		{
			//remove first node from tree
			_leaf = huffmanQueue->top();
			(*parent)[pos]->leftChild = new data;
			(*parent)[pos]->leftChild = _leaf;
			lFreq = _leaf->frequency;
			huffmanQueue->pop();	

			(*parent)[pos]->frequency = lFreq;
		}

		//make sure
		if(!(huffmanQueue->size() <=1))
		{
			//remove next node in tree and place as right child
			_leaf = huffmanQueue->top();
			(*parent)[pos]->rightChild = new data; //create right child
			(*parent)[pos]->rightChild = _leaf; //place first node to right child
			rFreq = _leaf->frequency; //get frequency of current node
			huffmanQueue->pop();

			//set the frequency of current node to combined freq of node 1 and 2
			freq = lFreq + rFreq;
			(*parent)[pos]->frequency = freq;
		}		

		//push two nodes back into queue
		huffmanTree->push((parent)->at(pos));
		pos++;	

	}while(huffmanQueue->size() > 1);
	//loop while more than one node in queue

	//create root node with last node in the huffmanQueue
	_node = new node;
	parent->push_back(_node);
	_leaf = huffmanQueue->top();
	(*parent)[pos]->root = new data;
	(*parent)[pos]->root = _leaf;
	(*parent)[pos]->frequency = _leaf ->frequency;
	huffmanQueue->pop();

	huffmanTree->push((parent)->at(pos));

	//pause console
	cin.get();

	//clean up objects	
	delete leafNodes;
	delete huffmanQueue;
	delete huffmanTree;
	delete parent;
	delete _node;
	delete _leaf;
	delete mData;
}

