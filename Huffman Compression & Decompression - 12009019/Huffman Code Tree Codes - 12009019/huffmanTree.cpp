#include "huffmanTree.h"

#include <iterator> 
#include <string>
#include <bitset>


//open file and return contense in a string variable
string huffmanTree::returnFile(string fileName)
{	
	string message;
	/*create file object*/
	std::ifstream infile;
	/*open text file*/
	infile.open(fileName);
	/*read file, store contense to message string*/
	if (infile.is_open())
	{
		getline(infile,message);
		/*close file*/
		infile.close();
	}
	else
	{
		cout<< "Error! File does not exsit! " << endl;
	}
	/*return file*/
	return message;
}

//populate priority queue for huffman code tree
void huffmanTree::createLeafNodes(map<char, int>* freqMap, priority_queue<data*, vector<data*>, compare>* huffmanQueue)
{
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
}

//create huffman code tree
data huffmanTree::createHuffmanTree(priority_queue<data*, vector<data*>, compare>* huffmanTree)
{
	//create vector to store parent nodes
	vector<data*>* parent = new vector<data*>;
	data* _node;
	data* _firstLeaf;
	data* _secondLeaf;
	data* _parentNode;
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

	//create root node
	_parentNode = huffmanTree->top();
	huffmanTree->pop();

	return *_parentNode;	
}

//function creates huffman codes for nodes in a huffman tree
void huffmanTree::generateCode(data* currentNode, map<string, string> &codes, string code)
{
	//if the left and right child is null - end of tree
	if((*currentNode).leftChild == nullptr && (*currentNode).rightChild == nullptr)
	{		
		codes.insert(std::make_pair(currentNode->letter, code));
	}	
	//else recursivally call function - working down tree
 	if((*currentNode).leftChild != nullptr)	
	{
		generateCode(currentNode->leftChild, codes, code + "0");
	} 
	if((*currentNode).rightChild != nullptr)	
	{
		generateCode(currentNode->rightChild, codes, code + "1");	
	}
}

//function compresses the message in the text file producing a compressed text file
void huffmanTree::compress(map<string, string> &codes, string input)
{
	//iterator for codeMap
	map<string, string>::iterator* inputMap = new map<string, string>::iterator;
	
	string bitStream;
	string currentCode;
	//loop over the input string length
	for (int chrPos = 0; chrPos < input.length(); chrPos ++)
	{
		//get the current character in string
		string currentChar;	
		currentChar = input[chrPos];

		//search the map for current char
		(*inputMap) = codes.find(currentChar);
		//add current byte to stream
		currentCode += (*inputMap)->second;	
		
	}

	//get the current length of the string 
	int length = input.length();
	
	//if the length is not divisble by 8 add padding
	int padAmount = 0;
	while (!(length % 8 == 0))
	{
		currentCode += "0";
		length = currentCode.length();

		padAmount++;
	}
		

	//open/create file to write bit stream too
	std::fstream *file = new std::fstream;
	//open output file and clear content 
	file->open("output.dat", std::fstream::out |std::fstream::binary | std::fstream::trunc);

	//write out number of codes
	unsigned char codeAmount = codes.size();
	file->put(codeAmount);	

	//write huffman codes to file
	for (auto const &huffTableIt : codes)
	{
		//write character
		string m_char = huffTableIt.first;
		(*file) << m_char;

		//write out the size of the code
		unsigned char sizeOfCode = huffTableIt.second.size();
		file->put(sizeOfCode);

		int length = huffTableIt.second.length();

		//Write out the actual code
		*file << huffTableIt.second;


		//unsigned char byte = 0;
		//for (unsigned bit = 0; bit != huffTableIt.second.length(); ++bit)
		//{
		//	if (bit < huffTableIt.second.length())
		//	{
		//		byte |= (huffTableIt.second[bit] & 1) << bit;
		//	}
		//}
		//file->put(byte);
	}	

	//write out number of padding bits
	unsigned char codePadding = padAmount;
	file->put(padAmount);	


	//write out message 
	for (int i = 0; i < currentCode.length(); i +=8)
	{
		unsigned char byte = 0;
		string eightBits;

		//if there are 8 avaible bits
		if(i+8 < currentCode.length())
		{
			//copy eight bits into string
			eightBits = currentCode.substr(i, 8);
		}
		else 
		{
			//just get remaining bits
			eightBits = currentCode.substr(i, currentCode.length());
		}

		//loop over eight bits in substring
		for (unsigned bit = 0; bit != 8; ++bit)
		{
			if (bit < eightBits.length())
			{
				byte |= (eightBits[bit] & 1) << bit;
			}
			else
			{
				byte |= 0 << bit;
				padAmount++;
			}

		} 
		//place new byte in file
		file->put(byte);
	}

	//close file
	file->close();
	//clean up objects 
	delete inputMap;
	delete file;
}

