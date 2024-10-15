#include <iostream>
#include <vector>
#include <utility>

using namespace std;

template <typename T>

void printVector(const vector<T>& arr)
{

    for (const auto& elem : arr)
    {

        cout << elem << " ";

    }

    cout << endl;

}

void selectionSort(vector<int>& arr, bool verbose = false)
{

    int N = arr.size();

    for (int i = 0; i < N - 1; i++)
    {

        int min_index = i;

        if (verbose)
        {

            cout << "Start of " << i + 1 << " iteration: ";
            printVector(arr);

        }

        for (int j = i + 1; j < N; j++)
        {

            if (arr[j] < arr[min_index])
            {

                min_index = j;

            }

        }

        if (min_index != i)
        {

            swap(arr[min_index], arr[i]);

        }

        if (verbose)
        {

            std::cout << "min_index = " << min_index << " ------> ";
            printVector(arr);
            std::cout << "=================\n";

        }

    }

}

void worstCaseSelectionSort(int N)
{

    vector<int> arr(N);
    int swaps = 0;

    arr[0] = N;
    for (int i = 1; i < N; i++)
    {

        arr[i] = i;

    }

    cout << "Initial array: ";
    printVector(arr);

    for (int i = 0; i < N - 1; i++)
    {

        int min_index = i;

        for (int j = i + 1; j < N; j++)
        {

            if (arr[j] < arr[min_index])
            {

                min_index = j;

            }

        }

        if (min_index != i)
        {

            swap(arr[min_index], arr[i]);
            swaps++;

        }

    }

    cout << "Sorted array: ";
    printVector(arr);
    cout << "Total swaps: " << swaps << endl;
    cout << "Expected swaps: " << N - 1 << endl;

}

void selectionSortPairs(vector<pair<int, string>>& arr, bool verbose = false)
{

    int N = arr.size();

    for (int i = 0; i < N - 1; i++)
    {

        int min_index = i;

        for (int j = i + 1; j < N; j++)
        {
       
            if (arr[j].first < arr[min_index].first)
            {

                min_index = j;

            }

        }

        if (min_index != i)
        {

            swap(arr[min_index], arr[i]);

        }

    }

    cout << "Sorted pairs:\n";

    for (const auto& p : arr)
    {

        cout << "(" << p.first << ", " << p.second << ") ";

    }

    cout << endl;

}

int main()
{
 
    cout << "Standard Selection Sort:\n";
    vector<int> arr1 = { 9, 4, 3, 2, 6, 7, 1, 8, 5 };
    selectionSort(arr1, true);
    cout << "Final sorted array: ";
    printVector(arr1);
    cout << endl;

 
    cout << "Worst Case Selection Sort:\n";
    worstCaseSelectionSort(10);
    cout << endl;


    cout << "Selection Sort for Pairs:\n";
    vector<pair<int, string>> arr2 = { {2, "woman"}, {1, "a"}, {1, "b"}, {2, "man"}, {1, "c"} };
    selectionSortPairs(arr2);

    return 0;

}
