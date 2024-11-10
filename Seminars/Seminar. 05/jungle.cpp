#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>

int main() 
{

    int N = 0;
    std::cin >> N;

    std::vector<int> arr(N, 0);
    for (int i = 0; i < N; i++) std::cin >> arr[i];

    std::vector<int> visible(N, 0);
    std::stack<int> st;

    for (int i = N - 1; i >= 0; i--) 
    {

        while (!st.empty() && arr[i] >= st.top()) st.pop();

        visible[i] = st.size();
        st.push(arr[i]);

    }

    int maxVisible = 0;
    int bestPosition = 0;

    for (int i = 0; i < N; i++)
    {

        if (visible[i] > maxVisible)
        {

            maxVisible = visible[i];
            bestPosition = i;

        }

    }
    
    std::cout << bestPosition;
    return 0;

}
