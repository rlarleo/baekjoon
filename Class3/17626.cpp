#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int x;
    cin >> x;
    int* dp = new int[x+1];
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= x; i++){
        dp[i] = dp[i-1] + 1;
        for(int j = 2; j*j <= i; j++){
            dp[i] = dp[i] < dp[i - j*j] + 1 ? dp[i] : dp[i - j*j] + 1;
        }
    }
    for(int i = 0; i < x; i++){
        //cout << dp[i] << " ";
    }
    cout << dp[x];
    delete dp;
    return 0;
}
