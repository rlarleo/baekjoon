#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;
int N;
struct Star{
    int x = 0;
    int y = 0;
    int z = 0;
};
vector<int> parentNode;

vector<Star> stars; 
vector<pair<int, pair<int, int>>> edges; // {cost, {from, to}}

int FindParent(int x)
{
    if (parentNode[x] == x)
        return x;
    return FindParent(parentNode[x]);
}

bool SameParent(int a, int b)
{
    return FindParent(a) == FindParent(b);
}

void Union(int x, int y)
{
    x = FindParent(x);
    y = FindParent(y);
    parentNode[y] = x;
}

int GetDistance(Star a, Star b){
    return min(abs(a.x - b.x), min(abs(a.y - b.y), abs(a.z - b.z)));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i ++){
        int x, y, z;
        Star star;
        cin >> star.x >> star.y >> star.z;
        stars.push_back(star);
        parentNode.push_back(i);
    }
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            int distance = GetDistance(stars[i], stars[j]);
            edges.push_back({distance, {i, j}});
        }
    }
    sort(edges.begin(), edges.end());
    int result = 0;
    for(int i = 0; i < edges.size(); i++){
        int from = edges[i].second.first;
        int to = edges[i].second.second;
        int cost = edges[i].first;
        if(!SameParent(from, to)){
            Union(from, to);
            result += cost;
        }
    }
    cout << result;
    return 0;
}
