#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int ms[501] = {0, };
bool isVisited[501][501] = {false, };
bool isVisited2[501][501] = {false, };
int N, M;

bool IsValid(int x, int y){
    return x >= 0 && y >= 0 && x < M && y < N;
}

void Bfs(int y, int x, vector<vector<int>> land){
    int amount = 1;
    queue<pair<int, int>> que;
    que.push({y, x});
    isVisited[y][x] = 1;

    while(!que.empty()){
        int currX = que.front().second;
        int currY = que.front().first;
        que.pop();
        for(int i = 0 ; i < 4; i++){
            int nextX = currX + dx[i];
            int nextY = currY + dy[i];
            
            if(IsValid(nextX, nextY) && !isVisited[nextY][nextX] && land[nextY][nextX] == 1){
                isVisited[nextY][nextX] = 1;
                que.push({nextY, nextX});
                amount++;
            }
        }
    }
    
    bool mVisited[501] = {0, };
    que.push({y, x});
    isVisited2[y][x] = 1;
    mVisited[x] = 1;
    ms[x] += amount;
    while(!que.empty()){
        int currX = que.front().second;
        int currY = que.front().first;
        que.pop();
        for(int i = 0 ; i < 4; i++){
            int nextX = currX + dx[i];
            int nextY = currY + dy[i];
            
            if(IsValid(nextX, nextY) && !isVisited2[nextY][nextX] && land[nextY][nextX] == 1){
                isVisited2[nextY][nextX] = 1;
                que.push({nextY, nextX});
                if(!mVisited[nextX]){
                    mVisited[nextX] = 1;
                    ms[nextX] += amount;
                }
            }
        }
    }
    
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    N = land.size();
    M = land[0].size();
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(land[i][j] == 1 && !isVisited[i][j])
                Bfs(i, j, land);
        }
    }
    
    answer = ms[0];
    for(int i = 1; i < M; i++) {
        answer = max(answer, ms[i]);
    }
    return answer;
}