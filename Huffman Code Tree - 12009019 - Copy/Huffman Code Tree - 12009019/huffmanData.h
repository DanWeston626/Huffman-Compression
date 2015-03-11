#ifndef _HUFFMANDATA_H_
#define _HUFFMANDATA_H_

//class for huffman leaf nodes
class data{
public:
	char letter;
	int frequency;
};

//custom comparator for the data class
struct compare
{
	bool operator()(const data* a, const data* b)
	{
		return a->frequency > b->frequency;
	}
};

#endif