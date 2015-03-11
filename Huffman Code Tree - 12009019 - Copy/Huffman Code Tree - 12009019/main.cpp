#include "huffmanTree.h"
#include <iostream>
using std::cin;




int main ()
{
	//create huffman tree object
	huffmanTree* huffTree = new huffmanTree();	

	huffTree->createLeafNodes();

	//pause console
	cin.get();

	//clean up objects 
	delete huffTree;
}

