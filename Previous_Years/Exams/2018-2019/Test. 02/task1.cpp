#include <iostream>
#include <vector>

void merge(std::vector<int>& array, int left, int middle, int right) 
{

    int L = middle - left + 1;
    int R = right - middle;

    std::vector<int> leftArray(L), rightArray(R);

    for (int i = 0; i < L; i++) leftArray[i] = array[left + i];
    for (int i = 0; i < R; i++)  rightArray[i] = array[middle + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < L && j < R) 
    {

        if (leftArray[i] <= rightArray[j])
        {

            array[k] = leftArray[i];
            i++;

        }
        else 
        {

            array[k] = rightArray[j];
            j++;

        }

        k++;

    }

    while (i < L) 
    {

        array[k] = leftArray[i];
        i++;
        k++;

    }

    while (j < R)
    {

        array[k] = rightArray[j];
        j++;
        k++;

    }

    if (left != 0 || right != array.size() - 1)
    {

        for (int i = left; i <= right; i++) std::cout << array[i] << " ";
        for (int i = left; i <= right; i++) std::cout << array[i] << " ";

    }

}

void mergeSort(std::vector<int>& array, int left, int right)
{

    if (left < right) 
    {

        int middle = left + (right - left) / 2;

        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);
        merge(array, left, middle, right);

    }

}

int main() 
{

    int N;
    std::cin >> N;

    std::vector<int> array(N);
    for (int i = 0; i < N; i++) std::cin >> array[i];

    mergeSort(array, 0, N - 1);
    for (int i = 0; i < N; i++) std::cout << array[i] << " ";

    return 0;

}

