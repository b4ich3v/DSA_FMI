void merge(std::vector<int>& arr, int left, int middle, int right)
{

    int leftSize = middle - left + 1;
    int rightSize = right - middle;

    std::vector<int> leftArr(leftSize);
    std::vector<int> rightArr(rightSize);

    for (int i = 0; i < leftSize; i++) leftArr[i] = arr[left + i];
    for (int i = 0; i < rightSize; i++) rightArr[i] = arr[middle + 1 + i];
       
    int i = 0;
    int j = 0;
    
    int k = left;

    while (i < leftSize && j < rightSize)
    {

        if (leftArr[i] <= rightArr[j])
        {

            arr[k] = leftArr[i];
            i++;

        }
        else 
        {

            arr[k] = rightArr[j];
            j++;

        }

        k++;

    }

    while (i < leftSize)
    {

        arr[k] = leftArr[i];
        i++;
        k++;

    }

    while (j < rightSize) 
    {

        arr[k] = rightArr[j];
        j++;
        k++;

    }

}

void mergeSort(std::vector<int>& arr, int left, int right)
{

    if (left < right) 
    {

        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);

    }

}
