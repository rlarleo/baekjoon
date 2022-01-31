#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main()
{
    int N, num;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> result;
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> num;
        if(num == 0){
            if(pq.size() == 0){
                result.push_back(0);
            }
            else{
                result.push_back(pq.top().first * pq.top().second);
                pq.pop();
            }
        }
        else if(num < 0){
            pq.push(pair<int, int>(num*-1, -1));
        }
        else {
            pq.push(pair<int, int>(num, 1));
        }
    }

    for(auto v : result){
        cout << v << endl;
    }
    return 0;
}
