#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;
int N, M;
vector<pair<int, pair<int, int>>> edges;
int parentNodes[100001];

int FindParent(int a){
    if(a == parentNodes[a]) return a;
    return parentNodes[a] = FindParent(parentNodes[a]);
}

bool SameParent(int a, int b){
    return FindParent(a) == FindParent(b);
}

void Union(int x, int y){
    x = FindParent(x);
    y = FindParent(y);
    parentNodes[y] = x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 1; i <= M; i++){
        int start, end, cost;
        cin >> start >> end >> cost;
        edges.push_back({cost, {start, end}});
    }
    for(int i = 1; i <= N; i++){
        parentNodes[i] = i;
    }
    sort(edges.begin(), edges.end());

    int result = 0;
    int last = 0;
    for(int i = 0; i < M; i++){
        if(!SameParent(edges[i].second.first, edges[i].second.second)){
            Union(edges[i].second.first, edges[i].second.second);
            result += edges[i].first;
            last = edges[i].first;
        }
    }
    cout << result - last;
    return 0;
}
