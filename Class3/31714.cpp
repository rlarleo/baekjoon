#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> people[1000];

int main()
{
    ios_base::sync_with_stdio(false);

    int N, M;
    long long D;

    cin >> N >> M >> D;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            int input;
            cin >> input;
            people[i].push_back(input + (D * i));
        }
        sort(people[i].begin(), people[i].end());
    }

    for(int i = 0; i < N - 1; i++){
        for(int j = 0; j < M; j++){
            if(people[i][j] >= people[i+1][j]){
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    

    return 0;
}
