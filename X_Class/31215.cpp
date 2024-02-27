#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        int N;
        cin >> N;
        if (N <= 2)
            cout << 1 << endl;
        else
            cout << 3 << endl;
    }

    return 0;
}