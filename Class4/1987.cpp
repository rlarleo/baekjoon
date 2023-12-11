#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <tuple>

using namespace std;
char map[20][20];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int R, C;
bool visited[26] = {0, };

int result = 0;

bool IsValid(int x, int y){
    return (x >= 0 && y >= 0 && x < C && y < R);
}

void Dfs(int x, int y, int curr){
    result = max(result, curr);
    int idx = map[y][x] - 'A';
    for(int i = 0; i < 4; i++){
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        if(IsValid(next_x, next_y) && !visited[map[next_y][next_x] - 'A']){
            visited[map[next_y][next_x] - 'A'] = 1;
            Dfs(x + dx[i], y + dy[i], curr + 1);
            visited[map[next_y][next_x] - 'A'] = 0;
        }
    }
        
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> R >> C;
    for(int i = 0; i < R; i++){
        string input;
        cin >> input;
        for(int j = 0; j < C; j++){
            map[i][j] = input[j];
        }
    }
    visited[map[0][0] - 'A'] = 1;
    Dfs(0, 0, 1);
    cout << result;
    
    return 0;
}