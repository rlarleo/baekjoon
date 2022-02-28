#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int final_result = INT_MAX;
int graph[51][51];
int visited[51][51];
int N, M, input;
vector<int> comb;
vector<pair<int, int>> chicken;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool checked(int x, int y){
    return x >= 0 && y >= 0 && x < N && y < N;
}

void bfs(queue<pair<int, int>> q){
    int result = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if(!visited[next_x][next_y] && checked(next_x, next_y)){
                q.push({next_x, next_y});
                visited[next_x][next_y] = visited[x][y] + 1;
                if(graph[next_x][next_y] == 1){
                    result += (visited[next_x][next_y]-1);
                }
            }
        }
    }

    final_result = final_result > result ? result : final_result;
}



void combination(int k) {
    if (comb.size() == M) {
        queue<pair<int, int>> que;
        for (int i = 0; i < comb.size(); i++){
            que.push(chicken[comb[i]]);
            visited[chicken[comb[i]].first][chicken[comb[i]].second] = 1;
        }
        bfs(que);
        for(int i = 0; i < N; i++){
            for(int j =0; j < N; j++){
                visited[i][j] = 0;
            }
        }
    }
    else if( k == chicken.size() ){
    }
    else {
        comb.push_back(k);
        combination(k + 1);
        comb.pop_back();
        combination(k + 1);
    }
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> input;
            if(input == 2) chicken.push_back({i, j});
            graph[i][j] = input;
        }
    }

    combination(0);

    cout << final_result;
    return 0;
}
