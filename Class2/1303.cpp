#include <iostream>
#include <vector>
#include <queue>

using namespace std;

char map[100][100];
bool visited[100][100] = {0, };
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int N, M;
long long wTeam = 0;
long long bTeam = 0;

bool IsValid(int x, int y){
    return (x >= 0 && y >= 0 && x < M && y < N);
}

void bfs(int x, int y, int color){
    int result = 1;
    queue<pair<int, int>> que;
    que.push({x, y});
    visited[y][x] = 1;
    
    while(!que.empty()){
        
        int curr_x = que.front().first;
        int curr_y = que.front().second;
        que.pop();
        for(int i = 0; i < 4; i++){
            int next_x = curr_x + dx[i];
            int next_y = curr_y + dy[i];
            if(IsValid(next_x, next_y) && !visited[next_y][next_x] && map[next_y][next_x] == color){
                result ++;
                visited[next_y][next_x] = 1;
                que.push({next_y, next_x});
            }
        }
    }

    cout << result << endl;

    if(color == 'W') wTeam += (result * result);
    else bTeam += (result * result);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> N >> M;

    for(int i = 0 ; i < M; i++){
        string input;
        cin >> input;
        for(int j = 0; j < N; j++){
            map[i][j] = input[j];
        }
    }

    
    for(int i = 0 ; i < M; i++){
        for(int j = 0; j < N; j++){
            if(!visited[i][j]){
                bfs(j, i, map[i][j]);
            }
        }
    }

    cout << wTeam << ' ' << bTeam;

    
    
    return 0;
}