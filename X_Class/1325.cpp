#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
vector<int>* graph;
vector<int> results;
int maxResult = 0;

void bfs(int s){
    queue<int> que;
    que.push(s);
    int result = 0;
    bool visited[N+1] = {0, };
    visited[s] = 1;
    while(!que.empty()){
        int current = que.front(); que.pop();
        for(int i = 0; i < graph[current].size(); i++){
            int next = graph[current][i];
            if(!visited[next]){
                visited[next] = 1;
                que.push(next);
                result++;
            }
        }
    }
    maxResult = maxResult < result ? result : maxResult;
    results.push_back(result);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> N >> M;

    results.push_back(0);
    graph = new vector<int>[N+1];
    for(int i = 0; i < M; i++){
        int A, B;
        cin >> A >> B;
        graph[B].push_back(A);
    }
    for(int i = 1; i <= N; i++){
        bfs(i);
    }

    for(int i = 1; i <= N; i++){
        if(results[i] == maxResult) cout << i << ' ';
    }

    delete[] graph;
    return 0;
}
