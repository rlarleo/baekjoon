#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <stdlib.h>

using namespace std;

int N, Start, End, M, s, e;

vector<int>* graph;
bool visited[101] = {0, };

int Bfs(){
    queue<pair<int, int>> que;
    que.push({0, Start});
    visited[Start] = true;
    while(!que.empty()) {
        int curr = que.front().second;
        int cost = que.front().first;
        que.pop();

        for(int i = 0; i < graph[curr].size(); i++){
            int next = graph[curr][i];
            if(!visited[next]){
                visited[next] = true;
                que.push({cost + 1, next});
                if(next == End) return cost + 1;
            }
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> N >> Start >> End >> M;

    graph = new vector<int>[N+1];

    for(int i = 0; i < M; i++){
        cin >> s >> e;

        graph[s].push_back(e);
        graph[e].push_back(s);
    }

    cout << Bfs();

    
    
}
