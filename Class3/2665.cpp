#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;


int n;
int miro[50][50];
bool visited[50][50] = {0, };


int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool IsValid(int x, int y){
    return (x >= 0 && y >= 0 && x < n && y < n);
}

int Bfs(){
    deque<pair<int, pair<int, int>>> deque;
    deque.push_front({0 ,{0, 0}});

    while(!deque.empty()){
        int curr_x = deque.front().second.second;
        int curr_y = deque.front().second.first;
        int cost = deque.front().first;
        deque.pop_front();
        for(int i = 0; i < 4; i++){
            int next_x = curr_x + dx[i];
            int next_y = curr_y + dy[i];
            if(IsValid(next_x, next_y) && !visited[next_y][next_x]){
                visited[next_y][next_x] = 1;
                if(next_x == n-1 && next_y == n-1) return cost;
                if(miro[next_y][next_x] == 0) {
                    deque.push_back({cost + 1, {next_y, next_x}});
                }
                else{
                    deque.push_front({cost, {next_y, next_x}});
                }
            }
        }
    }
    return 0;
}


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> n;

    pair<int, int> person1 = {-1, -1};
    pair<int, int> person2 = {-1, -1};
    for(int i = 0; i < n; i++){
        string input;
        cin >> input;
        for(int j = 0; j < n; j++){
            miro[i][j] = input[j] - '0';
        }
    }
    cout << Bfs();

}
