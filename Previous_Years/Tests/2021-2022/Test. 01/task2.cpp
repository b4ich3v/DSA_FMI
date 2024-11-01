#include <iostream>
#include <vector>
#include <algorithm>

struct Team 
{

    int index = 0;
    int players = 0;
    int opponents = 0;
    long long score = 0;

};

bool pred(const Team& t1, const Team& t2) 
{

    if (t1.score == t2.score) return t1.players > t2.players;
    return t1.score > t2.score;

}

int main() 
{

    int N;
    std::cin >> N;
    std::vector<Team> teams(N);

    for (int i = 0; i < N; i++) 
    {

        int Xi, Yi;
        std::cin >> Xi >> Yi;
        teams[i] = { i + 1, Xi, Yi, (Xi * Xi) / Yi };

    }

    std::sort(teams.begin(), teams.end(), pred);

    for (const auto& team : teams) std::cout << team.index << " ";
    return 0;

}
