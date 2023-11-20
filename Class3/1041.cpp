#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

char map[601][601];
int visited[601][601];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int N, M, result = 0;

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
            if(isValid(nextX, nextY) && visited[nextY][nextX] == 0 && (map[nextY][nextX] == 'O' ||  map[nextY][nextX] == 'P')){
                que.push({nextX, nextY});
                visited[nextY][nextX] = 1;
                if(map[nextY][nextX] == 'P'){
                    result++;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(visited, -1, sizeof(visited));

    string input;
    int x, y;

    cin >> N >> M;

    for(int i = 0; i < N; i ++){
        cin >> input;
        for(int j = 0; j < M; j++){
            map[i][j] = input[j];
            if(input[j] == 'I'){
                x = j;
                y = i;
            }
            visited[i][j] = 0;
        }
    }

    bfs({x, y});

    if(result > 0) cout << result;
    else cout << "TT";


    return 0;
}
