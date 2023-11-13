#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int map[1002][1002];
int visited[1002][1002];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int N, M;

bool isValid(int x, int y){
    return (x >= 0 && y >= 0 && x < M && y < N);
}

void bfs(pair<int, int> start){
    queue<pair<int, int>> que;
    que.push(start);
    visited[start.second][start.first] = 0;

    while(!que.empty()){
        pair<int, int> current = que.front();
        que.pop();
        for(int i = 0; i < 4; i++){
            int nextX = current.first + dx[i];
            int nextY = current.second + dy[i];
            if(isValid(nextX, nextY) && visited[nextY][nextX] == -1 && map[nextY][nextX] == 1){
                que.push({nextX, nextY});
                visited[nextY][nextX] = visited[current.second][current.first] + 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(visited, -1, sizeof(visited));

    int input, x, y;
    cin >> N >> M;

    for(int i = 0; i < N; i ++){
        for(int j = 0; j < M; j++){
            cin >> input;
            map[i][j] = input;
            if(input == 2){
                x = j;
                y = i;
            }
            if(input == 0){
                visited[i][j] = 0;
            }
        }
    }

   bfs({x, y});

    for(int i = 0; i < N; i ++){
        for(int j = 0; j < M; j++){
            cout << visited[i][j] << ' ';
        }
        cout << "\n";
    }


    return 0;
}
