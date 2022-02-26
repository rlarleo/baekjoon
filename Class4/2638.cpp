#include <iostream>
#include <queue>

using namespace std;

int graph[101][101];
int graph2[101][101];
bool visited[101][101] = {0, };
int dfsCnt = 0;

queue<pair<int, int>> que;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int N, M;
bool flag = false;
bool check(int x, int y){
    return x > 0 && y > 0 && x < N-1 && y < M-1;
}

void dfs(int x, int y){
    visited[x][y] = 1;
    for(int i = 0; i < 4; i++){
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if(nextX == 0 || nextY == 0 || nextX == N-1 || nextY == M-1) flag = true;
        if(!flag && !visited[nextX][nextY] && check(nextX, nextY) && graph[nextX][nextY] == 0){
            dfs(nextX, nextY);
        }
    }
}

void bfs(){
    while(!que.empty()){
        pair<int, int> current = que.front(); que.pop();
        int cnt = 0;
        for(int i = 0; i < 4; i++){
            int x = current.first + dx[i];
            int y = current.second + dy[i];
            if(graph[x][y] == 0){
                cnt++;
                dfs(x, y);
                if(flag) dfsCnt++;
                flag = false;
                for(int i = 0; i < N; i++){
                    for(int j = 0; j < M; j++){
                        visited[i][j] = 0;
                    }
                }
            }
        }
        if(cnt >= 2 && dfsCnt >= 2){
            graph2[current.first][current.second] = 0;
        }
        dfsCnt = 0;
        cnt = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> graph[i][j];
            graph2[i][j] = graph[i][j];
            if(graph[i][j] == 1) que.push({i, j});
        }
    }

    int time = 0;
    //cout << endl;
    while(!que.empty()){
        bfs();
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                graph[i][j] = 0;
                if(graph2[i][j] == 1) que.push({i, j});
                graph[i][j] = graph2[i][j];
            }
        }
        /*for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cout << graph2[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;*/
        time++;
    }

    cout << time;

    return 0;
}
