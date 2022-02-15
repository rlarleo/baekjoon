#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int>* graph;
//int visited[101][101];
int N, input;

void bfs(int start){
    queue<int> que;
    que.push(start);
    int visited[101] = {0, };
    while(!que.empty()){
        int current = que.front();
        que.pop();
        for(int i = 0; i < graph[current].size(); i++){
            int next = graph[current][i];
            if(!visited[next]){
                que.push(next);
                visited[next] = 1;
            }
        }
    }
    for(int i = 1; i <= N; i++){
        cout << visited[i] << " ";
    }
    cout << endl;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> N;

    graph = new vector<int>[N+1];
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> input;
            if(input){
                graph[i].push_back(j);
            }
        }
    }

    for(int i = 1; i <= N; i++){
        bfs(i);
    }



    return 0;
}
