#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int findMin(int dp1, int dp2, int color){
    int min = dp1 > dp2? dp2 : dp1;
    return min + color;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int N;
        cin >> N;
        int* U = new int[N];
        int* D = new int[N];
        int* dp[3];
        dp[0] = new int[N];
        dp[1] = new int[N];
        dp[2] = new int[N];

        for(int i = 0; i < N; i++){
            cin >> U[i];
        }
        for(int i = 0; i < N; i++){
            cin >> D[i];
        }
        dp[0][0] = U[0];
        dp[1][0] = D[0];
        dp[2][0] = D[0] > U[0] ? D[0] : U[0];

        for(int i = 1; i < N; i++){
            dp[0][i] = dp[0][i] +
        }

        delete U;
        delete D;
        delete dp[0];
        delete dp[1];
        delete dp[2];
    }



    return 0;
}
