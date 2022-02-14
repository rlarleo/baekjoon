#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    int N, input;
    int result = 0;
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> input;
        pq1.push(input);
    }

    for(int i = 0; i < N; i++){
        cin >> input;
        pq2.push(input);
    }

    for(int i = 0; i < N; i++){
        result += pq1.top() * pq2.top();
        pq1.pop();
        pq2.pop();
    }

    cout << result;



    return 0;
}
