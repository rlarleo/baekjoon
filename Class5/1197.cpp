#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int V, E;
int result = 0;
int parentNode[10001];

int FindParent(int x)
{
    if (parentNode[x] == x)
        return x;
    return FindParent(parentNode[x]);
}

bool SameParent(int a, int b)
{
    return FindParent(a) == FindParent(b);
}

void Union(int x, int y)
{
    x = FindParent(x);
    y = FindParent(y);
    parentNode[y] = x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> V >> E;
    vector<pair<int, pair<int, int>>> graph;
    for (int i = 1; i <= V; i++)
    {
        parentNode[i] = i;
    }

    for (int i = 0; i < E; i++)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        graph.push_back({cost, {a, b}});
    }
    sort(graph.begin(), graph.end());

    for (int i = 0; i < E; i++)
    {
        int cost = graph[i].first;
        int from = graph[i].second.first;
        int to = graph[i].second.second;
        if (!SameParent(from, to))
        {
            Union(from, to);
            result += cost;
        }
    }
    cout << result;
    return 0;
}
