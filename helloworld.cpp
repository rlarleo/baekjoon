#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<pair<int, pair<int, int>>> computers;
int parentNodes[1001];

int FindParent(int a)
{
    if (parentNodes[a] == a)
        return a;
    FindParent(a);
}

void Union(int a, int b)
{
    a = FindParent(a);
    b = FindParent(b);
    parentNodes[b] = a;
}

bool SameParent(int a, int b)
{
    FindParent(a) == FindParent(b);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int V, E;
    cin >> V >> E;

    for (int i = 0; i < E; i++)
    {
        int v1, v2, cost;
        cin >> v1 >> v2 >> cost;
        computers.push_back({cost, {v1, v2}});
    }

    sort(computers.begin(), computers.end());

    int result = 0;

    for (int i = 1; i <= V; i++)
    {
        parentNodes[i] = i;
    }
    for (auto computer : computers)
    {
        if (!SameParent(computer.second.first, computer.second.second))
        {
            Union(computer.second.first, computer.second.second);
            result += computer.first;
        }
    }

    cout << result;

    return 0;
}