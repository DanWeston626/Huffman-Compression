#include "SymbolFreq.h"

/*open file and return contense in a string variable*/
string SymbolFreq::returnFile(string message)
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
void SymbolFreq::calFreq(map<char, int> &freqMap, string input)
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
