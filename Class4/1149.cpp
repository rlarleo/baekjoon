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

    int N;
    cin >> N;
    int* R = new int[N];
    int* G = new int[N];
    int* B = new int[N];
    int dp[3][1000];

    for(int i = 0; i < N; i++){
        cin >> R[i] >> G[i] >> B[i];
    }
    dp[0][0] = R[0];
    dp[1][0] = G[0];
    dp[2][0] = B[0];

    for(int i = 1; i < N; i++){
        dp[0][i] = findMin(dp[1][i-1], dp[2][i-1], R[i]);
        dp[1][i] = findMin(dp[0][i-1], dp[2][i-1], G[i]);
        dp[2][i] = findMin(dp[0][i-1], dp[1][i-1], B[i]);
    }

    int min = INT_MAX;
    for(int i = 0; i < 3; i++){
        min = min > dp[i][N-1] ? dp[i][N-1] : min;
    }
    cout << min;

    delete R;
    delete G;
    delete B;

    return 0;
}
