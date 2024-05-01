#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int N;
    int result = 0;
    cin >> N; 

    for(int i = 0; i < N; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == -1) continue;
        else if(b == -1 && c != -1) continue;
        else if((b != -1 && b < a) || (c != -1 && c < b) || (c != -1 && c < a)) continue;
        else
            result++;
    }
    cout << result;
}
