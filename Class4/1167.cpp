#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>

using namespace std;

int N;
pair<int, int> maxResult;
vector<pair<int, int>> graph[100001];
int visited[100001];

void bfs(int s){
    maxResult = {0, 0};
    queue<pair<int, int>> que;
    que.push({s, 0});
    visited[s] = 1;
    while(!que.empty()){
        int current = que.front().first;
        int cost = que.front().second;
        que.pop();
        for(int i = 0; i < graph[current].size(); i++){
            int next = graph[current][i].first;
            int n_cost = cost + graph[current][i].second;
            if(visited[next] == 0){
                visited[next] = n_cost;
                que.push({next, n_cost});
                maxResult = maxResult.first < n_cost ? make_pair(n_cost, next) : maxResult;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++){
        int parent, child, len;
        cin >> parent;
        while(true){
            cin >> child;
            if(child == -1) break;
            cin >> len;
            graph[parent].push_back({child, len});
        }
    }

    bfs(1);

    for(int i = 0; i <= N; i++){
        visited[i] = 0;
    }

    bfs(maxResult.second);
    cout << maxResult.first;

    return 0;
}
