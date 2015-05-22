/*SymbolFreq contains two functions; the first of these is returnFile, returnFile reads in a file ('richardiii.txt') and
returns the contense as a string. The second function is calFreq, calFreq takes two paremeters, one being a map and the other a
string. calFreq iterates over the string and places individual characters into the map, if the character has already been placed
in the map, the frequency is incremented, otherwise the character is insteretd into the map. */

#ifndef _SymbolFreq_H_
#define _SymbolFreq_H_
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <set>

using std::string;
using std::map;


//other method as opposed to map was to use a struct
//struct letterFreq
//{
//	char letter;
//	int freq;
//};


class SymbolFreq
{
public:
	void calFreq(map<char, int> & freqMap, string input);

};

#endif