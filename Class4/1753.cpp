#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
#include <functional>

#define INF 987654321
#define MAX_V 20010

using namespace std;

int N, M, start;
vector<pair<int, int>> graph[MAX_V];

void dijkstra(){
    int* d = new int[N+1];
    for(int i = 1; i <= N; i++){
        d[i] = INF;
    }
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    d[start] = 0;
    while(!pq.empty()){
        int cost = pq.top().first;
        int current = pq.top().second; pq.pop();
        for(int i = 0; i < graph[current].size(); i++){
            int next = graph[current][i].first;
            int n_cost = cost + graph[current][i].second;
            if(d[next] > n_cost){
                d[next] = n_cost;
                pq.push({d[next], next});
            }
        }

    }

    for(int i = 1; i <= N; i++){
        if(d[i] == INF) cout << "INF\n";
        else cout << d[i] << '\n';
    }

    delete d;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    cin >> start;

    for(int i = 0; i < M; i++){
        int start, end, distance;
        cin >> start >> end >> distance;
        graph[start].push_back({end, distance});
    }

    dijkstra();


    return 0;
}
