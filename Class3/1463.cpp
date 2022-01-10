#include <iostream>
using namespace std;


void MakeOne(int* dp, int N){
    if(N <= 3) {
        cout << dp[N];
        return;
    }
    else {
        for(int i = 4; i <= N; i++){
            dp[i] = dp[i-1] + 1;
            if(i%2 == 0 && dp[i] > dp[i/2] + 1) dp[i] = dp[i/2] + 1;
            if(i%3 == 0 && dp[i] > dp[i/3] + 1) dp[i] = dp[i/3] + 1;
        }
    }
    cout << dp[N];

}

int main()
{
    int N;
    cin >> N;
    int* dp = new int[N+1];
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    MakeOne(dp, N);
    delete dp;
}
