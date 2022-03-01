#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int N;

void bfs(int s, vector<int>* tree){
    int* visited = new int[N+1];
    for(int i = 0; i <= N; i++) visited[i] = 0;
    visited[s] = 1;

    queue<int> que;
    que.push(s);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    while(!que.empty()){
        int current = que.front(); que.pop();
        for(int i = 0; i < tree[current].size(); i++){
            int next = tree[current][i];
            if(visited[next] == 0){
                que.push(next);
                visited[next] = visited[current] + 1;
                pq.push({next, current});
                que.push(next);
            }
        }
    }

    while(!pq.empty()){
        cout << pq.top().second << '\n';
        pq.pop();
    }

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    vector<int>* tree = new vector<int>[N+1];

    for(int i = 0; i < N-1; i++){
        int start, end;
        cin >> start >> end;
        tree[start].push_back(end);
        tree[end].push_back(start);
    }

    bfs(1, tree);

    delete[] tree;

    return 0;
}
