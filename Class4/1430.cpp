#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int N, R, D, X, Y;
double finalResult = 0;
vector<pair<int, int>> graph[1000];
vector<pair<int, int>> turrets;

double GetDistance(int a, int b, int c, int d){

    double distance;
    distance = sqrt(pow(a - c, 2) + pow(b - d, 2));

 return distance;
}

int GetIndex(pair<int, int> location){
    int index = 0;
    for(auto t : turrets){
        if(t == location) return index;
        index++;
    }

 return -1;
}

double bfs(int x, int y){
    int visited[1000][1000] = {0, };
    double result = 0;
    queue<pair<pair<int, int>, double>> que;
    que.push({{x, y}, D});
    visited[y][x] = 1;
    
    while(!que.empty()){
        int curr_x = que.front().first.first;
        int curr_y = que.front().first.second;
        int index = GetIndex(que.front().first);
        double damage = que.front().second;
        bool isDone = false;
        que.pop();

        for(int i = 0; i < graph[index].size(); i++){
            int next_x = graph[index][i].first;
            int next_y = graph[index][i].second;
            if(!visited[next_y][next_x]){
                if(next_x == X && next_y == Y){
                    result = damage;
                    isDone = true;
                }else{
                    visited[next_y][next_x] = 1;
                    que.push({{next_x, next_y}, damage / 2.0});
                }
            }
            if(isDone) break;
        }
        if(isDone) break;
    }
    return result;

}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> N >> R >> D >> X >> Y;

    int map[1000][1000] = {0, };
    for(int i = 0 ; i < N; i++){
        int inputX, inputY;
        cin >> inputX >> inputY;
        turrets.push_back({inputX, inputY});
        map[inputY][inputX] = 1;
    }

    for(int i = 0; i < N; i++){
        int currX = turrets[i].first;
        int currY = turrets[i].second;
        if(GetDistance(currX, currY, X, Y) <= R){
            graph[i].push_back({X, Y}); 
        }
        for(int j = i+1; j < N; j++){
            if(GetDistance(currX, currY, turrets[j].first, turrets[j].second) <= R){
                graph[i].push_back({turrets[j].first, turrets[j].second});
                graph[j].push_back({currX, currY});
            }
        }
    }

    for(int i = 0; i < N; i++){
        finalResult += bfs(turrets[i].first, turrets[i].second);
    }
    cout << finalResult;


    
    
    return 0;
}