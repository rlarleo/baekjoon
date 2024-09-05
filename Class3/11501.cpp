#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int N;
        long long result = 0;
        cin >> N;
        vector<int> values;
        for (int i = 0; i < N; i++)
        {
            int input;
            cin >> input;
            values.push_back(input);
        }

        int maxValue = -1;
        for (int i = N - 1; i >= 0; i--)
        {
            maxValue = max(maxValue, values[i]);
            result += maxValue - values[i];
        }

        cout << result << '\n';
    }
    return 0;
}
