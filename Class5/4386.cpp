#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int N;
vector<pair<double, double>> stars;
vector<pair<double, pair<double, double>>> edges;
int parentNodes[101];

double GetDistance(pair<double, double> a, pair<double, double> b) {
    double dx = a.first - b.first;
    double dy = a.second - b.second;
    return sqrt(dx * dx + dy * dy);
}
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
    cout << fixed;
    cout.precision(2);
    cin >> N;
    stars.push_back({0, 0});
    for(int i = 1; i <= N; i++){
        double x, y;
        cin >> x >> y;
        stars.push_back({x, y});
    }

    for(int i = 1; i <= N; i++){
        for(int j = i + 1; j <= N; j++){
            double cost = GetDistance(stars[i], stars[j]);
            edges.push_back({cost, {i, j}});
        }
    }
    for(int i = 1; i <= N; i++){
        parentNodes[i] = i;
    }
    sort(edges.begin(), edges.end());

    double result = 0;
    for(int i = 0; i < edges.size(); i++){
        if(!SameParent(edges[i].second.first, edges[i].second.second)){
            Union(edges[i].second.first, edges[i].second.second);
            result += edges[i].first;
        }
    }
    cout << result;
    return 0;
}
