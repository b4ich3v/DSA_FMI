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

int partition(vector<int>& arr, int low, int high)
{

    int pivot = arr[high]; 
    int i = low;           

    cout << "New pivot number: " << pivot << ", low: " << low << ", high: " << high << endl;
    cout << "Before: ";
    printVector(vector<int>(arr.begin() + low, arr.begin() + high + 1)); 

    for (int j = low; j < high; j++)
    {

        if (arr[j] <= pivot)
        {

            swap(arr[i], arr[j]); 
            i++;   

        }

    }

    swap(arr[i], arr[high]); 

    cout << "After: ";
    printVector(vector<int>(arr.begin() + low, arr.begin() + high + 1)); 
    return i;  

}

void quickSort(vector<int>& arr, int low, int high)
{

    if (low < high)
    {

        int pi = partition(arr, low, high); 

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);

    }

}

void printPairs(const vector<pair<int, string>>& arr)
{

    for (const auto& p : arr)
    {

        cout << "(" << p.first << ", " << p.second << ") ";

    }

    cout << endl;

}

int partition(vector<pair<int, string>>& arr, int low, int high)
{

    int pivot = arr[high].first; 
    int i = low;                 

    for (int j = low; j < high; j++)
    {

        if (arr[j].first <= pivot)
        {       
            
            swap(arr[i], arr[j]); 
            i++;   
            
        }

    }

    swap(arr[i], arr[high]); 
    return i;               

}

void quickSort(vector<pair<int, string>>& arr, int low, int high)
{

    if (low < high)
    {

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);

    }

}

void testBasicQuickSort()
{

    vector<int> arr = { 9, 4, 3, 2, 6, 7, 1, 8, 5 };
    int N = arr.size();

    cout << "Initial array: ";
    printVector(arr);

    quickSort(arr, 0, N - 1);


    cout << "Sorted array: ";
    printVector(arr);
    cout << endl;

}

void testPairsQuickSort()
{

    vector<pair<int, string>> arr = { {2, "woman"}, {1, "a"}, {1, "b"}, {2, "man"}, {1, "c"} };
    int N = arr.size();

    cout << "Initial array of pairs: ";
    printPairs(arr);

    quickSort(arr, 0, N - 1);

    cout << "Sorted array of pairs: ";
    printPairs(arr);
    cout << endl;

}

int main()
{

    testBasicQuickSort();
    std::cout << endl;
    testPairsQuickSort();

    return 0;

}
