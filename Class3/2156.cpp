#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int dp[10000];
    int wine[10000];
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int input;
        cin >> input;
        wine[i] = input;
    }

    dp[0] = wine[0];
    dp[1] = wine[0] + wine[1];
    dp[2] = max(wine[0] + wine[1], max(wine[1] + wine[2], wine[0] + wine[2]));
    for(int i = 3; i < N; i++){
        dp[i] = max(dp[i-3] + wine[i-1] + wine[i], max(dp[i-2] + wine[i], dp[i-1]));
    }

    cout << dp[N-1];
    
    return 0;
}
