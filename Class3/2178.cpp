#include <iostream>
#include <queue>
#include <string>

int graph[101][101];
int N, M, x;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
using namespace std;

void bfs(){
    queue<pair<int, int>> que;
    que.push({0, 0});
    while(!que.empty()){
        pair<int, int> current = que.front();
        que.pop();
        for(int i = 0; i < 4; i++){
            int nextX = current.first + dx[i];
            int nextY = current.second + dy[i];
            if(nextX >= 0 && nextX < N && nextY >= 0 && nextY < M && graph[nextX][nextY] == 1){
                que.push({nextX, nextY});
                graph[nextX][nextY] = graph[current.first][current.second] + 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    string road;

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> road;
        for(int j = 0; j < M; j++){
            graph[i][j] = (int)road[j] - 48;
        }
    }

    bfs();

    cout << graph[N-1][M-1];

    return 0;
}
