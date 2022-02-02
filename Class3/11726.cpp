#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    vector<int> fibo;

    cin >> n;

    fibo.push_back(1);
    fibo.push_back(2);

    for(int i = 2; i < n; i++){
        fibo.push_back((fibo[i-2] + fibo[i-1]) % 10007 );
    }

    cout << fibo[n-1];

    return 0;
}
