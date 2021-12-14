#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    queue<int> myQue;
    vector<int> result;
    int N, K;
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        myQue.push(i);
    }
    while(myQue.size() != 0){
        for(int i = 0; i < K - 1; i++){
            int temp = myQue.front();
            myQue.pop();
            myQue.push(temp);
        }
        result.push_back(myQue.front());
        myQue.pop();
    }
    cout << '<';
    for(auto r : result){
        if(r != *(result.end()-1)) cout << r << ", ";
        else cout << r;
    }
    cout << '>';


    return 0;
}
