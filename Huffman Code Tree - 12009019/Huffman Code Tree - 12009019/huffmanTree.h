/*huffmanTree is a class responsible for creating/populating all the leaf nodes. This is done inside the createLeafNodes function. As well as creating leaf nodes, this class is also responsible for building
a huffman code tree in the createHuffmanTree function*/

#ifndef _HUFFMANTREE_H_
#define _HUFFMANTREE_H_
#include "huffmanData.h"
#include "node.h"
#include <iostream>
#include <queue>
#include <vector>

using std::priority_queue;
using std::vector;
using std::cout;
using std::cin;
using std::string;

class huffmanTree
{
public:
	void createLeafNodes();

	void createHuffmanTree(priority_queue<data*, vector<data*>, compare>* huffQueue);


};
#endif