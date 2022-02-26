#include <iostream>
#include <queue>

using namespace std;

int room[51][51];
int room2[51][51];
queue<pair<int, int>> que;
queue<pair<int, int>> que2;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int R, C, T;
int air;

bool check(int x, int y){
    return x >= 0 && y >= 0 && x < R && y < C;
}

void bfs(){
    while(!que.empty()){
        pair<int, int> current = que.front(); que.pop();
        int cnt = 0;
        for(int i = 0; i < 4; i++){
            int x = current.first + dx[i];
            int y = current.second + dy[i];
            if(check(x, y) && room[x][y] != -1){
                room2[x][y] += (room[current.first][current.second] / 5);
                ++cnt;
            }
        }
        room2[current.first][current.second] += room[current.first][current.second] - (room[current.first][current.second] / 5 * cnt);
        cnt = 0;
    }


    for(int i = air-2; i > 0; i--){
        room2[i][0] = room2[i-1][0];
    }
    for(int i = 0; i < C-1; i++){
        room2[0][i] = room2[0][i+1];
    }
    for(int i = 0; i < air-1; i++){
        room2[i][R] = room2[i+1][R];
    }
    for(int i = C; i > 1; i--){
        room2[air-1][i] = room2[air-1][i-1];
    }
    room2[air-1][1] = 0;

    for(int i = air+1; i < R-1; i++){
        room2[i][0] = room2[i+1][0];
    }
    for(int i = 0; i < C; i++){
        room2[R-1][i] = room2[R-1][i+1];
    }
    for(int i = R; i > air; i--){
        room2[i][C-1] = room2[i-1][C-1];
    }
    for(int i = C; i > 1; i--){
        room2[air][i] = room2[air][i-1];
    }
    room2[air][1] = 0;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


    cin >> R >> C >> T;

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> room[i][j];
            if(room[i][j] > 0) que.push({i, j});
            if(room[i][j] == -1) air = i;
        }
    }

    for(int i = 0; i < T; i++){
        if(i != 0){
            for(int i = 0; i < R; i++){
                for(int j = 0; j < C; j++){
                    if(room[i][j] != -1){
                        room[i][j] = room2[i][j];
                    }
                    if(room[i][j] > 0) que.push({i, j});
                    room2[i][j] = 0;
                }
            }
        }
        bfs();
    }

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cout << room2[i][j] << " ";
        }
        cout << endl;
    }
    int result = 0;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            result += room2[i][j];
        }
    }
    cout << result;
    return 0;
}
