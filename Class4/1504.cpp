#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#define MAX 801
#define INF 987654321

using namespace std;

int V, E;
int a, b;
vector<pair<int, int>> graph[MAX];

int dijkstra(int start, int end){

    vector<int> d;
    for(int i = 0; i < V+2; i++){
        d.push_back(INF);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, start});
    d[start] = 0;
    while(!pq.empty()){
        int current = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if (d[current] < cost) continue;
        for(int i = 0; i < graph[current].size(); i++){
            int next = graph[current][i].first;
            int n_cost = graph[current][i].second + cost;
            if(d[next] > n_cost){
                d[next] = n_cost;
                pq.push({n_cost ,next});
            }
        }
    }
    return d[end];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> V >> E;

    int start, end, distance;
    for(int i = 0; i < E; i++){
        cin >> start >> end >> distance;
        graph[start].push_back({end, distance});
        graph[end].push_back({start, distance});
    }
    cin >> a >> b;

    bool flag1 = false;
    bool flag2 = false;
    int result1 = -1;
    int result2 = -1;

    int ab = dijkstra(a, b);
    if(ab != INF){
        int a1 = dijkstra(1, a);
        if(a1 != INF){
            int bv = dijkstra(b, V);
            if(bv != INF){
                result1 = a1 + ab + bv;
            }
        }
        int b1 = dijkstra(1, b);
        if(b1 != INF){
            int av = dijkstra(a, V);
            if(av != INF){
                result2 = ab+b1+av;
            }
        }
    }
    if(result1 == -1 && result2 == -1) cout << -1;
    else if(result1 == -1){
        cout << result2;
    }
    else if(result2 == -1){
        cout << result1;
    }
    else{
        result1 > result2 ? cout << result2 : cout << result1;
    }

    return 0;
}
