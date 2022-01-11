#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, stair;
    vector<int> stairs;
    vector<pair<int, int>> results;
    vector<int> finals;
    stairs.push_back(0);
    results.push_back(make_pair(0,0));
    finals.push_back(0);
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> stair;
        stairs.push_back(stair);
    }
    results.push_back(make_pair(stairs[1], stairs[1]));
    finals.push_back(stairs[1]);
    results.push_back(make_pair(stairs[2], stairs[1]+stairs[2]));
    finals.push_back(stairs[1] + stairs[2]);

    for(int i = 3; i <= N; i++){
        results.push_back(make_pair(finals[i-2]+stairs[i], results[i-1].first+stairs[i]));
        if(results[i].first > results[i].second) finals.push_back(results[i].first);
        else finals.push_back(results[i].second);
    }
    cout << finals[N];
    return 0;
}
