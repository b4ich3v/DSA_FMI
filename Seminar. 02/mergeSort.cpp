#include <iostream>
#include <vector>
#include <string>

using namespace std;

void merge(vector<int>& arr, vector<int>& left_arr, vector<int>& right_arr)
{

    cout << "Start of merging <- ";
    cout << "Left: ";
    for (int n : left_arr)
        cout << n << " ";
    cout << "| Right: ";
    for (int n : right_arr)
        cout << n << " ";
    cout << endl;

    int index = 0, left = 0, right = 0;
    int left_size = left_arr.size();
    int right_size = right_arr.size();

    while (left < left_size && right < right_size)
    {

        if (left_arr[left] <= right_arr[right])
        {

            arr[index] = left_arr[left];
            left++;

        }
        else
        {

            arr[index] = right_arr[right];
            right++;

        }

        index++;

    }

    while (left < left_size)
    {

        arr[index] = left_arr[left];
        left++;
        index++;

    }

    while (right < right_size)
    {

        arr[index] = right_arr[right];
        right++;
        index++;

    }

    cout << "End of merging: ";
    for (int n : arr)
        cout << n << " ";
    cout << endl;

}

void mergeSort(vector<int>& arr)
{

    if (arr.size() > 1)
    {
        int middle = arr.size() / 2;

        vector<int> left_arr(arr.begin(), arr.begin() + middle);
        vector<int> right_arr(arr.begin() + middle, arr.end());

        cout << "Splitting: ";
        for (int n : arr)
            cout << n << " ";
        cout << "-> Left: ";
        for (int n : left_arr)
            cout << n << " ";
        cout << "| Right: ";
        for (int n : right_arr)
            cout << n << " ";
        cout << endl;

        mergeSort(left_arr);
        mergeSort(right_arr);

        merge(arr, left_arr, right_arr);

    }

}

void mergePairs(vector<pair<int, string>>& arr, vector<pair<int, string>>& left_arr, vector<pair<int, string>>& right_arr)
{

    int index = 0, left = 0, right = 0;
    int left_size = left_arr.size();
    int right_size = right_arr.size();

    while (left < left_size && right < right_size)
    {

        if (left_arr[left].first <= right_arr[right].first)
        {

            arr[index] = left_arr[left];
            left++;

        }
        else
        {

            arr[index] = right_arr[right];
            right++;

        }

        index++;

    }

    while (left < left_size)
    {

        arr[index] = left_arr[left];
        left++;
        index++;

    }

    while (right < right_size)
    {

        arr[index] = right_arr[right];
        right++;
        index++;

    }

}

void mergeSortPairs(vector<pair<int, string>>& arr)
{

    if (arr.size() > 1)
    {

        int middle = arr.size() / 2;

        vector<pair<int, string>> left_arr(arr.begin(), arr.begin() + middle);
        vector<pair<int, string>> right_arr(arr.begin() + middle, arr.end());

        mergeSortPairs(left_arr);
        mergeSortPairs(right_arr);

        mergePairs(arr, left_arr, right_arr);

    }

}

void testMergeSortIntegers()
{

    cout << "Merge Sort for Integers:\n";
    vector<int> arr = { 9, 4, 3, 2, 6, 7, 1, 8, 5 };
    mergeSort(arr);

    cout << "Sorted array: ";

    for (int num : arr)
    {

        cout << num << " ";

    }

    cout << endl;

}

void testMergeSorPairs()
{

    cout << "Merge Sort for Pairs:\n";
    vector<pair<int, string>> arr = { {2, "woman"}, {1, "a"}, {1, "b"}, {2, "man"}, {1, "c"} };
    mergeSortPairs(arr);

    cout << "Sorted pairs: ";

    for (const auto& p : arr)
    {

        cout << "(" << p.first << ", " << p.second << ") ";

    }

    cout << endl;

}

int main()
{

    testMergeSortIntegers();
    cout << endl;
    testMergeSorPairs();

    return 0;

}
