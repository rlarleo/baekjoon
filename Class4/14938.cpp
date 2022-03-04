#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
#include <functional>
#define INF 987654321

using namespace std;

int N, M, R;
int maxResult = 0;
vector<pair<int, int>> graph[101];
int items[101];

void dijkstra(int s){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    int* distance = new int[N+1];
    for(int i = 0; i <= N; i++) distance[i] = INF;
    distance[s] = 0;
    while(!pq.empty()){
        int current = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if (distance[current] < cost) continue;
        for(int i = 0; i < graph[current].size(); i++){
            int next = graph[current][i].first;
            int n_cost = graph[current][i].second + cost;
            if(n_cost > M) continue;
            distance[next] = n_cost;
            pq.push({n_cost, next});
        }
    }
    int result = 0;
    for(int i = 1; i <= N; i++){
        if(distance[i] != INF) result += items[i];
    }
    maxResult = maxResult < result ? result : maxResult;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> R;

    for(int i = 1; i <= N; i++){
        cin >> items[i];
    }

    int start, end, cost;

    for(int i = 0; i < R; i++){
        cin >> start >> end >> cost;
        graph[start].push_back({end, cost});
        graph[end].push_back({start, cost});
    }

    for(int i = 1; i <= N; i++){
        dijkstra(i);
    }

    cout << maxResult;

    return 0;
}
