#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int N, X, S;
    vector<pair<int, int>> vec;
    cin >> N;
    cin >> X >> S;

    for(int i = 0; i < N; i++){
        int cost, damage;
        cin >> cost >> damage;
        vec.push_back({cost, damage});
    }

    for(int i = 0; i < N; i++){
        if(vec[i].first <= X && vec[i].second > S){
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    return 0;


}
