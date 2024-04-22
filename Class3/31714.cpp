#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define prime 1000000007
using namespace std;

vector<pair<int, long long>> people[1000];

int main()
{
    ios_base::sync_with_stdio(false);

    int N, M;
    long long D;

    cin >> N >> M >> D;

    for(int i = 1; i <= N; i++){
        for(int j = 0; j < M; j++){
            int input;
            cin >> input;
            int h = input + (D * i);
            people[i].push_back({h / prime, h % prime});
        }
        sort(people[i].begin(), people[i].end());
    }

    for(int i = 0; i < N - 1; i++){
        for(int j = 0; j < M; j++){
            if(people[i][j].first > people[i+1][j].first || (
                people[i][j].first == people[i+1][j].first && people[i][j].second > people[i+1][j].second )){
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    

    return 0;
}
