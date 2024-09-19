#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <stdlib.h>
#include <limits.h>
#include <cmath>
#include <queue>

using namespace std;


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N;
    int dasom;
    int result = 0;
    cin >> N;
    cin >> dasom;
    priority_queue<int> pq;
    for(int i = 1; i < N; i++){
        int score;
        cin >> score;
        if(score >= dasom) pq.push(score);
    }

    while(!pq.empty() && pq.top() >= dasom){
        int t = pq.top(); pq.pop();
        t--; result++; dasom++;
        pq.push(t);
    }
    cout << result;

    return 0;
}