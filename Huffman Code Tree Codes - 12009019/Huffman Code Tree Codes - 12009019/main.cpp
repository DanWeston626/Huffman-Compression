#include "huffmanTree.h"
#include <iostream>
#include <string>

#include <fstream>

using namespace std;

void main ()
{
	//Objects
	huffmanTree* huffTree = new huffmanTree();	
	//Variables
	string* inputFile = new string;
	string* fileContent = new string;
	string* bitStream = new string;
	data* parentNode = new data;
	map<char, int>* freqMap = new map<char, int>;
	map<string, string>* codeMap = new map<string,string>;
	priority_queue<data*, vector<data*>, compare>* huffmanQueue = new priority_queue<data*, vector<data*>, compare>;

	//ask for file name
	cout << "Enter a filename: ";
	cin >> *inputFile;
	cout << endl;

	//get contense of file
	*fileContent = huffTree->returnFile(*inputFile);

	//create frequency map of file 
	huffTree->calFreq(*freqMap, *fileContent);
	cout<<"Character and Frequencies: " << endl;
	 //print frequencies and characters
	for(auto it = (*freqMap).cbegin(); it != (*freqMap).cend(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}

	//create leaf nodes
	huffTree->createLeafNodes(freqMap, huffmanQueue);

	//create huffman tree
	*parentNode = huffTree->createHuffmanTree(huffmanQueue);

	//generate huffman codes
	string codeString;
	huffTree->generateCode(parentNode->leftChild, (*codeMap), codeString);
	huffTree->generateCode(parentNode->rightChild, (*codeMap), codeString);
	
	//print codes
	cout<<endl;
	cout<<"Huffman Codes From Data: " << endl;
	for(auto it = (*codeMap).cbegin(); it != (*codeMap).cend(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}

	string huffmanTable;
	huffTree->encodeTree(parentNode, huffmanTable);

	//compress data
	huffTree->compress((*codeMap), *fileContent, parentNode, huffmanTable);


	//pause console
	cin.ignore();
	cin.get();
	

	//clean up objects 
	delete huffTree;
	delete huffmanQueue;
	delete parentNode;
	delete freqMap;
	delete codeMap;
	delete fileContent;
	delete inputFile;
}

