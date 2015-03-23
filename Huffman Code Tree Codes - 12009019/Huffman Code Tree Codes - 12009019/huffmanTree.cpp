#include "huffmanTree.h"

#include <string>


//open file and return contense in a string variable
string huffmanTree::returnFile(string message)
{
	
	/*create file object*/
	std::ifstream infile;
	/*open text file*/
	infile.open("richardiii.txt");
	/*read file, store contense to message string*/
	getline(infile,message);
	/*close file*/
	infile.close();

	return message;
}

/*place the charatcers of the string into the map, if the character is already in the map
increment the frequency of the charatcer*/
void huffmanTree::calFreq(map<char, int> &freqMap, string input)
{
    //iterator for &freqMap
	map<char, int>::iterator* inputMap = new map<char, int>::iterator;

	//loop over the input string length
	for (int chrPos = 0; chrPos < input.length(); chrPos ++)
	{
		//take the current charatcer of the string and assign to char
		char currentChar = input[chrPos];

		//search the map for current char
		(*inputMap) = freqMap.find(currentChar);

		//if current letter was not located in map
		if((*inputMap) == freqMap.end())
		{
			//add current letter and +1 freq to map
			freqMap.insert(std::make_pair(currentChar,1));
		}
		else 
		{
			//increment the character frequency
			(*inputMap)->second++;
		}
	}

	//delete dynamic map
	delete inputMap;
}


//populate priority queue for huffman code tree
void huffmanTree::createLeafNodes()
{
	//get file contense
	string input;
	input = returnFile(input);

	//set up map to store character freqs 
	map<char, int>* freqMap = new map<char, int>;
	//cal freq for input string and store in above map
	calFreq((*freqMap), input);

	//set up priority queue
	priority_queue<data*, vector<data*>, compare>* huffmanQueue = new priority_queue<data*, vector<data*>, compare>;

	//create a new leaf for queue
	data* leaf;
	//loop over map
	for(auto it = (*freqMap).cbegin(); it != (*freqMap).cend(); ++it)
	{
		//get data from map
		leaf = new data;
		leaf->letter = (*it).first;
		leaf->frequency = (*it).second;

		//push back new leaf into priority queue
		huffmanQueue->push(leaf);
	}
	
	cout<<"Character and Frequencies: " << endl;

	 //print frequencies and characters
	for(auto it = (*freqMap).cbegin(); it != (*freqMap).cend(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}

	//create a tree from data in queue
	createHuffmanTree(huffmanQueue);

	//clean up ojects 
	delete freqMap;
}

//create huffman code tree
void huffmanTree::createHuffmanTree(priority_queue<data*, vector<data*>, compare>* huffmanTree)
{
	cout << "Creating huffman tree from data!" << endl; 
	cout << endl;

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


	string codeString;
	map<string, string>* codeMap = new map<string,string>;

	//call generateCode to generate codes from tree
	generateCode(huffmanTree->top(), (*codeMap), codeString);
	
	cout<<"Huffman Codes From Data: " << endl;

	 //print codes
	for(auto it = (*codeMap).cbegin(); it != (*codeMap).cend(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}

	//clean up objects
	delete huffmanTree;
	delete codeMap;
	delete parent;
}


//function creates huffman codes for nodes in a huffman tree
void huffmanTree::generateCode(data* currentNode, map<string, string> &codes, string &code)
{
	//if the left and right child is null - end of tree
	if((*currentNode).leftChild == nullptr && (*currentNode).rightChild == nullptr)
	{		
		codes.insert(std::make_pair(currentNode->letter, code));
	}	

	//else recursivally call function - working down tree
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
		//when string is empty and function recursives - pop back last couple of values
		code.pop_back();
	}
}
