#include "huffmanData.h"
#include "node.h"
#include <map>
#include <iostream>
#include <queue>
#include <vector>

using std::priority_queue;
using std::vector;
using std::cout;
using std::cin;
using std::map;

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

	//set up priority queue
	priority_queue<data*, vector<data*>, compare>* huffmanQueue = new priority_queue<data*, vector<data*>, compare>;
	//add all leaf nodes to queue
	for(int i = 0; i < leafNodes->size(); i ++)
	{
		huffmanQueue->push((leafNodes)->at(i));
	}

	priority_queue<data*, vector<data*>, compare>* huffmanTree = new priority_queue<data*, vector<data*>, compare>;

	vector<data*>* children = new vector<data*>;
	data* _child =  new data;
	int pos = 0;
	do
	{
		int lFreq, rFreq, freq;
		//get the top node

		children->push_back(_child);

		_child = huffmanQueue->top();
		(*children)[pos]->rightChild = new data;
		(*children)[pos]->rightChild = _child;
		rFreq = _child->frequency;
		huffmanQueue->pop();

		children->push_back(_child);
		_child = huffmanQueue->top();
		(*children)[pos]->leftChild = new data;
		(*children)[pos]->leftChild = _child;
		lFreq = _child->frequency;
		huffmanQueue->pop();

		freq = lFreq + rFreq;
		(*children)[pos]->frequency = freq;

		huffmanTree->push((children)->at(pos));
		pos++;
		
	}while(huffmanQueue->size() > 1);
	//loop while more than one node in queue	
	

	

	//pause console
	cin.get();

	//clean up objects	
	delete leafNodes;
}