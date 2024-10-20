#include <iostream>
#include <vector>
#include <string>

int decodeCharacterToNumber(char ch)
{

    return (ch >= '0' && ch <= '9') ? (ch - '0' + 1) :
        (ch >= 'a' && ch <= 'z') ? (ch - 'a' + 11) :
        (ch >= 'A' && ch <= 'Z') ? (ch - 'A' + 37) : -1;

}

void countingSort(const std::string& input)
{

    std::vector<int> count(62, 0);

    for (char ch : input)
    {

        int number = decodeCharacterToNumber(ch);

        if (number != -1)
        {

            count[number - 1]++;

        }

    }

    std::string sortedOutput;
    sortedOutput.reserve(input.size());

    for (int i = 0; i < 62; ++i)
    {

        if (count[i] > 0)  sortedOutput.append(count[i], (i < 10) ? (i + '0') : (i < 36) ? (i - 10 + 'a') : (i - 36 + 'A'));

    }

    std::cout << sortedOutput << std::endl;

}

int main()
{

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::string input;
    std::cin >> input;

    countingSort(input);

    return 0;

}
