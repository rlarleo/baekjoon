#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    long long result = N;

    M = N-M < M ? N-M : M;

    for(int i = 1; i < M; i++){
        cout << "up: " << N-i << endl;
        cout << "down: " << i << endl;
        result *= N-i;
        result /= i+1;
    }

    cout << result;

    return 0;
}
