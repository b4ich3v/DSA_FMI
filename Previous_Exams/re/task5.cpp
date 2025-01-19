#include <iostream>
#include <vector>

void dfs(int node, std::vector<std::vector<long long>>& tree, std::vector<bool>& colored, std::vector<int>& parent, int& counter)
{

    for (const auto& current : tree[node]) dfs(current, tree, colored, parent, counter);

    if (!colored[node])
    {

        counter += 1;
        colored[node] = true;
        colored[parent[node]] = true;
        colored[parent[parent[node]]] = true;

        for (const auto& current : tree[parent[node]]) colored[current] = true;

    }

}

int main() 
{

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<std::vector<long long>> tree(N);
    std::vector<bool> colored(N, false);
    std::vector<int> parent(N, 0);

    for (int i = 0; i < N; i++)
    {

        long long left = 0;
        long long right = 0;
        std::cin >> left >> right;

        if (left != -1)
        {

            tree[i].push_back(left);
            parent[left] = i;

        }

        if (right != -1)
        {

            tree[i].push_back(right);
            parent[right] = i;

        }

    }

    int counter = 0;
    dfs(0, tree, colored, parent, counter);
    std::cout << counter;

    return 0;

}
