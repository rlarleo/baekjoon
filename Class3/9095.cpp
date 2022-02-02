#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> dp;
    dp.push_back(0);
    dp.push_back(1);
    dp.push_back(2);
    dp.push_back(4);
    int n, testCase;
    cin >> n;

    for(int i = 4; i <= 11; i++){
        dp.push_back(dp[i-1] + dp[i-2] + dp[i-3]);
    }

    for(int i = 0; i < n; i++){
        cin >> testCase;
        cout << dp[testCase] << endl;
    }

    return 0;
}
