#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int>* graph;
int N, M;
int result = 1000;
int idx = 0;

void bfs(int start){
    int depth = 0;
    int* visited = new int[N+1];
    for(int i = 1; i <= N; i++){
        visited[i] = 0;
    }
    queue<int> que;
    que.push(start);
    visited[start] = 1;

    while(!que.empty()){
        int current = que.front();
        que.pop();
        for(int i = 0; i < graph[current].size(); i++){
            int next = graph[current][i];
            if(visited[next] == 0){
                que.push(next);
                visited[next] = visited[current] + 1;
            }
        }
    }
    int sum = 0;
    for(int i = 1; i <= N; i++){
        sum = sum + visited[i];
    }
    if(result > sum){
        result = sum;
        idx = start;
    }
    delete visited;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> N >> M;

    graph = new vector<int>[N+1];

    for(int i = 0; i < M; i++){
        int start, end;
        cin >> start >> end;
        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    for(int i = 1; i < N+1; i++){
        bfs(i);
    }
    cout << idx;

    delete[] graph;
    return 0;
}
