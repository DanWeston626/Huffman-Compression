/*main sets up inital variables and calls functions from other objects*/
#include "SymbolFreq.h" 
#include <map>
#include <iostream>

int main ()
 {
	 //variables
	 map<char, int>* freqMap = new map<char, int>;
	 string input;
	 //objects
	 SymbolFreq* getFreq = new SymbolFreq();

	 //get file contense
	 input  = getFreq->returnFile(input);
	 //cal freq for input string
	 getFreq->calFreq((*freqMap), input);

	 //print map 
	for(auto it = (*freqMap).cbegin(); it != (*freqMap).cend(); ++it)
	{
		std::cout << it->first << " " << it->second << std::endl;
	}

	//pause console
	std::cin.get();
	
	//delete objects
	delete getFreq;
	//delete map
	delete freqMap; 

	//end program
	 return 0;
 }
