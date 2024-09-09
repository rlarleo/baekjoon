#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <stdlib.h>
#include <limits.h>

using namespace std;
vector<int> numbers;
vector<int> dp;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int T;
    int maxNum = 0;

    dp.push_back(2);
    dp.push_back(3);

    cin >> T;
    for(int t = 0; t < T; t++){
        int number;
        cin >> number;
        numbers.push_back(number);
        maxNum = maxNum > number ? maxNum : number;
    }

    for(int i = 2; i < maxNum; i++){
        dp.push_back(dp[i-2] + dp[i-1]);
    }


    for(int i = 0; i < numbers.size(); i++){
        cout << "Scenario " << i + 1 << ":" << '\n';
        cout << dp[numbers[i] - 1] << '\n' << '\n';
    }



    return 0;
}