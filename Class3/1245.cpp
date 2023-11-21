#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M, input;
int result = 0;
int map[101][71];
int visited[101][71];
int dx[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int dy[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
bool isPeak;

bool isValid(int x, int y){
    return (x >= 0 && y >= 0 && x < M && y < N);
}

bool isIncrement(pair<int, int> curr, pair<int, int> next){
    return (map[next.first][next.second] > map[curr.first][curr.second]);
}


void bfs(int y, int x){
    queue<pair<int, int>> que;
    que.push({y, x});
    visited[y][x] = 1;
    while(!que.empty()){
        pair<int, int> curr = que.front();
        que.pop();
        for(int i = 0; i < 8; i++){
            pair<int, int> next = {curr.first + dy[i], curr.second + dx[i]};
            if(isValid(next.second, next.first)){
                if(isIncrement(curr, next))
                    isPeak = false;
                if(visited[next.first][next.second] == 0 && map[curr.first][curr.second] == map[next.first][next.second]){
                    visited[next.first][next.second] = 1;
                    que.push(next);
                }
            }
        }
        
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    memset(map, 0, sizeof(map));
    memset(visited, 0, sizeof(visited));

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> input;
            map[i][j] = input;
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(visited[i][j] == 0){
                isPeak = true;
                bfs(i, j);
                if(isPeak) result++;;
            }
        }
    }
    cout << result;
    

    return 0;
}
