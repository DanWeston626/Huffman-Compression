/*huffmanTree is a class responsible for creating/populating all the leaf nodes. This is done inside the createLeafNodes function. As well as creating leaf nodes, this class is also responsible for building
a huffman code tree in the createHuffmanTree function*/

#ifndef _HUFFMANTREE_H_
#define _HUFFMANTREE_H_
#include "huffmanData.h"
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using std::priority_queue;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::map;


class huffmanTree
{
public:
	//returns contense of a given file
	string returnFile(string message);
	void calFreq(map<char, int> & freqMap, string input);

	//fills priority queue with leaf nodes
	void createLeafNodes(map<char, int>* freqMap, priority_queue<data*, vector<data*>, compare>* huffmanQueue);
	//uses leaf nodes for createLeafNodes to create a priority tree
	data createHuffmanTree(priority_queue<data*, vector<data*>, compare>* huffmanTree);

	
	//generates the set of huffman codes from a huffman tree
	void generateCode(data *tree,  map<string, string> &codes, string code);
	
	//creates a bit stream using discoverd huffman codes
	void compress(map <string, string> &codes, string input);

	//decompress binary tree from file 
	void getTree(map<string, string> & huffCodeMap, std::ifstream *outputFile);

	//decompress message from file
	string getMessage(std::ifstream *outputfile);

	void decompressMessage(map<string, string> & huffCodeMap, string message);

};
#endif