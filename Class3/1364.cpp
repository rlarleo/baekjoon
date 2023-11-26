#include <iostream>
#include <vector>

using namespace std;

vector<long long> result;
int N;

void dp() {
    result.push_back(1);
    result.push_back(1);
    result.push_back(2);
    result.push_back(3);
    result.push_back(4);
    result.push_back(5);
    for(int i = 6; i <= N; i++){
        result.push_back(i + result[i-6]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    dp();
    cout << result[N];
    return 0;
}