#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int ladder[101];
int visited[101];

void bfs(){
    queue<pair<int, int>> que;
    que.push({1, 0});
    while(!que.empty()){
        int current = que.front().first;
        if(visited[current] != 0 && visited[current] <= que.front().second) {
            que.pop();
            continue;
        }
        visited[current] = que.front().second;
        que.pop();
        if(current <= 100){
            int next;
            if(ladder[current] != 0){
                next = ladder[current];
                que.push({next, visited[current]});
            }
            next = current+1;
            for(int i = 0; i < 6; i++)
                que.push({next+i, visited[current] + 1});
        }
    }
    for(int i = 1; i < 101; i++){
        cout << i << " " << visited[i] << endl;
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    for(int i = 0; i < N + M; i++){
        int start, end;
        cin >> start >> end;
        ladder[start] = end;
    }

    bfs();

    return 0;
}
