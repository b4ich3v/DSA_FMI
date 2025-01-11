int upperBound(const std::vector<int>& arr, int target)
{

    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {

        int middle = left + (right - left) / 2;

        if (arr[middle] <= target)  left = middle + 1;
        else right = middle - 1;
            
    }

    return left;

}
