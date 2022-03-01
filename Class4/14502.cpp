#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int graph[8][8];
bool visited[8][8];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<pair<int, int>> way;
queue<pair<int, int>> que;
int wall = 0;
int virus = 0;
int result = 0;

void InitVsited(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++)
            visited[i][j] = 0;
    }
}

bool Checked(int x, int y){
    return x >= 0 && y >= 0 && x < N && y < M;
}

int bfs(){

    InitVsited();
    int cnt = virus;

    while(!que.empty()){
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        for(int i = 0; i < 4; i++){
            int n_x = x + dx[i];
            int n_y = y + dy[i];
            if(Checked(n_x, n_y) && !visited[n_x][n_y] && graph[n_x][n_y] == 0){
                que.push({n_x, n_y});
                visited[n_x][n_y] = 1;
                cnt++;
            }
        }
    }
    return N*M - (cnt + wall + 3);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

   	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++)
		{
            cin >> graph[i][j];
            if(graph[i][j] == 0) way.push_back({i, j});
            else if(graph[i][j] == 1) wall++;
            else if(graph[i][j] == 2) {
                que.push({i, j});
                virus++;
            }
        }
    }


    for (int i = 0; i < way.size(); i++){
		for (int j = i + 1; j < way.size(); j++){
			for (int k = j + 1; k < way.size(); k++){
				// 벽 세우기
				graph[way[i].first][way[i].second] = 1;
				graph[way[j].first][way[j].second] = 1;
				graph[way[k].first][way[k].second] = 1;

				// 안전영역 최대크기 저장
				result = max(result, bfs());

				// 되돌려 놓기
				graph[way[i].first][way[i].second] = 0;
				graph[way[j].first][way[j].second] = 0;
				graph[way[k].first][way[k].second] = 0;
			}
        }
    }
    cout << result;

    return 0;

}
