#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:

	int findPermutationDifference(std::string s, std::string t)
	{

		int result = 0;

		for (int i = 0; i < s.size(); i++)
		{

			for (int j = 0; j < s.size(); j++)
			{

				if (s[i] == t[j]) { result += std::abs(i - j); break; }

			}

		}

		return result;

	}

};