/*DECOMPRESSION FUNCTIONS*/
//get tree reads the file and returns the hufmman table with characters and huffman codes
void huffmanTree::getTree(map<string, string> & huffCodeMap, std::ifstream *outputfile)
{
	char fileBit;
	char code;
	int amountOfCodes;
	int sizeOfCode;

	//get the amount of codes stored in file
	outputfile->get(fileBit);
	amountOfCodes = fileBit;

	//loop until code amount has been met
	for (int i = 0; i < amountOfCodes; i ++)
	{
		//get the character
		outputfile->get(fileBit);
		unsigned char bit = fileBit;
		
		//get size of code
		outputfile->get(fileBit);
		int codeSize = fileBit;
		

		//get code as binary string
		string binaryString;
		//loop for code size
		for (int i = 0; i < codeSize; i++)
		{	
			//pull out bit and append to binary string
			outputfile->get(fileBit);
			binaryString += fileBit;
		}

		//turn character into string
		string character;
		character.push_back(bit);
		
		//push into map
		huffCodeMap.insert(std::make_pair(character, binaryString));
	}
}
//get message reads the file and returns its contense as a stream of 1's and 0's 
string huffmanTree::getMessage(std::ifstream *outputfile, int &paddingBits)
{
	char fileBit;
	string message;
	unsigned char leng;
	
	//get the amount of padding bits 
	outputfile->get(fileBit);
	paddingBits = fileBit;

	//loop over the rest of the file to get compressed message
	while(outputfile->get(fileBit))
	{
		//get the next bit
		//outputfile->get(fileBit);
		unsigned char bit = fileBit;

		//get 8 bit binary 
		string binaryString;
		for (unsigned char i = 128, j = 0; i > 0; i >>= 1, j++)
		{
			binaryString += (bit % 2) + '0';
			bit /= 2;
		} 		

		//place binary string into message
		message += binaryString;
	}

	return message;
}
//decompress message takes the string from get message and 
void huffmanTree::decompressMessage(map<string, string> & huffCodeMap, string message,int paddingBits)
{
	//starting positon for substring
	int startPos = 0;


	int length = 0;// message.length() - paddingBits;
	//loop over message length
	for (int i = 0; i < message.length(); i ++)	
	{
		//if the amount of characters found is equal to the length minus padding STOP 
		if (length == message.length() - paddingBits)
		{
			break;
		}
		//loop over map
		for(auto it = huffCodeMap.cbegin(); it != huffCodeMap.cend(); ++it)
		{
			//get current code at map pos
			string binaryString = it->second;
			//get the current binary sub string
			string binarySub = message.substr(startPos, it->second.length());
			
			if(binarySub == binaryString)
			{
				//if match is found output character
				cout << it->first;
				//move along the starting position
				startPos = startPos + it->second.length();

				//add up characters
				length = length + it->second.length();
							
				break;
			}

		}		
	}


	

}

