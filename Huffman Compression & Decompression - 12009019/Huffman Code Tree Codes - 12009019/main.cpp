#include "huffmanTree.h"
#include "SymbolFreq.h"
#include <iostream>
#include <string>

#include <fstream>

using namespace std;

int compressFile();
int decompressFile();

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
		cout << "\t2. Decompress File" << endl;
		cout << "\t3. Exit" << endl;
		cout << endl;
		cout << "\t";
		cin >> choice;
		cout << endl;

		if (choice == 1)
		{
			compressFile();
		}
		else if (choice == 2)
		{
			decompressFile();
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

int decompressFile()
{
	huffmanTree* huffTree = new huffmanTree();	
	string* decompress = new string;
	data* decompressNode = new data;
	map<string, string>* codeMap = new map<string,string>;
	std::ifstream *file = new std::ifstream;
	string* fileName = new string;

	//ask for file name
	cout << "Enter a filename: " << endl;
	cout<< "Files must be in the Working Directory!" << endl; 
	cin >> *fileName;
	cout << endl;

	//open output file and clear content 
	file->open(*fileName, std::ios::binary | std::ios::in);

	//check to see if file opens 
	if (file->is_open())
	{
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
	}
	else 
	{
		cout << "Error, file does not exsit! Please ensure file is in the working directory! " << endl;
	}

	//clean up objects 
	delete file;
	delete fileName;
	delete decompress;
	delete huffTree;
	delete decompressNode;

	return 0;
}
