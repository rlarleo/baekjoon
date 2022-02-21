#include <iostream>
#include <set>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int T, x, y, N, M;
    cin >> T;


    while(T--){
        cin >> x >> y >> N >> M;
        int lcm = x*y / gcd(x, y);
        int currentX, currentY;
        int i;
        for(i = 0; i < lcm; i++){
            currentX = i % x + 1;
            currentY = i % y + 1;
            if(currentX == N && currentY == M){
                cout << i+1 << '\n';
                break;
            }
        }
        if(i == lcm) cout << -1 << '\n';
    }
    return 0;
}
