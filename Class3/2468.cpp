#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int map[100][100];
bool visited[100][100];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int N;

bool isValid(int x, int y){
    return (x >= 0 && y >= 0 && x < N && y < N);
}

void bfs(pair<int, int> start, bool check, int rain){
    queue<pair<int, int>> que;
    que.push(start);
    visited[start.first][start.second] = 1;

    while(!que.empty()){
        pair<int, int> current = que.front();
        que.pop();
        for(int i = 0; i < 4; i++){
            int nextX = current.second + dx[i];
            int nextY = current.first + dy[i];
            if(isValid(nextX, nextY) && !visited[nextY][nextX] && (check || map[nextY][nextX] <= rain)){
                que.push({nextY, nextX});
                visited[nextY][nextX] = 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int input;
    int maxHeight = 0;
    int maxResult = 1;
    cin >> N;

    for(int i = 0; i < N; i ++){
        for(int j = 0; j < N; j++){
            cin >> input;
            map[i][j] = input;
            maxHeight = maxHeight < input ? input : maxHeight;
        }
    }
    for(int rain = 0; rain < maxHeight; rain++){
        memset(visited, 0, sizeof(visited));


        for(int i = 0; i < N; i ++){
            for(int j = 0; j < N; j++){
                if(!visited[i][j] && map[i][j] <= rain)
                    bfs({i, j}, false, rain);
            }
        }
        
        int result = 0;
        for(int i = 0; i < N; i ++){
            for(int j = 0; j < N; j++){
                if(!visited[i][j]){
                    bfs({i, j}, true, rain);
                    result ++;
                }
            }
        }

        maxResult = maxResult < result ? result : maxResult;
    }

    cout << maxResult;

    return 0;
}
