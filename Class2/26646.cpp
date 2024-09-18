#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <stdlib.h>
#include <limits.h>
#include <cmath>

using namespace std;


int GetCost(pair<int, int> a, pair<int, int> b){
    return pow(a.first - b.first, 2) + pow(a.second - b.second, 2);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N;
    int maxHeight = 0;
    int width = 0;
    int result = 0;
    cin >> N;
    vector<pair<int, int>> nodes;
    for(int i = 0; i < N; i++){
        int input;
        cin >> input;
        width += input;
        if(maxHeight < input || i == N-1){
            nodes.push_back({width, input});
            if(i > 0){
                result += GetCost(nodes[i-1], nodes[i]);
            }
        }
        width += input;
    }

    cout << result;

    return 0;
}