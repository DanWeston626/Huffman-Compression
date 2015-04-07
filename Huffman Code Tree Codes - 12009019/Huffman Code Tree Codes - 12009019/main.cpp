#include "huffmanTree.h"
#include <iostream>
#include <string>

#include <fstream>

using namespace std;

void compressFile();
void decompressFile();

void main ()
{
	//print menu 
	
	int choice;
	cout << "\t****HUFFMAN COMPRESSION****" << endl;
	cout << "\t1. Compress File" << endl;
	cout << "\t2. Decompress File" << endl;
	cout << "\t3. Exit" << endl;

	cin >> choice;

	switch (choice)
	{
		case 1:
		{
			compressFile();
		}
		case 2:
		{
			decompressFile();
		}
		case 3:
		{
			decompressFile();
		}
	}
	
}

void compressFile()
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

	delete huffmanQueue;
	delete parentNode;
	delete freqMap;
	delete codeMap;
	delete fileContent;
	delete inputFile;


	main();
}

void decompressFile()
{
	huffmanTree* huffTree = new huffmanTree();	
	string* decompress = new string;
	data* decompressNode = new data;
	map<string, string>* codeMap = new map<string,string>;
		//empty the code map
	(*codeMap).clear();

	//open/create file to write bit stream too
	std::ifstream *file = new std::ifstream;

	//open output file and clear content 
	file->open("output.dat", std::ios::binary | std::ios::in);

	//decompress file and get tree
	huffTree->getTree((*codeMap), file);

	//get compressed bitstream
	*decompress = huffTree->getMessage(file);
	file->close();

	cout<<endl;
	cout<<"Huffman Codes From File: " << endl;
	for(auto it = (*codeMap).cbegin(); it != (*codeMap).cend(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}

	huffTree->decompressMessage((*codeMap), *decompress);
	
	//pause console
	cin.ignore();
	cin.get();	

	//clean up objects 
	delete file;
	delete decompress;
	delete huffTree;
	delete decompressNode;
	delete huffTree;

	main();
}
