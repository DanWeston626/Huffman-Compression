#include "huffmanData.h"
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
	
	vector<data*>* myData = new vector<data*>;
	data *mData =  new data;

	myData->push_back(mData);
	(*myData)[0]->letter = ' ';
	(*myData)[0]->frequency = 302;
	mData =  new data;
	myData->push_back(mData);
	(*myData)[1]->letter = ',';
	(*myData)[1]->frequency = 15;
	mData =  new data;
	myData->push_back(mData);
	(*myData)[2]->letter = '.';
	(*myData)[2]->frequency = 20;
	mData =  new data;
	myData->push_back(mData);
	(*myData)[3]->letter = 'd';
	(*myData)[3]->frequency = 71;
	mData =  new data;
	myData->push_back(mData);
	(*myData)[4]->letter = 'e';
	(*myData)[4]->frequency = 138;

	priority_queue<data*, vector<data*>, compare>* huffmanQueue = new priority_queue<data*, vector<data*>, compare>;

	huffmanQueue->push((myData)->at(0));
	huffmanQueue->push((myData)->at(1));
	huffmanQueue->push((myData)->at(2));
	huffmanQueue->push((myData)->at(3));
	huffmanQueue->push((myData)->at(4));

	data* b = huffmanQueue->top();
	cout << b->letter << " , " << b->frequency << std::endl;
	huffmanQueue->pop();	

	b = huffmanQueue->top();
	cout << b->letter << " , " << b->frequency << std::endl;	
	huffmanQueue->pop();

	b = huffmanQueue->top();
	cout << b->letter << " , " << b->frequency << std::endl;	
	huffmanQueue->pop();

	b = huffmanQueue->top();
	cout << b->letter << " , " << b->frequency << std::endl;	
	huffmanQueue->pop();

	b = huffmanQueue->top();
	cout << b->letter << " , " << b->frequency << std::endl;
	huffmanQueue->pop();




	cin.get();
	delete b;
	delete myData;
}