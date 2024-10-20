#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

bool canDivide(const std::vector<int>& skills, long long maxSum, int teams)
{

    long long currentSum = 0;   
    int countTeams = 1;        

    for (int skill : skills)
    {
       
        if (currentSum + skill > maxSum)
        {

            countTeams++;        
            currentSum = skill;  

            if (countTeams > teams)  return false;
               
        }
        else currentSum += skill;

    }

    return true;

}

long long minimizeMaxSum(const std::vector<int>& skills, int teams)
{

    long long left = *std::max_element(skills.begin(), skills.end());
    long long right = std::accumulate(skills.begin(), skills.end(), 0LL); 

    while (left < right)
    {

        long long mid = left + (right - left) / 2; 

        if (canDivide(skills, mid, teams)) right = mid;
        else left = mid + 1;

    }

    return left; 

}

int main()
{

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k; 
    std::vector<int> skills(n);

    for (int i = 0; i < n; i++) std::cin >> skills[i];
        
    long long result = minimizeMaxSum(skills, k); 
    std::cout << result << '\n'; 

    return 0;

}

