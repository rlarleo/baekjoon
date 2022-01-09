#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> trees;
long long N, M, tree, result = 0;
long long maxTree = 0;
long long test;
long long min_diff = 1000000001;

void myFind(){
    long long left = 0;
    long long right = maxTree;
    long long mid;
    while(left <= right){
        mid = (left + right) / 2;
        result = 0;
        for(auto t : trees){
            if(t-mid > 0) result += t-mid;
        }
        if(result > M){
            if(min_diff > result - M){
                min_diff = result - M;
                test = mid;
            }
            left = mid + 1;
        }
        else if (result < M) {
            right = mid - 1;
        }
        else{
            cout << mid;
            return;
        }
    }
    cout << test;

}


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> tree;
        trees.push_back(tree);
        maxTree = tree > maxTree? tree : maxTree;
    }

    myFind();

    return 0;
}
