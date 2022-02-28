#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int dp[501][501] = {0, };
    int N, input;
    cin >> N;

    for(int i = 1; i <= N; i++){
        for(int j = 0; j < i; j++){
            cin >> input;
            if(j == 0) dp[i][j] = dp[i-1][j] + input;
            else if(j == (i-1)) dp[i][j] = dp[i-1][j-1] + input;
            else dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + input;
        }
    }

    int max = 0;

    for(int i = 0; i < N; i++){
        max = max < dp[N][i] ? dp[N][i] : max;
    }

    cout << max;

    return 0;
}
