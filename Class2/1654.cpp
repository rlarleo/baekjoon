#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    vector<int> vec;
    int N, M, num, cnt = 0;
    int max = 0;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> num;
        vec.push_back(num);
        max = max < num? num : max;
    }
    long long end = max;
    long long start = 1;
    long long mid;
    int result = 0;
    while(start <= end){
        mid = (start + end) / 2;
        cnt = 0;
        for(auto v : vec){
            cnt = cnt + v / mid;
        }
        if(cnt >= M){
            start = mid+1;
            if(result < mid) result = mid;
        }
        else{
            end = mid-1;
        }
    }
    cout << result;
    return 0;
}
