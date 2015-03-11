#ifndef _HUFFMANDATA_H_
#define _HUFFMANDATA_H_

//struct for node
class data{
public:
	char letter;
	int frequency;
};

//letter frequencies with lowest frequency = highest priority
struct compare
{
	bool operator()(const data* a, const data* b)
	{
		return a->frequency > b->frequency;
	}
};

#endif