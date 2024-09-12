#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <stdlib.h>
#include <limits.h>

using namespace std;
vector<int> numbers;
int dp[4001][4001] = {0, };

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    string A, B;
    int result = 0;

    cin >> A >> B;

    for(int i = 1; i <= A.size(); i++){
        for(int j = 1; j <= B.size(); j++){
            if(B[j-1] ==  A[i-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                result = result > dp[i][j] ? result : dp[i][j];
            }
        }
    }

    cout << result;


    return 0;
}