#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int graph[1001][1001];
int visited[1001][1001];
int N, M;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

struct point{
    int X;
    int Y;
    int Attack;
};

bool checked(int x, int y, bool Attack){
    if(x < 0 || y < 0 || x >= N || y >= M) return false;
    if(visited[x][y] != 0) return false;
    if(Attack && graph[x][y] != 0) return false;
    return true;
}

void bfs(){
    point p;
    p.X = 0; p.Y = 0; p.Attack = 0;
    queue<point> que;
    que.push(p);
    visited[0][0] = 1;

    while(!que.empty()){
        int x = que.front().X;
        int y = que.front().Y;
        bool attack = que.front().Attack;
        que.pop();
        for(int i = 0; i < 4; i++){
            int n_x = x + dx[i];
            int n_y = y + dy[i];
            if(checked(n_x, n_y, attack)){
                point newPoint;
                newPoint.X = n_x;
                newPoint.Y = n_y;
                if(graph[n_x][n_y]) newPoint.Attack = 1;
                que.push(newPoint);
                visited[n_x][n_y] = visited[x][y] + 1;
            }
        }
    }


    if(visited[N-1][M-1] == 0){cout << -1; return;}
    cout << visited[N-1][M-1];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string input;
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        cin >> input;
        for(int j = 0; j < M; j++){
            graph[i][j] = input[j] - 48;
        }
    }

    bfs();


    return 0;
}
