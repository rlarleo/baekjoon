#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int K, num;
    stack<int> s;
    cin >> K;
    for(int i = 0; i < K; i++){
        cin >> num;
        if(num == 0) s.pop();
        else s.push(num);
    }
    int result = 0;
    while(s.size() > 0){
        result = result + s.top();
        s.pop();
    }
    cout << result;
}
