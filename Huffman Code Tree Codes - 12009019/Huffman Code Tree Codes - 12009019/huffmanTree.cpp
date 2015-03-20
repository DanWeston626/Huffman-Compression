#include "huffmanTree.h"

#include <string>

//populate priority queue for huffman code tree
void huffmanTree::createLeafNodes()
{
	//create vector to store data for queue
	vector<data*>* leafNodes = new vector<data*>;

	//create leaf nodes
	data *mData =  new data;
	leafNodes->push_back(mData);
	(*leafNodes)[0]->letter = "r";
	(*leafNodes)[0]->frequency = 1;

	mData =  new data;
	leafNodes->push_back(mData);
	(*leafNodes)[1]->letter = "n";
	(*leafNodes)[1]->frequency = 1;

	mData =  new data;
	leafNodes->push_back(mData);
	(*leafNodes)[2]->letter = "e";
	(*leafNodes)[2]->frequency = 2;

	mData =  new data;
	leafNodes->push_back(mData);
	(*leafNodes)[3]->letter = "b";
	(*leafNodes)[3]->frequency = 2;

	mData =  new data;
	leafNodes->push_back(mData);
	(*leafNodes)[4]->letter = "t";
	(*leafNodes)[4]->frequency = 3;

	mData =  new data;
	leafNodes->push_back(mData);
	(*leafNodes)[5]->letter = "o";
	(*leafNodes)[5]->frequency = 4;

	mData =  new data;
	leafNodes->push_back(mData);
	(*leafNodes)[6]->letter = "_";
	(*leafNodes)[6]->frequency = 5;


	//set up priority queue
	priority_queue<data*, vector<data*>, compare>* huffmanQueue = new priority_queue<data*, vector<data*>, compare>;
	//add all leaf nodes to queue
	for(int i = 0; i < leafNodes->size(); i ++)
	{
		huffmanQueue->push((leafNodes)->at(i));
	}

	createHuffmanTree(huffmanQueue);

	//clean up objects
	delete leafNodes;
}

//create huffman code tree
void huffmanTree::createHuffmanTree(priority_queue<data*, vector<data*>, compare>* huffmanTree)
{
	//create vector to store parent nodes
	vector<data*>* parent = new vector<data*>;
	data* _node;
	data* _firstLeaf;
	data* _secondLeaf;
	int pos = 0;
	//create huffman tree
	while (huffmanTree->size() > 1)
	{
		int lFreq, rFreq, freq;
		string _fLetter;
		string _sLetter;

		//set up data node in vect
		_node = new data;
		parent->push_back(_node);

		//remove first node from tree
		_firstLeaf = huffmanTree->top();
		_fLetter = _firstLeaf->letter;
		lFreq = _firstLeaf->frequency;
		(*parent)[pos]->frequency = lFreq;
		huffmanTree->pop();			

		//remove next node in queue
		_secondLeaf = huffmanTree->top();		
		_sLetter = _secondLeaf->letter;
		rFreq = _secondLeaf->frequency; //get frequency of current node
		huffmanTree->pop();

		//create new node with last two nodes as children
		(*parent)[pos]->rightChild = new data;
		(*parent)[pos]->rightChild = _firstLeaf;
		(*parent)[pos]->rightChild->huffmanCode = 1;

		(*parent)[pos]->leftChild = new data; //create right child
		(*parent)[pos]->leftChild = _secondLeaf; //place first node to right child
		(*parent)[pos]->leftChild->huffmanCode = 0;

		//set the frequency to combined children 
		(*parent)[pos]->letter = _sLetter += _fLetter;		
		freq = lFreq + rFreq;
		(*parent)[pos]->frequency = freq;

		//push combined nodes back into queue	
		huffmanTree->push((parent)->at(pos));
		pos++;	
	}
	delete parent;

	//create huffman codes for nodes in tree
	createHuffmanCodes(huffmanTree);
}

//produce huffman codes for tree
void huffmanTree::createHuffmanCodes(priority_queue<data*, vector<data*>, compare>* huffmanTree)
{
	//get tree in vect 
	vector<data*>* huffTree = new vector<data*>;
	data* tree = new data;
	huffTree->push_back(tree);
	(*huffTree)[0] = huffmanTree->top();
	//huffmanTree->pop();

	tree = (*huffTree)[0];
	string codeString;
	map<string, string>* codeMap = new map<string,string>;

	//codeString =  "0";
	generateCode(tree, (*codeMap), codeString);
	codeString.clear();
	//codeString = "1";
	//generateCode(tree->rightChild, (*codeMap), codeString, "1");

	//clean up objects
	delete huffmanTree;
}

void huffmanTree::generateCode(data* currentNode, map<string, string> &codes, string &code)
{
	if((*currentNode).leftChild == nullptr && (*currentNode).rightChild == nullptr)
	{		
		//parentCode += code;
		codes.insert(std::make_pair(currentNode->letter, code));
	}	
 	if((*currentNode).leftChild != nullptr)	
	{
		generateCode(currentNode->leftChild, codes, code += "0");
	} 
	if((*currentNode).rightChild != nullptr)	
	{
		generateCode(currentNode->rightChild, codes, code += "1");	
	}

	//make sure string is not empty
	if(!(code.empty()))
	{
		code.pop_back();
	}
}
