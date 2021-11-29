#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    cin >> n;
    int result = 0;
    for(int i = 1; i <= n+1; i++){
        if(i % 2 == 1) result = (result * 2 + 1) % 10007;
        else result = (result * 2 - 1) % 10007;
    }
    cout << result;

    return 0;
}
