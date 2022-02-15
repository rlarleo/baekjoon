#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int visited[100001];
int subin, baby;
queue<int> que;

void bfs(int subin){
    que.push(subin);
    visited[subin] = 1;
    while(!que.empty()){
        int current = que.front();
        que.pop();
        if(current == baby){
            cout << visited[current] - 1;
            return;
        }
        if(current - 1 >= 0 && visited[current - 1] == 0){
            que.push(current - 1);
            visited[current - 1] = visited[current] + 1;
        }
        if(current + 1 <= 100000 && visited[current + 1] == 0){
            que.push(current + 1);
            visited[current + 1] = visited[current] + 1;
        }
        if(current * 2 <= 100000 && visited[current * 2] == 0){
            que.push(current * 2);
            visited[current * 2] = visited[current] + 1;
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);


    cin >> subin >> baby;

    bfs(subin);

    return 0;
}
