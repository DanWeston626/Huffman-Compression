#include "huffmanTree.h"
#include "SymbolFreq.h"
#include <iostream>
#include <string>

#include <fstream>

using namespace std;

int compressFile();


void main ()
{
	//print menu 
	
	bool loop = true;

	while (loop)
	{
		int choice;
		cout << endl;
		cout << endl;
		cout << "\t****HUFFMAN COMPRESSION****" << endl;
		cout << "\t1. Compress File" << endl;
		cout << "\t2. Exit" << endl;
		cout << endl;
		cout << "\t";
		cin >> choice;
		cout << endl;

		if (choice == 1)
		{
			compressFile();
		}
		else 
		{
			loop = false;
		}

	}
	
}

int compressFile()
{
	//Objects
	huffmanTree* huffTree = new huffmanTree();	
	SymbolFreq* getFreq = new SymbolFreq();
	string* inputFile = new string;
	string* fileContent = new string;
	string* bitStream = new string;
	data* parentNode = new data;
	map<char, int>* freqMap = new map<char, int>;
	map<string, string>* codeMap = new map<string,string>;
	priority_queue<data*, vector<data*>, compare>* huffmanQueue = new priority_queue<data*, vector<data*>, compare>;


	//ask for file name
	cout << "Enter a filename: " << endl;
	cout<< "Files must be in the Working Directory!" << endl; 
	cin >> *inputFile;
	cout << endl;

	//get contense of file
	*fileContent = huffTree->returnFile(*inputFile);

	//if the string is empty don't continue with compression 
	if (!(*fileContent == ""))
	{

		//create frequency map of file 
		getFreq->calFreq(*freqMap, *fileContent);
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
		huffTree->generateCode(parentNode, (*codeMap), codeString);
		//huffTree->generateCode(parentNode->rightChild, (*codeMap), codeString);
	
		//print codes
		cout<<endl;
		cout<<"Huffman Codes From Data: " << endl;
		for(auto it = (*codeMap).cbegin(); it != (*codeMap).cend(); ++it)
		{
			cout << it->first << " " << it->second << endl;
		}
	
		//compress data
		huffTree->compress((*codeMap), *fileContent);
	}

	delete huffmanQueue;
	delete parentNode;
	delete freqMap;
	delete codeMap;
	delete fileContent;
	delete inputFile;


	return 0;
}


