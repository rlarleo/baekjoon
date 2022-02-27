#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#define MAX 1001
#define INF INT_MAX

using namespace std;

int city, bus;
int a, b;
vector<pair<int, int>> graph[MAX];
vector<int> d(MAX,INF);

void dijkstra(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, a});
    d[a] = 0;
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
    cout << d[b];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> city >> bus;

    int start, end, distance;
    for(int i = 0; i < bus; i++){
        cin >> start >> end >> distance;
        graph[start].push_back({end, distance});
    }
    cin >> a >> b;

    dijkstra();

    return 0;
}
