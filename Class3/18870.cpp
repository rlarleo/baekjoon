#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int N, num;
    vector<pair<int, int>> vec;
    vector<pair<int, int>> result;
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> num;
        vec.push_back(pair<int, int>(num, i));
    }

    sort(vec.begin(), vec.end());

    result.push_back(pair<int, int> (vec[0].second, 0));

    int zip = 0;
    for(int i = 1; i < N; i++){
        if(vec[i-1].first != vec[i].first) zip++;
        result.push_back(pair<int, int>(vec[i].second, zip));
    }

    sort(result.begin(), result.end());

    for(auto r : result){
        cout << r.second << " ";
    }

    return 0;
}
