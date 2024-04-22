#include <iostream>
#include <queue>


using namespace std;

char map[40][40];
char copyMap[40][40];
int N;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool IsValid(int x, int y){
    return (x >= 0 && y >= 0 && x < N && y < N);
}

void CopyMap(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            copyMap[i][j] = map[i][j];
        }
    }
}

bool Bfs(int x, int y){
    CopyMap();
    queue<pair<int, int>> que;
    que.push({x, y});
    while(!que.empty()){
        int curr_x = que.front().first;
        int curr_y = que.front().second;
        que.pop();
        for(int i = 0; i < 4; i++){
            int next_x = curr_x + dx[i];
            int next_y = curr_y + dy[i];
            if(IsValid(next_x, next_y) && copyMap[next_y][next_x] == '#'){
                copyMap[next_y][next_x] = '.';
                que.push({next_y, next_x});
            }
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(copyMap[i][j] == '#') return false;
        }
    }
    return true;
}

bool Calc(int x, int y){
    map[x][y] = '.';
    bool result = true;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(map[x][y] == '#')
                result = Bfs(i, j);
            if(!result) break;
        }
        if(!result) break;
    }

    if(!result) map[x][y] = '#';
    return result;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for(int i = 0; i < N; i++){
        string input;
        cin >> input;
        for(int j = 0; j < N; j++){
           map[i][j] = input[j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(Calc(i, j)){
                cout << i << ' ' << j << '\n';
            }
        }
    }
    
   


    return 0;
}
