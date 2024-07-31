#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int R, C;
char preGraph[1500][1500];
char graph[1500][1500];
pair<int, int> startPoint = {-1, -1};
pair<int, int> endPoint;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool IsValid(int x, int y){
    return (x >= 0 && y >= 0 && x < C && y < R);
}

bool IsDone(){
    bool visited[1500][1500] = {0, };
    queue<pair<int, int>> que;
    que.push(startPoint);

    while(!que.empty()){
        int curr_x = que.front().second;
        int curr_y = que.front().first;
        que.pop();
        for(int i = 0; i < 4; i++){
            int next_x = curr_x + dx[i];
            int next_y = curr_y + dy[i];
            if(endPoint.first == next_y && endPoint.second == next_x) return true;
            if(IsValid(next_x, next_y) && !visited[next_y][next_x] && graph[next_y][next_x] == '.'){
                visited[next_y][next_x] = true;
                que.push({next_y, next_x});
            }
        }
    }

    return false;
}

bool WillMelt(int x, int y){
    for(int i = 0; i < 4; i++){
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        if(IsValid(next_x, next_y) && preGraph[next_y][next_x] == '.'){
            return true;
        }
    }
    return false;
}

void Melt(){
   for(int i = 0 ; i < R; i++){
        for(int j = 0; j < C; j++){
            if(preGraph[i][j] == 'X' && WillMelt(j, i)){
                graph[i][j] = '.';
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> R >> C;

    for(int i = 0 ; i < R; i++){
        string input;
        cin >> input;
        for(int j = 0; j < C; j++){
            if(input[j] == 'L') {
                if(startPoint.first == -1)
                    startPoint = {i, j};
                else
                    endPoint = {i, j};
            }
            graph[i][j] = input[j];
        }
    }

    bool isDone = false;
    int day = 1;
    if(IsDone()){
        cout << 0;
    }
    else{
        while(true){
            for(int i = 0 ; i < R; i++){
                for(int j = 0; j < C; j++){
                    preGraph[i][j] = graph[i][j];
                }
            }

            Melt();

            if(IsDone()) break;
            day++;
        }
    }

    cout << day;
    
}
