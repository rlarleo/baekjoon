#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N, M, k, j;
    cin >> N >> M;

    vector<int> vec;
    int input;
    vec.push_back(0);
    int sum = 0;

    for(int i = 0; i < N; i++){
        cin >> input;
        sum = sum + input;
        vec.push_back(sum);
    }

    for(int i = 0; i < M; i++){
        cin >> k >> j;
        cout << vec[j] - vec[k-1] << '\n';
    }

    return 0;
}
