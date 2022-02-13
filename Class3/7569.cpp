#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
int N, M, H, tomato;
int graph[101][101][101];
queue<tuple<int, int, int>> que;
int x[6] = {1, -1, 0, 0, 0, 0};
int y[6] = {0, 0, -1, 1, 0, 0};
int h[6] = {0, 0, 0, 0, 1, -1};

bool isValid(int h, int y, int x){
    return (x >= 0 && x < N && y >= 0 && y < M && h >= 0 && h < H);
}

void bfs(){
    while(!que.empty()){
        tuple<int, int, int> current = que.front();
        que.pop();
        for(int i = 0; i < 6; i++){
            int dh = get<0>(current) + h[i];
            int dy = get<1>(current) + y[i];
            int dx = get<2>(current) + x[i];
            if(isValid(dh, dy, dx) && graph[dh][dy][dx] == 0){
                que.push({dh, dy, dx});
                graph[dh][dy][dx] = graph[get<0>(current)][get<1>(current)][get<2>(current)] + 1;
            }
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> H;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < M; j++){
            for(int k = 0; k < N; k++){
                cin >> tomato;
                graph[i][j][k] = tomato;
                if(graph[i][j][k] == 1) que.push({i, j, k});
            }
        }
    }

    bfs();

    int max = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < M; j++){
            for(int k = 0; k < N; k++){
                if(graph[i][j][k] == 0){
                    cout << -1;
                    return 0;
                }
                max = graph[i][j][k] > max? graph[i][j][k] : max;
            }
        }
    }
    cout << max - 1;

    return 0;
}
