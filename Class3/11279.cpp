#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> pq;
vector<int> result;

void output(){
    if(pq.empty()) result.push_back(0);
    else{
        result.push_back(pq.top());
        pq.pop();
    }
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        if(num == 0) output();
        else pq.push(num);
    }

    for(auto v : result){
        cout << v << '\n';
    }
	return 0;
}
