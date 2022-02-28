#include <iostream>
#include <vector>
#include <queue>
#include <functional>

#define MAX_STUDENT 1001
#define INF 987654321
using namespace std;


int N, M, X;

vector<pair<int, int>> graph[MAX_STUDENT];

int dijkstra(int s, int e) {
    int d[1001];
    for (int i = 0; i < 1001; i++) d[i] = INF;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({ 0, s });
    while (!pq.empty()) {
        int current = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if (d[current] < cost) continue;
        for (int i = 0; i < graph[current].size(); i++) {
            int next = graph[current][i].first;
            int n_cost = graph[current][i].second + cost;
            if (d[next] > n_cost) {
                d[next] = n_cost;
                pq.push({ n_cost, next });
            }
        }

    }

    return d[e];
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> N >> M >> X;

    int start, end, cost;
    for (int i = 0; i < M; i++) {
        cin >> start >> end >> cost;
        graph[start].push_back({ end, cost });
    }

    int max = 0;
    for (int i = 1; i <= N; i++) {
        if (i != X) {
            int result = dijkstra(i, X) + dijkstra(X, i);
            max = max < result ? result : max;
        }
    }
    cout << max;

    return 0;
}
