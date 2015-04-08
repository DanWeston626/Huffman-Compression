
#ifndef _NODE_COMPARATOR_H_
#define _NODE_COMPARATOR_H_
#include "huffmanNode.h"

//custom comparator for the data class
struct compare
{
	bool operator()(const data* a, const data* b)
	{
		return a->frequency > b->frequency;		
	}
};

#endif