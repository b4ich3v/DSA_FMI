int ternarySearch(const std::vector<int>& arr, int left, int right, int target)
{

    while (left <= right)
    {

        int middle1 = left + (right - left) / 3;
        int middle2 = right - (right - left) / 3;

        if (arr[middle1] == target) return middle1;
        if (arr[middle2] == target) return middle2;
           
        if (target > arr[middle1]) right = middle1 - 1;
        else if (target < arr[middle2]) left = middle2 + 1;
        else { left = middle1 + 1; right = middle2 - 1; }
       
    }

    return -1;

}
