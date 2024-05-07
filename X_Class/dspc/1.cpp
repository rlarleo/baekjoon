#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    int a, b, c;
    int result = 0;
    cin >> a >> b >> c;

    if(a == 0){
        result = c * c - b;
    } else if(b == 0){
        result = c * c - a;
    } else {
        result = sqrt(a + b);
    }
    cout << result;
    
}
