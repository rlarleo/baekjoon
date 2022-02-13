#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int>* graph;
int N, M, tomato;
int visited[1001][1001];
queue<pair<int, int>> que;
int x[4] = {1, -1, 0, 0};
int y[4] = {0, 0, -1, 1};


void bfs(){
    while(!que.empty()){
        pair<int, int> current = que.front();
        que.pop();
        for(int i = 0; i < 4; i++){
            int dx = current.first + x[i];
            int dy = current.second + y[i];
            if(dx >= 0 && dy >= 0 && dx < M && dy < N && graph[dx][dy] == 0){
                graph[dx][dy] = graph[current.first][current.second] + 1;
                que.push({dx, dy});
            }
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    graph = new vector<int>[M];
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> tomato;
            graph[i].push_back(tomato);
            if(graph[i][j] == 1) que.push({i, j});
        }
    }

    bfs();


    int max = 0;

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(graph[i][j] == 0) {
                cout << -1;
                delete[] graph;
                return 0;
            }
            else{
                max = graph[i][j] > max? graph[i][j] : max;
            }
        }
    }
    cout << max-1;
    delete[] graph;

    return 0;
}
