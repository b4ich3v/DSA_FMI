#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{

    std::string str;
    std::cin >> str;

    int N = str.size();
    std::vector<std::pair<int, int>> counter(500);

    for (int i = 0; i < 500; i++)
    {

        counter[i].first = 0;
        counter[i].second = -1;

    }

    for (int i = 0; i < N; i++) 
    {

        counter[(int)str[i]].first++; 
        counter[(int)str[i]].second = i;
       
    }

    for (int i = 0; i < N; i++)
    {

        if(counter[(int)str[i]].first == 1) std::cout << counter[(int)str[i]].second << " ";

    }

    return 0;

}

