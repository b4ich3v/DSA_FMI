int exponentialSearch(const std::vector<int>& arr, int target)
{

    int size = arr.size();
    if (arr[0] == target) return 0;
       
    int i = 1;
    while (i < size && arr[i] <= target) i *= 2;
       
    int left = i / 2;
    int right = std::min(i, size - 1);

    return binarySearch(arr, left, right, target);

}

