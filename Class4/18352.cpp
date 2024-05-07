#include <iostream>
#include <queue>
#define INF 987654321

using namespace std;

vector<pair<int, int>> graph[300001];
int V, E, K, X;
int d[300001];

void dijkstra(int s)
{
    for (int i = 0; i <= V; i++)
        d[i] = INF;
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, s});
    while (!pq.empty())
    {
        int current = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if (d[current] < cost)
            continue;
        for (int i = 0; i < graph[current].size(); i++)
        {
            int next = graph[current][i].first;
            int n_cost = graph[current][i].second + cost;
            if (d[next] > n_cost)
            {
                d[next] = n_cost;
                pq.push({n_cost, next});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> V >> E >> K >> X;
    for (int i = 0; i < E; i++)
    {
        int start, end;
        cin >> start >> end;
        graph[start].push_back({end, 1});
    }
    dijkstra(X);
    bool check = false;
    for (int i = 1; i <= V; i++)
    {
        if (d[i] == K)
        {
            cout << i << '\n';
            check = true;
        }
    }
    if (!check)
    {
        cout << -1;
    }

    return 0;
}