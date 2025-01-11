void selectionSort(std::vector<int>& arr)
{

    for (int i = 0; i < arr.size(); i++)
    {

        int minIndex = i;

        for (int j = i + 1; j < arr.size(); j++)
        {

            if (arr[j] < arr[minIndex]) minIndex = j;

        }

        if (i != minIndex) std::swap(arr[i], arr[minIndex]);

    }

}
