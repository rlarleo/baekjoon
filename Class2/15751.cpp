#include <iostream>
#include <string>
#include <stdlib.h>


using namespace std;


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    int a, b, x, y;

    cin >> a >> b >> x >> y;

    int start = min(a, b);
    int end = max(a, b);
    int t_start = min(x, y);
    int t_end = max(x, y);
    cout << min(end - start, abs(t_start - start) + abs(t_end - end));

    return 0;
}