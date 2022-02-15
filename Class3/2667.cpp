#include <iostream>
#include <queue>
#include <functional>
using namespace std;
int graph[26][26];
int visited[26][26];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
priority_queue<int, vector<int>, greater<int>> results;

bool isValid(int x, int y){
    return (x >= 0 && y >= 0 && x < 26 && y < 26);
}

void bfs(pair<int, int> start){
    queue<pair<int, int>> que;
    que.push(start);
    visited[start.first][start.second] = 1;
    int result = 1;
    while(!que.empty()){
        pair<int, int> current = que.front();
        que.pop();
        for(int i = 0; i < 4; i++){
            int x = current.first + dx[i];
            int y = current.second + dy[i];
            if(isValid && graph[x][y] != 0 && visited[x][y] != 1){
                que.push({x, y});
                result = result + 1;
                visited[x][y] = 1;
            }
        }
    }
    results.push(result);
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int N;
    string str;
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> str;
        for(int j = 0; j < N; j++){
            graph[i][j] = (int)str[j] - 48;
        }
    }

    int cnt = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(graph[i][j] == 1 && visited[i][j] != 1){
                bfs({i, j});
                cnt++;
            }
        }
    }

    cout << cnt << endl;

    while(!results.empty()){
        cout << results.top() << endl;
        results.pop();
    }

    return 0;
}
