int binarySearch(const std::vector<int>& arr, int left, int right, int target)
{

    while (left <= right)
    {

        int middle = left + (right - left) / 2;

        if (arr[middle] > target) right = middle - 1;
        else if (arr[middle] < target) left = middle + 1;
        else  return middle;

    }

    return -1;

}
