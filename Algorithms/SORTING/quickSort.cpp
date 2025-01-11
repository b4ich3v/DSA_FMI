int partition(std::vector<int>& arr, int left, int right)
{
    
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++) 
    {

        if (arr[j] < pivot) 
        {

            i++;
            std::swap(arr[i], arr[j]);

        }

    }

    std::swap(arr[i + 1], arr[right]);
    return i + 1;

}

void quickSort(std::vector<int>& arr, int left, int right)
{

    if (left < right) 
    {

        int pivotIndex = partition(arr, left, right);

        quickSort(arr, left, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, right);

    }

}
