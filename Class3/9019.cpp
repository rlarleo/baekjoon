#include <iostream>
#include <queue>
#include <string>
using namespace std;

int T, origin, result;

void bfs(){
    queue<pair<int, string>> que;
    vector<bool> visited(10000, 0);

    que.push({origin, ""});
    visited[origin] = 1;

    while(!que.empty()){
        pair<int, string> current = que.front(); que.pop();
        int cur = current.first;
        if(cur == result){
            cout << current.second << '\n';
            break;
        }

        int next;
        //D
        next = cur * 2;
        if (next> 9999) next = next % 10000;

        if(visited[next] == 0) {
            visited[next] == 1;
            que.push({next, current.second + "D"});
        }

        //S
        next = cur - 1;
        if (next < 0) next = 9999;
        if(visited[next] == 0) {
            visited[next] == 1;
            que.push({next, current.second + "S"});
        }

        //L
        next = (cur % 1000) * 10 + (cur / 1000);
        if(visited[next] == 0) {
            visited[next] == 1;
            que.push({next, current.second + "L"});
        }

        //R
        next = (cur % 10) * 1000 + (cur / 10);
        if(visited[next] == 0) {
            visited[next] == 1;
            que.push({next, current.second + "R"});
        }

    }
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout.tie(0);
    cin >> T;

    while(T--){
        cin >> origin >> result;
        bfs();
    }

    return 0;
}
