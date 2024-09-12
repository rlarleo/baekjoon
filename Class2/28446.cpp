#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <stdlib.h>
#include <limits.h>

using namespace std;
vector<int> numbers;
vector<int> dp;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int N;
    map<int, int> balls;
    cin >> N;

    for(int i = 0; i < N; i++){
        int cmd, index, weight;
        cin >> cmd;
        if(cmd == 1){
            cin >> index >> weight;
            balls.insert({weight, index});
        }
        else{
            cin >> weight;
            cout << balls.find(weight)->second << '\n';
        }

    }


    return 0;
}