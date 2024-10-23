#include <iostream>
#include <vector>
#include <algorithm>

struct nTorka
{
    std::vector<int> array;
    int zeroCount; 

    nTorka() : zeroCount(0) {} 

    nTorka& operator=(const nTorka& other)
    {

        if (this != &other)
        {

            array = other.array;
            zeroCount = other.zeroCount; 

        }

        return *this;

    }

    bool operator > (const nTorka& other) const
    {

        int minSize = std::min(array.size(), other.array.size());

        for (int i = 0; i < minSize; i++)
        {

            if (array[i] > other.array[i]) return true;
            if (array[i] < other.array[i]) return false;

        }

        return array.size() > other.array.size();

    }

    void print() const
    {
    
        int actualSize = array.size() - zeroCount;
        for (int i = 0; i < actualSize; i++) std::cout << array[i];

    }

};

int countOfDigits(int number)
{

    int counter = 0;

    while (number)
    {

        counter++;
        number /= 10;

    }

    return counter;

}

nTorka toNtorka(int number, int realSize)
{

    nTorka result;

    while (number)
    {

        result.array.push_back(number % 10);
        number /= 10;

    }

    std::reverse(result.array.begin(), result.array.end());
    result.zeroCount = realSize - result.array.size(); 
    for (int i = 0; i < realSize - result.array.size(); i++) result.array.push_back(0);
    return result;

}

int main()
{

    int N = 0;
    std::cin >> N;

    std::vector<int> numbers(N);
    for (int i = 0; i < N; i++) std::cin >> numbers[i];

    int maxElement = *max_element(numbers.begin(), numbers.end());
    int digitsCountOfMaxElement = countOfDigits(maxElement);

    std::vector<nTorka> newNumbers(N);
    for (int i = 0; i < N; i++) newNumbers[i] = toNtorka(numbers[i], digitsCountOfMaxElement);
        
    std::sort(newNumbers.begin(), newNumbers.end(), std::greater<nTorka>());

    for (const auto& number : newNumbers) number.print();
    return 0;

}
