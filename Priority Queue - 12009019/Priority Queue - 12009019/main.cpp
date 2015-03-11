#include "huffmanData.h"
#include <iostream>
#include <queue>
#include <vector>

using std::priority_queue;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main ()
{
	//create vector to store leaf nodes for priority queue
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

	//get the top of the queue
	data* leaf = new data;
	leaf = huffmanQueue->top();

	//output top off the queue
	cout << "Top of the queue: ";
	cout << leaf->letter << " , " << leaf->frequency << endl;
	cout << "Popping top of the queue" << endl;

	//pop top data memember of queue
	huffmanQueue->pop();

	//get the next memember in the queue
	leaf = new data;
	leaf = huffmanQueue->top();
	cout << "Top of the queue: ";
	cout << leaf->letter << " , " << leaf->frequency << endl;

	//pop top data memember of queue
	huffmanQueue->pop();

	//pause console
	cin.get();

	//clean up objects	
	delete leafNodes;
	delete huffmanQueue;
	delete mData;
	delete leaf;
}

