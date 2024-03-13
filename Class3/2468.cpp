#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int map[500][500];
bool visited[500][500] = {0, };
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int N, M;

bool isValid(int x, int y){
    return (x >= 0 && y >= 0 && x < M && y < N);
}

int bfs(pair<int, int> start){
    int result = 1;
    queue<pair<int, int>> que;
    que.push(start);
    visited[start.first][start.second] = 1;

    while(!que.empty()){
        pair<int, int> current = que.front();
        que.pop();
        for(int i = 0; i < 4; i++){
            int nextX = current.second + dx[i];
            int nextY = current.first + dy[i];
            if(isValid(nextX, nextY) && !visited[nextY][nextX] && map[nextY][nextX] == 1){
                que.push({nextY, nextX});
                visited[nextY][nextX] = 1;
                result++;
            }
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int input;
    int result = 0;
    int count = 0;
    cin >> N >> M;

    for(int i = 0; i < N; i ++){
        for(int j = 0; j < M; j++){
            cin >> input;
            map[i][j] = input;
        }
    }


    for(int i = 0; i < N; i ++){
        for(int j = 0; j < N; j++){
            if(map[i][j] == 1){
                int curr = bfs({i, j});
                result = result < curr ? curr : result;
                count++;
            }
        }
    }
    


    cout << count << '\n' << result;

    return 0;
}
