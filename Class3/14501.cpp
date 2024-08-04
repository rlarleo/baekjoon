#include <iostream>
#include <cmath>
#include <vector>
#include <math.h>

using namespace std;

int N, t, p;
vector<pair<int, int>> consults;
int dp[16][16] = {0, };
int main()
{
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> t >> p;
        consults.push_back({t, p});
    }
    

    for(int i = 1; i <= N; i++){
        for(int day = 1; day <= N; day++){
            int validDay = (i - 1 + consults[i-1].first);
            if(day == validDay)
                dp[i][day] = max((dp[i-1][day-consults[i-1].first] + consults[i-1].second), max(dp[i][day-1], dp[i-1][day]));
            else
                dp[i][day] = max(dp[i-1][day], dp[i][day-1]);
        }
    }    
    cout << dp[N][N];

}