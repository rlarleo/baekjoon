#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int N; // 돌의 개수
    cin >> N;

    if (N % 2 == 1)
    {
        cout << "SK";
    }

    else
    {
        cout << "CY";
    }

    return 0;
}