int jumpSearch(const std::vector<int>& arr, int target) 
{

    int size = arr.size();
    int jump = sqrt(size);
    int start = 0, end = start + jump;

    while (end < size && arr[end] <= target) 
    {

        start = end;
        end += jump;
        if (end > size - 1) end = size;
            
    }

    for (int i = start; i < end; i++) 
    {

        if (arr[i] == target) return i;
           
    }

    return -1;

}
