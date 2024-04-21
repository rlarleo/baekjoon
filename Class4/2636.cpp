#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
int map[100][100];
int nextMap[100][100];
bool isVisited[100][100];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int Bfs(int y, int x)
{
    queue<pair<int, int>> que;
    que.push({x, y});
    isVisited[y][x] = 1;


    while(!que.empty()){
        int currX = que.front().first;
        int currY = que.front().second;
        que.pop();
        for(int i = 0 ; i < 4; i++){
            int nextX = currX + dx[i];
            int nextY = currY + dy[i];
            if(map[nextY][nextX] == -1) {
                nextMap[y][x] = 0;
                return 1;
            }
            if(!isVisited[nextY][nextX] && map[nextY][nextX] == 0){
                isVisited[nextY][nextX] = 1;
                que.push({nextX, nextY});
            }
        }
    }
    return 0;
}

bool Done(){
    for(int i = 1; i < N-1; i++){
        for(int j = 1; j < M-1; j++){
            if(map[i][j] == 1){
                return false;
            };
        }
    }
    return true;
}

void InitVisted(){
    for(int i = 1; i < N-1; i++){
        for(int j = 1; j < M-1; j++){
            isVisited[i][j] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            int input;
            cin >> input;
            if(i == 0 || j == 0) map[i][j] = -1;
            else if(i == N-1 || j == M-1) map[i][j] = -1;
            else map[i][j] = input;
        }
    }
    
    int time = 0;
    int result = 0;

    while(!Done()){
        time++;
        result = 0;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                nextMap[i][j] = map[i][j];
                isVisited[i][j] = 0;
            }
        }
        for(int i = 1; i < N-1; i++){
            for(int j = 1; j < M-1; j++){
                if(map[i][j] == 1) {
                    result += Bfs(i, j);
                    InitVisted();
                }
            }
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                map[i][j] = nextMap[i][j];
            }
        }
    }

    cout << time << '\n' << result;

    return 0;
}
