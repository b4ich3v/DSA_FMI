void bubbleSort(std::vector<int>& arr) 
{

    for (int i = 0; i < arr.size() - 1; i++)
    {

        for (int j = 0; j < arr.size() - i - 1; j++)
        {

            if (arr[j] > arr[j + 1]) std::swap(arr[j], arr[j + 1]);

        }

    }

}
