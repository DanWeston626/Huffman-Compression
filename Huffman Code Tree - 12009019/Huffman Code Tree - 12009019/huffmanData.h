#ifndef _HUFFMANDATA_H_
#define _HUFFMANDATA_H_
#include <iostream>
using std::string;

//class for huffman leaf nodes
class data{
public:
	string letter;
	int frequency;
	data* leftChild;
	data* rightChild;
};

//custom comparator for the data class
struct compare
{
	bool operator()(const data* a, const data* b)
	{
		return a->frequency > b->frequency;
	}
};

#endif