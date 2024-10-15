#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution 
{
public:

    void countingSort(std::string& str)
    {
        int N = str.size();
        if (N == 0) return;
        int K = *max_element(str.begin(), str.end()) + 1;

        std::string output(N, ' ');
        std::vector<int> count(K, 0);

        for (int i = 0; i < N; i++)
        {

            count[str[i]]++;

        }

        for (int i = 1; i < K; i++)
        {

            count[i] += count[i - 1];

        }

        for (int i = N - 1; i >= 0; i--)
        {

            output[count[str[i]] - 1] = str[i];
            count[str[i]]--;

        }

        for (int i = 0; i < N; i++)
        {

            str[i] = output[i];

        }

    }

    char findTheDifference(std::string s, std::string t) 
    {

        countingSort(s);
        countingSort(t);
        int index = 0;

        for (char ch: s)
        {

            if (ch != t[index]) return t[index];
            index++;

        }

        return t[t.size() - 1];

    }

};

