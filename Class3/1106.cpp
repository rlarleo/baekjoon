#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main()
{
    int C, N, money, person;
    vector<pair<int, int>> vec;

    cin >> C >> N;
    int* dp = new int[C+1];
    dp[0] = 0;

    for(int i = 0; i < N; i++){
        cin >> money >> person;
        vec.push_back(pair<int, int>(money, person));
    }

    for(int i = 1; i <= C; i++){
        int min = INT_MAX;
        for(int j = 0; j < N; j++){
            if((i - vec[j].second) >= 0){
                int temp = dp[i - vec[j].second] + vec[j].first;
                if(min > temp) min = temp;
            } else {
                if(min > vec[j].first) min = (vec[j].first);
            }

        }
        dp[i] = min;
    }

    cout << dp[C] << endl;


    delete dp;

    return 0;
}
