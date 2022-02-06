#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

void bfs(vector<int>* graph, vector<bool>& checked, int start){
    queue<int> que;
    que.push(start);
    checked[start] = true;
    while(!que.empty()){
        int current = que.front();
        que.pop();
        for(int i = 0; i<graph[current].size(); i++){
            int next = graph[current][i];
            if(!checked[next]){
                checked[next] = true;
                que.push(next);
            }

        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int N, M, V;
    int result = 0;
    cin >> N >> M;

    vector<int>* graph = new vector<int>[N+1];
    vector<bool> checked(N+1);
    fill(checked.begin(), checked.end(), false);

    for(int i = 0; i < M; i++){
        int startPoint, endPoint;
        cin >> startPoint >> endPoint;
        graph[startPoint].push_back(endPoint);
        graph[endPoint].push_back(startPoint);
    }

    for(int i = 1; i <= N; i++){
        if(!checked[i]){
            result++;
            bfs(graph, checked, i);
        }
    }
    cout << result;

    delete[] graph;

    return 0;
}
