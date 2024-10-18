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

void insertionSort(vector<int>& arr, bool verbose = false)
{

    int N = arr.size();

    for (int i = 1; i < N; i++)
    {

        int key = arr[i];
        int j = i - 1;

        if (verbose)
        {

            cout << "key = " << key << "\n";
            printVector(arr);

        }

        while (j >= 0 && arr[j] > key)
        {

            arr[j + 1] = arr[j];
            j--;

            if (verbose)
            {

                cout << "   ->  ";
                printVector(arr);

            }

        }

        arr[j + 1] = key;

        if (verbose)
        {

            printVector(arr);
            cout << "=================\n";

        }

    }

}

void stableInsertionSort(vector<pair<int, string>>& arr, bool verbose = false)
{

    int N = arr.size();

    for (int i = 1; i < N; i++)
    {

        auto key = arr[i];
        int j = i - 1;

        
        while (j >= 0 && arr[j].first > key.first)
        {

            arr[j + 1] = arr[j];
            j--;

        }

        arr[j + 1] = key;

    }

    cout << "Stable sorted pairs:\n";

    for (const auto& p : arr)
    {

        cout << "(" << p.first << ", " << p.second << ") ";

    }

    cout << endl;

}

int insertionSortWithComparisons(vector<int>& arr)
{

    int N = arr.size();
    int comparisons = 0; 

    for (int i = 1; i < N; i++)
    {

        int key = arr[i];
        int j = i - 1;

        while (j >= 0)
        {
            comparisons++; 

            if (arr[j] > key)
            {

                arr[j + 1] = arr[j];
                j--;

            }
            else
            {

                break; 

            }

        }

        arr[j + 1] = key;

    }

    return comparisons; 

}

void worstCaseInsertionSort(int N)
{

    vector<int> arr(N);

    
    for (int i = 0; i < N; i++)
    {

        arr[i] = N - i;

    }

    printVector(arr);
    int total_comparisons = insertionSortWithComparisons(arr);

    printVector(arr);
    cout << "Total comparisons in worst case: " << total_comparisons << endl;

}

int main()
{
  
    cout << "Standard Insertion Sort:\n";
    vector<int> arr1 = { 9, 4, 3, 2, 6, 7, 1, 8, 5 };
    insertionSort(arr1, true);
    cout << "Final sorted array: ";
    printVector(arr1);
    cout << endl;

    cout << "Worst Case Insertion Sort with Comparisons:\n";
    worstCaseInsertionSort(10); 
    cout << endl;


    cout << "Stable Insertion Sort for Pairs:\n";
    vector<pair<int, string>> arr2 = { {2, "woman"}, {1, "a"}, {1, "b"}, {2, "man"}, {1, "c"} };
    stableInsertionSort(arr2);

    return 0;

}
