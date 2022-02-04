#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main()
{
    int n, input;
    priority_queue<int, vector<int>, greater<int>> pq;
    int result = 0;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> input;
        pq.push(input);

    }

    for(int i = 0; i < n; i++){
        result = result + pq.top() * pq.size();
        pq.pop();
    }
    cout << result;
    return 0;
}
