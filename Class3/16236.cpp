#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int graph[20][20];
int N, result = 0;
pair<int, int> start;
priority_queue<int, vector<int>, greater<int>> pq;

int dy[4] = {0, -1, 1, 0};
int dx[4] = {-1, 0, 0, 1};

struct Shark{
    int size = 2;
    int feed = 0;
};

bool check(int x, int y){
    return (x >= 0 && y >= 0 && x < N && y < N);
}

void bfs(){
    Shark shark;
    queue<pair<int, int>> que;
    que.push(start);
    int visited[20][20] = {0, };
    visited[start.first][start.second] = 1;

    while(!que.empty()){
        if(shark.feed == shark.size){
            shark.size++;
            shark.feed = 0;
        }
        if(pq.top() >= shark.size) {
            cout << "pq.top(): " << pq.top() << endl;
            break;
        }
        pair<int, int> current = que.front(); que.pop();

        for(int i = 0; i < 4; i++){
            int x = current.first + dx[i];
            int y = current.second + dy[i];
            if(check(x, y) && !visited[x][y] && graph[x][y] <= shark.size){
                if(graph[x][y] != 0 && graph[x][y] < shark.size) {
                    que.push({x, y});
                    pq.pop();
                    visited[x][y] = visited[current.first][current.second] + 1;
                    graph[x][y] = 0;
                    shark.feed ++;
                    cout << "x: " << x+1 << "  y: " << y+1 << "  result: " << result << "  size: " << shark.size << endl;
                    cout << visited[x][y] << endl;
                    result = result + visited[x][y] - 1;
                    start = {x, y};
                    while(!que.empty()){
                        que.pop();
                    }
                    que.push(start);
                    for(int i = 0; i < N; i++){
                        for(int j = 0; j < N; j++){
                            cout << visited[i][j];
                            visited[i][j] = 0;
                        }
                        cout << endl;
                    }
                    visited[x][y] = 1;
                    break;
                } else{
                    que.push({x, y});
                    visited[x][y] = visited[current.first][current.second]+1;
                }
            }
        }
    }
    cout << result;

}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int input;

    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> input;
            graph[i][j] = input;
            if(input == 9) {graph[i][j] = 0; start = {i, j};};
            if(input != 0) pq.push(input);
        }
    }


    bfs();

    return 0;
}
