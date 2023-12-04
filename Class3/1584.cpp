#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <tuple>

using namespace std;
int map[501][501] = {0, };
bool visited[501][501] = {0, };
bool flag = false;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int N, M;

int result = 0;

bool IsValid(int x, int y){
    return (x >= 0 && y >= 0 && x < 501 && y < 501 && map[y][x] != -1);
}

void Bfs(){
    deque<tuple<int, int, int>> deq;
    deq.push_front({0, 0, 0});
    visited[0][0] = 1;

    while(!deq.empty()){
        int curr_x = get<1>(deq.front());
        int curr_y = get<0>(deq.front());
        int dist = get<2>(deq.front());
        deq.pop_front();
        if(curr_x == 500 && curr_y == 500)
        {
            flag = true;
            cout << dist;
            break;
        }
        for(int i = 0; i < 4; i++){
            int next_x = curr_x + dx[i];
            int next_y = curr_y + dy[i];
            if(IsValid(next_x, next_y) && visited[next_y][next_x] == 0){
                visited[next_y][next_x] = 1;
                if(map[next_y][next_x] == 1){
                    deq.push_back({next_y, next_x, dist + 1});
                }
                else{
                    deq.push_front({next_y, next_x, dist});
                }
            }

        }

    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int x1, y1, x2, y2;

    cin >> N;
    for(int i = 0 ; i < N; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int y = min(y1, y2); y <= max(y1, y2); y++){
            for(int x = min(x1, x2); x <= max(x1, x2); x++){
                map[y][x] = 1;
            }
        }
    }
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int y = min(y1, y2); y <= max(y1, y2); y++){
            for(int x = min(x1, x2); x <= max(x1, x2); x++){
                map[y][x] = -1;
            }
        }
    }

    Bfs();

    if(!flag) cout << "-1";


    
    return 0;
}