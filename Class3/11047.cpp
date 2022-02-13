#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N, M, coin;
    cin >> N >> M;
    int* money = new int[N];
    for(int i = N-1; i >= 0; i--){
        cin >> coin;
        money[i] = coin;
    }

    int cnt = 0;
    while(M != 0){
        for(int i = 0; i < N; i++){
            if(M >= money[i]){
                M = M - money[i];
                cnt++;
                i--;
            }
        }
    }
    cout << cnt;

    delete money;
    return 0;
}
