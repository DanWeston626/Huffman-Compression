#include "huffmanTree.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int compressFile();

void main ()
{
		
	bool loop = true;

	//loop and print menu
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
	string* inputFile = new string;
	string* fileContent = new string;
	string* bitStream = new string;
	data* parentNode = new data;
	map<char, int>* freqMap = new map<char, int>;
	map<string, string>* codeMap = new map<string,string>;
	priority_queue<data*, vector<data*>, compare>* huffmanQueue = new priority_queue<data*, vector<data*>, compare>;

	//get contense of file
	*fileContent = huffTree->returnFile("richardiii.txt");

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
	huffTree->generateCode(parentNode, (*codeMap), codeString);
	//huffTree->generateCode(parentNode->rightChild, (*codeMap), codeString);
	
	//print codes
	cout<<endl;
	cout<<"Huffman Codes From Data: " << endl;
	for(auto it = (*codeMap).cbegin(); it != (*codeMap).cend(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}
	
	cout << endl;
	cout << "Compressing and Saving data to 'output.dat'" << endl;

	//compress data
	huffTree->compress((*codeMap), *fileContent);

	//clean up objects
	delete huffmanQueue;
	delete parentNode;
	delete freqMap;
	delete codeMap;
	delete fileContent;
	delete inputFile;

	//return to menu
	return 0;
}


