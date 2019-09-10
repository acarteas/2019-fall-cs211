#ifndef RANDOM_NUMBER_GENERATOR_H
#define RANDOM_NUMBER_GENERATOR_H

#include <ctime> //for time() function
#include <cstdlib> //for rand() / srand()
#include <iostream>
using namespace std; //import std function

class RandomNumberGenerator
{
public:
	RandomNumberGenerator(int seed = -1)
	{
		//use time-based seed if none was specified
		if (seed == -1)
		{
			srand((unsigned int)time(NULL));
		}
		else
		{
			srand(seed);
		}
	}

	unsigned int getInt(unsigned int min = 0, unsigned int max = RAND_MAX) const
	{
		//make sure that we were passed in okay values
		if (min > max)
		{
			min = 0;
			max = RAND_MAX;
		}
		unsigned int result = (rand() % (max + 1 - min)) + min;
		return result;
	}


};

#endif