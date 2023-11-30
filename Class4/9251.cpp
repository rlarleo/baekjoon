#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    string A, B;
    int dp[1001][1001] = {0, };
    cin >> A >> B;

    for(int i = 1 ; i <= A.length(); i++){
        for(int j = 1; j <= B.length(); j++){
            if(A[i-1] == B[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[A.length()][B.length()];

    
    return 0;
}