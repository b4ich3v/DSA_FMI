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

void bubbleSort(vector<int>& arr, bool verbose = false)
{

    int N = arr.size();

    for (int i = 0; i < N - 1; i++)
    {

        if (verbose)
        {

            cout << "Start of iteration " << i + 1 << ": ";
            printVector(arr);

        }
        for (int j = 0; j < N - 1 - i; j++)
        {

            if (arr[j] > arr[j + 1])
            {

                swap(arr[j], arr[j + 1]);

                if (verbose)
                {

                    printVector(arr);

                }

            }

        }
        if (verbose)
        {

            cout << "End of iteration " << i + 1 << ".\n";

        }

    }

}

void optimizedBubbleSort(vector<int>& arr, bool verbose = false)
{

    int N = arr.size();

    for (int i = 0; i < N - 1; i++)
    {

        bool swapped = false;

        if (verbose)
        {

            cout << "Start of iteration " << i + 1 << ": ";
            printVector(arr);

        }

        for (int j = 0; j < N - 1 - i; j++)
        {

            if (arr[j] > arr[j + 1])
            {

                swap(arr[j], arr[j + 1]);
                swapped = true;

                if (verbose)
                {

                    printVector(arr);

                }

            }

        }
        if (verbose)
        {

            cout << "End of iteration " << i + 1 << ".\n";

        }

        if (!swapped)
        {

            break;

        }

    }

}

void evenMoreOptimizedBubbleSort(int* arr, size_t size) 
{

    int lastSwappedIndex = size - 1;

    for (int i = 0; i < size; i++)
    {

        int currentSwappedIndex = -1;

        for (int j = 0; j < lastSwappedIndex; j++)
        {

            if (arr[j] > arr[j + 1]) 
            {

                currentSwappedIndex = j;
                swap(arr[j], arr[j + 1]);

            }

        }

        if (currentSwappedIndex == -1)
        {

            return;

        }

        lastSwappedIndex = currentSwappedIndex;

    }

}

void worstCaseBubbleSort(int N)
{

    vector<int> arr(N);
    int swaps = 0;

    for (int i = 0; i < N; i++)
    {

        arr[i] = N - i;

    }

    cout << "Initial array: ";
    printVector(arr);

    for (int i = 0; i < N - 1; i++)
    {

        for (int j = 0; j < N - 1 - i; j++)
        {

            if (arr[j] > arr[j + 1])
            {

                swap(arr[j], arr[j + 1]);
                swaps++;

            }

        }

    }

    cout << "Sorted array: ";
    printVector(arr);
    cout << "Total swaps: " << swaps << endl;
    cout << "Expected swaps (N * (N - 1) / 2): " << (N * (N - 1)) / 2 << endl;

}

void stableBubbleSort(vector<pair<int, string>>& arr, bool verbose = false)
{

    int N = arr.size();

    for (int i = 0; i < N - 1; i++)
    {

        for (int j = 0; j < N - 1 - i; j++)
        {
        
            if (arr[j].first > arr[j + 1].first)
            {

                swap(arr[j], arr[j + 1]);

            }

        }

    }

    cout << "Stable sorted pairs:\n";

    for (const auto& p : arr)
    {

        cout << "(" << p.first << ", " << p.second << ") ";

    }

    cout << endl;

}

int main()
{
    
    cout << "Standard Bubble Sort:\n";
    vector<int> arr1 = { 9, 4, 3, 2, 6, 7, 1, 8, 5 };
    bubbleSort(arr1, true);
    cout << "Final sorted array: ";
    printVector(arr1);
    cout << endl;

    cout << "Optimized Bubble Sort:\n";
    vector<int> arr2 = { 9, 4, 3, 2, 6, 7, 1, 8, 5 };
    optimizedBubbleSort(arr2, true);
    cout << "Final sorted array: ";
    printVector(arr2);
    cout << endl;

    cout << "Worst Case Bubble Sort:\n";
    worstCaseBubbleSort(50);
    cout << endl;

    cout << "Stable Bubble Sort for Pairs:\n";
    vector<pair<int, string>> arr3 = { {2, "woman"}, {1, "a"}, {1, "b"}, {2, "man"}, {1, "c"} };
    stableBubbleSort(arr3);

    return 0;

}
