#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <tuple>
using namespace std;
vector<int> tree[50];
bool visited[50];
int N, delNode, result;
int main()
{
    ios_base::sync_with_stdio(0);
    int N;
    int max = 0;
    int maxInput = 0;
    cin >> N;
    int arr[100000] = {
        0,
    };
    for (int i = 0; i < N; i++)
    {
        int input;
        cin >> input;
        arr[input] += 1;
        max = max < arr[input] ? arr[input] : max;
        maxInput = maxInput < input ? input : maxInput;
    }
    if ((max * 2) > ((N + 1) / 2) * 2)
        cout << "NO";
    else
        cout << "YES";
    return 0;
}