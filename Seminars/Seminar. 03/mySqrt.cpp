#include <iostream>
#include <vector>
#include <algorithm>

class Solution 
{
public:

    int mySqrt(int x) 
	{

		double iter = 1;

		while (iter * iter <= x)
		{

			if (iter * iter == x) return iter;
			iter++;


		}

		iter--;
		return iter;

    }

};


