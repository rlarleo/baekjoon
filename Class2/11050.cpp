#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int N, K;
    cin >> N >> K;
    int result = 1;
    for(int i = 0; i < K; i++){
        result = result * (N-i) / (i+1);
    }
    cout << result;

    return 0;
}
