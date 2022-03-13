#include <iostream>
#include <queue>

using namespace std;

int N;
int room[17][17];
int dx[3] = {0, 1, 1};
int dy[3] = {1, 0, 1};
int result = 0;

bool checked(int x, int y){
    return x >= 0 && y >= 0 && x < N && y < N;
}

void bfs(){
    queue<pair<int, pair<int, int>>> que;
    que.push({0, {0, 1}});
    while(!que.empty()){
        int state = que.front().first;
        int x = que.front().second.first;
        int y = que.front().second.second;
        que.pop();
        for(int i = 0; i < 3; i++){
            int n_s = i;
            int n_x = x + dx[i];
            int n_y = y + dy[i];
            if(state == 0 && i == 1) continue;
            if(state == 1 && i == 0) continue;
            if(i == 2){
                if((room[x][n_y] == 1 || room[n_x][y] == 1)) continue;
            }
            if(checked(n_x, n_y) && room[n_x][n_y] != 1){
                que.push({n_s, {n_x, n_y}});
                if(n_x == N-1 && n_y == N-1) result++;
            }
        }
    }
    cout << result;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> room[i][j];
        }
    }
    for(int i = 0; i <= N; i++){
        room[N][i] = 1;
        room[i][N] = 1;
    }

    bfs();
    return 0;
}
