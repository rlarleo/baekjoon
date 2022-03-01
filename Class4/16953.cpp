#include <iostream>

using namespace std;

long long A, B;
bool flag = true;

void dfs(long long a, int cnt){
    if(a > B) return;

    if(a == B) {
        flag = false;
        cout << cnt;
        return;
    }
    dfs(a*2, cnt+1);
    dfs(a*10+1, cnt+1);

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> A >> B;

    dfs(A, 1);

    if(flag) cout << -1;

    return 0;
}
