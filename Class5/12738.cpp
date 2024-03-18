#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int N, input;
    vector<int> vec;
    vector<int> result;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        vec.push_back(input);
    }
    result.push_back(vec[0]);

    for (int i = 1; i < N; i++)
    {
        if (result.back() < vec[i])
        {
            result.push_back(vec[i]);
        }
        else
        {
            int index = lower_bound(result.begin(), result.end(), vec[i]) - result.begin();
            result[index] = vec[i];
        }
    }
    cout << result.size();
    return 0;
}
